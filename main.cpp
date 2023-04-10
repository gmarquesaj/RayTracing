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
vec3 AMBIENTE(float u, float v) {
	vec3 cor1 = vec3(.4f, 1.0f, 1.0f);
	vec3 cor2 = vec3(1.0f, 1.0f, 1.0f);
	return  lerp3(cor1, cor2, .5 - v);

}
void clamp1(vec3 &a)
{
	a.x = a.x>1.0f?1.0f:a.x<0.0f?0.0f:a.x;
	a.y = a.y>1.0f?1.0f:a.y<0.0f?0.0f:a.y;
	a.z = a.z>1.0f?1.0f:a.z<0.0f?0.0f:a.z;

};
vec3 shade(CONTATO &c)
{
	//return  randomFloatVec3MinMax(0,1);
	return c.obj->material->albedo;

}
void rt(PPM *img,int x,int y, int pos, float u,float v)
{
#define saltos 50
	u=u*2-1;
	v=v*2-1;

	RAY raio(vec3(0,0,1),vec3(u,v,-1));
	int i=0;

	CONTATO info = objMaisProximo(&raio);
	vec3 cor = AMBIENTE(u,v);
	if(info.toque)
	 cor = shade(info);
	
	while(info.toque && i<saltos)
	{
		cor = cor* shade(info);
		info.reflexo();
		info = objMaisProximo(&raio);
		i++;
	}
	if(info.toque== false)
		cor = cor * AMBIENTE(u,v);
	else if(i==saltos) cor=vec3(0,0,0);
	clamp1(cor);
	img->setPxl(x,y,cor.x*250,cor.y*250,cor.z*250);

};

int main()
{

	MAT basico=MAT((vec3){0.80f,0.82f,0.82f},0.5f,0);
	MAT basico2=MAT((vec3){0.0f,1.0f,0.2f},0.5f,0);
	MAT basico3=MAT((vec3){20.0f,20.10f,20.5f},0.5f,0);
	objs.emplace_back(vec3(0,0,-1),0.5f,&basico);
	const float chao = 10;
	objs.emplace_back(vec3(0,chao+0.6,-1),chao,&basico);
	objs.emplace_back(vec3(-1.5,0,-1),0.5f,&basico3);
	PPM img(550,550);
	img.paraCadaPX(&rt);
	img.save();

	return 0;
};
