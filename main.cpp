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
#include "arvore.hpp"
using std::cout;
using std::vector;
using std::string;
using std::to_string;
using std::ifstream;
using std::ofstream;
arvore arv;
//vector<OBJ> objs;
CONTATO objMaisProximo(RAY *raio)
{
	CONTATO res(false,vec3(t_max,t_max,t_max),vec3(t_max,t_max,t_max));
	for(int i=0;i<	arv.objs.size();i++)
	{
		OBJ *obj = &	arv.objs[i];
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


CONTATO objMaisProximo2(RAY *raio)
{
	CONTATO res(false,vec3(t_max,t_max,t_max),vec3(t_max,t_max,t_max));
	vector<int> testar;
	testar.reserve(100);
	testar.push_back(0);
	const int pOBJ = arv.nosNaUltimaCamada()*2-1;
	while(testar.size()>0)
	{
		const int c = testar[testar.size()-1];
		testar.pop_back();
		if(c==-1)
			continue;
		if(c>=pOBJ)
		{

			int indice = c-arv.caixas.size();
			if(indice<0 or indice>=arv.indices.size())
			{
				printf("Indice ruim %d\n",indice);

			}
			int id = arv.indices[indice];
			if(id==-1)
				continue;
			else if(id>= arv.objs.size())
			{
				printf("ID RUIM %d, com C = %d e OBJS = %ld\n",id,c,arv.objs.size());

				continue;
			}
			OBJ *obj = &	arv.objs[id];
			if(obj==NULL)
			{
				cout << "Ponteiro nulo\n";
			}
			//cout << "testando raio com o obj "<<c<<"\n";
			CONTATO	temp = obj->colide(raio);

			if(temp.toque and temp.dis<res.dis)
			{
				res=temp;
				res.obj = obj;
			}
		}
		else {
			if(c<0 or c>=arv.caixas.size())
			{
				printf("tentou acessar caixa inexistente %d\n",c);
			}
			if(arv.caixas[c].toque(raio))
			{
				//	printf("Raio TOCOU na caixa %d ",c);
				//arv.caixas[c].print();
				int iD = (arv.caixas[c].indDir);
				int iE = (arv.caixas[c].indEsq);

				testar.push_back(iE);
				testar.push_back(iD);

			}
		};

	}


	res.raio = raio;
	return res;
}

float clamp(float v)
{
	//	return v>1.0f?1.0f:v>=0?v:v<-1.0f?1.0f:-v;
	return v>=1.0f?1.0f:v<=0.0f?0.0f:v;
}
//funciona como um Mapa HDRI provisorio ate que um sistem
//de texturas seja implementado
vec3 AMBIENTE(float u, float v) {
	//return vec3(0.5);
	vec3 cor1(0.7f, 0.7f, 1.0f);
	vec3 cor2(1.0f, .70f, .40f);
	return  lerp3(cor2, cor1, clamp(.5-v));


}



vec3 shade(CONTATO &c)
{
	return lerp3(c.obj->material->albedo,c.obj->material->especColor,c.obj->material->especular);
	//vec3 UV = c.obj->normalToUV(c.normal); 
	//vec3 cor = c.obj->corEm(UV.x,UV.y);

}
void rt(PPM *img,int x,int y, int pos, float u,float v)
{
#define saltos 20
#define amostras 300
	u=u-0.5;
	v=v-0.5;
	vec3 corFinal(0,0,0);
	int amostra =0;
	for(;amostra <amostras;amostra++)
	{
		RAY raio(vec3(0,0,2.5),vec3(u,v,-1));
		int i=0;

		CONTATO info = objMaisProximo2(&raio);
		vec3 cor = AMBIENTE(u,v);
		if(info.toque)
			cor = shade(info);

		while(info.toque && i<saltos)
		{
			cor = cor* shade(info);
			if(!info.reflexo())
				break;
			info = objMaisProximo2(&raio);
			i++;

		}
		if(info.toque== false)
			cor = cor * AMBIENTE(u,v);
		else if(i==saltos) cor=vec3(0,0,0);
		//	cor.clamp1();
		corFinal = corFinal + cor;
	}
	corFinal = corFinal/amostra;
	corFinal.clamp1();
	img->setPxl(x,y,corFinal.x*250,corFinal.y*250,corFinal.z*250);

};

int main()
{

	cout<<"\n\n";
	vector<MAT> OSmateriais;
	const float chao = 5000;
	const int d = 50;
	const int t =2;
	MAT matChao=MAT(vec3(0.5),0.5f,0.85f,DIFUSO);
	MAT matLuz =MAT(vec3(1.0),0.5f,0.5f,EMISSOR);
	//chao
	arv.objs.emplace_back(vec3(0,d+t,0),d,&matChao);
	//teto
	arv.objs.emplace_back(vec3(0,-d-t,0),d,&matChao);
	//laterais
	arv.objs.emplace_back(vec3(d+t,0,0),d,&matChao);
	arv.objs.emplace_back(vec3(-d-t,0,0),d,&matChao);
	//fundo
	arv.objs.emplace_back(vec3(0,0,-d-t),d,&matChao);
	int nx = 10;
	int ny = 10;
	float s =0.3;
	OSmateriais.reserve(nx*ny*2);
	for(int y=0;y<ny;y++)
		for(int x=0;x<nx;x++)
		{
			float e = 1.0f-((float)x/float(nx));
			float r = 1.0f-((float)y/float(ny));
			OSmateriais.push_back(MAT(vec3(0.8,0.2,0.2),r,e,DIFUSO));
			arv.objs.emplace_back(vec3(x*s-1.3,y*-s+1.5,-1-.2),s*0.5,&OSmateriais[x+y*nx]);	
		}
	PPM img(1550,1550);
	cout <<"Calculando Arvore hierarquica de delimitaçao volumetrica\n";
	arv.popularArvore();
	cout<<"renderizando\n";
	img.paraCadaPX(&rt);
	cout<<"salvando arquivo ppm\n";
	img.save();
	cout<<"concluido\n";
	return 0;
};
