#include "ppm.hpp"
#include "vec3.hpp"
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
int main()
{
PPM img(250,250);
img.paraCadaPX(&arcoIris);
img.save();

return 0;
};
