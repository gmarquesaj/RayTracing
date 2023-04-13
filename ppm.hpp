#pragma once
#include<iostream>
#include <thread>
#include<vector>
using std::thread;
using std::vector;
struct PPM
{
	int w,h;
	vector<unsigned char> pxl;
	PPM(int w,int h);
	void save();
	void setPxl(int x,int y,int r,int g,int b);
	void paraCadaPX(void( *func)(PPM *,int, int,int, float, float));
	//setPxl(int x,int y,vec3 cor)
};
