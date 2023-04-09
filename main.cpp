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
#define mini 0.0001f
#define maxi 10000.0f
	CONTATO res(false,vec3(maxi,maxi,maxi),vec3(maxi,maxi,maxi));
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
	return res;
}
void rt(PPM *img,int x,int y, int pos, float u,float v)
{
	int r = 0;
	int g = 0;
	int b = 0;
	#define saltos 10
	vector<vec3>cores(saltos,vec3(0,0,0));
	u=u*2-1;
	v=v*2-1;

	RAY raio(vec3(0,0,-2),vec3(u,v,-5));
	int i=0;
	for(i=0;i<saltos;i++)

	{
		CONTATO info = objMaisProximo(&raio);
		if(info.toque)
		{
			MAT* material= info.obj->material;
			r=material->albedo.x*250;
			g=material->albedo.y*250;
			b=material->albedo.z*250;
			cores[i]=vec3(r,g,b);
		}
	}
	img->setPxl(x,y,r,g,b);

};

int main()
{

	MAT basico=MAT((vec3){1.0f,0.2f,0.2f},0.5f,0);
	MAT basico2=MAT((vec3){0.0f,1.0f,0.2f},0.5f,0);
	objs.emplace_back(vec3(0,0,-1),0.1f,&basico);
	objs.emplace_back(vec3(0.1,0,-1),0.1f,&basico2);
	PPM img(250,250);
	img.paraCadaPX(&rt);
	img.save();

	return 0;
};
