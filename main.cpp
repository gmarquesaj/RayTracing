#include "ppm.hpp"
#include "vec3.hpp"
#include "ray.hpp"
#include "obj.hpp"
#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cmath>
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

OBJ *obj;

void rt(PPM *img,int x,int y, int pos, float u,float v)
{
	int r = 0;
	int g = 10;
	int b = 200;

	u=u*2-1;
	v=v*2-1;

	RAY raio((vec3){0,0,0},(vec3){u,v,-5});
	if(obj->colide(&raio).toque)
	{
		r=250;
		g=100;
		b=200;
	}

	img->setPxl(x,y,r,g,b);

};

int main()
{
	
MAT basico=MAT((vec3){1.0f,0.2f,0.2f},0.5f,0);
OBJ o({0,0,-1},0.15f,&basico);
obj = &o;	
PPM img(250,250);
	img.paraCadaPX(&rt);
	img.save();

	return 0;
};
