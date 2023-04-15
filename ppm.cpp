#include "ppm.hpp"

void PPM::paraCadaPX(void( *func)(PPM*,int, int,int,float,float)){

	vector<thread> th;
	int nth = 16;
	int p = h/nth;
	for(int i=0;i<nth;i++)
	{
		th.emplace_back([=](){


				int ini = i*p;
				int fim = i==nth-1?h:ini+p;
				printf("ini = %d fim = %d\n",ini,fim);
				for(int y=ini;y<fim;y++)
				{
				float v = (float)y/(float)h;

				for(int x=0;x<w;x++)
				{
				int pos = (3*w*y)+(3*x);
				float u = (float)x/(float)w;
				func(this,x,y,pos,u,v);
				}
				}
				printf("fim da thread %d\n",i+1);
				});
	}
	for(int i=0;i<nth;i++)
	{
		if(th[i].joinable())
			th[i].join();

	}
};
PPM::PPM(int w,int h):w(w),h(h)
{

	pxl.resize(w*h*3,150);
};


void PPM::setPxl(int x,int y,int r,int g,int b)

{
	int pos = (3*w*y)+(3*x);
	pxl[pos]=r;
	pxl[pos+1]=g;
	pxl[pos+2]=b;

};
void PPM:: setPxl(int x,int y,vec3 cor){

	int pos = (3*w*y)+(3*x);
	pxl[pos]=cor.x;
	pxl[pos+1]=cor.y;
	pxl[pos+2]=cor.z;
};
void PPM::save(string caminho)
{
	FILE *f = fopen(caminho.c_str(),"wb");
	fprintf(f,"P6\n%d %d\n%d\n",w,h,255);
	fwrite(pxl.data(),w*h*sizeof(unsigned char)*3,1,f);
	fclose(f);
}

void PPM::saveP3()
{
	FILE *f = fopen("img.ppm","w");
	fprintf(f,"P3\n%d %d\n%d\n",w,h,256);
	for(int y=0;y<h;y++)
	{
		for(int x=0;x<w;x++)
		{
			int pos = (3*w*y)+(3*x);
			fprintf(f,"%d %d %d\n",pxl[pos],pxl[pos+1],pxl[pos+2]);	
		}
	}
	fclose(f);
}
