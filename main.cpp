#include "ppm.hpp"
#include "vec3.hpp"
#include "ray.hpp"
#include "obj.hpp"
#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cmath>
#include"aleatorio.hpp"
using std::cout;
using std::vector;
using std::string;
using std::to_string;
using std::ifstream;
using std::ofstream;
void arcoIris(PPM *img,int x,int y, int pos, float u,float v)
{
	int r = u*250;
	int g = v * 250;
	int b = 255-r;
	img->setPxl(x,y,r,g,b);

};

vector<MAT> materiais;
vector<OBJ> objs;
CONTATO objMaisProximo(RAY *raio)
{
	CONTATO res(false,vec3(t_max,t_max,t_max),vec3(t_max,t_max,t_max));
	for(int i=0;i<objs.size();i++)
	{
		OBJ *obj = &objs[i];
		if(obj==NULL)
		{
			cout << "Ponteiro nulo\n";
		}

		CONTATO	temp = obj->colide(raio);
		if(temp.toque and temp.dis<res.dis)
		{
			res=temp;
			res.obj = obj;
		}
	}
	res.raio = raio;
	return res;
}
//funciona como um Mapa HDRI provisorio ate que um sistem
//de texturas seja implementado
vec3 AMBIENTE(float u, float v) {
	vec3 cor1 = vec3(.4f, 1.0f, 1.0f);
	vec3 cor2 = vec3(1.0f, 1.0f, 1.0f);
	return  lerp3(cor1, cor2, .5 - v)*0.1;

}
void clamp1(vec3 &a)
{
	a.x = a.x>1.0f?1.0f:a.x<0.0f?0.0f:sqrt(a.x);
	a.y = a.y>1.0f?1.0f:a.y<0.0f?0.0f:sqrt(a.y);
	a.z = a.z>1.0f?1.0f:a.z<0.0f?0.0f:sqrt(a.z);

};



vec3 shade(CONTATO &c)
{
	//float intensidade = dot(c.normal,c.raio->dir)*2;
	//return  randomFloatVec3MinMax(0,1);
	return lerp3(c.obj->material->albedo,c.obj->material->especColor,c.obj->material->especular);
	//vec3 UV = c.obj->normalToUV(c.normal); 
	//return c.obj->corEm(UV.x,UV.y);

}
void rt(PPM *img,int x,int y, int pos, float u,float v)
{
#define saltos 10
#define amostras 100
	u=u*2-1;
	v=v*2-1;
	vec3 corFinal(0,0,0);
	int amostra =0;
	for(;amostra <amostras;amostra++)
	{
		RAY raio(vec3(0,0,1),vec3(u,v,-1));
		int i=0;

		CONTATO info = objMaisProximo(&raio);
		vec3 cor = AMBIENTE(u,v);
		if(info.toque)
			cor = shade(info);

		while(info.toque && i<saltos)
		{
			cor = cor* shade(info);
			if(!info.reflexo())
				break;
			info = objMaisProximo(&raio);
			i++;
			
		}
		if(info.toque== false)
			cor = cor * AMBIENTE(u,v);
		else if(i==saltos) cor=vec3(0,0,0);
		clamp1(cor);
		corFinal = corFinal + cor;
	}
	corFinal = corFinal/amostra;
	img->setPxl(x,y,corFinal.x*250,corFinal.y*250,corFinal.z*250);

};

int main()
{

	MAT basico=MAT(vec3(0.9),0.5f,0.15,DIFUSO);
	MAT tomate=MAT(vec3(0.9,0.2,0.1),0.51f,0.27f,DIFUSO);
	MAT metal=MAT(vec3(0.95),0.5f,0.5,METALICO);
	MAT luz=MAT(vec3(2),0.5f,0.5,EMISSOR);
	objs.emplace_back(vec3(0,0,-1),0.5f,&basico);
	objs.emplace_back(vec3(-1.5,0,-1),0.5f,&metal);
	objs.emplace_back(vec3(1.5,0,-1),0.5f,&tomate);
	const float chao = 50;
	objs.emplace_back(vec3(0,chao+0.5,-1),chao,&basico);
	objs.emplace_back(vec3(0,-1.5,20),15.15f,&luz);
	PPM img(550,550);
	img.paraCadaPX(&rt);
	img.save();

	return 0;
};
