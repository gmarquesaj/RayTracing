#include "ppm.hpp"

void PPM::paraCadaPX(void( *func)(PPM*,int, int,int,float,float)){

	for(int y=0;y<h;y++)
	{
		float v = (float)y/(float)h;
		for(int x=0;x<w;x++)
		{
			int pos = (3*w*y)+(3*x);
			float u = (float)x/(float)w;
			func(this,x,y,pos,u,v);
		}
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
void PPM::save()
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
