#include "aabb.hpp"

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

void caixa:: print(){
	printf("[(%3.2f,%2.2f,%f),(%3.2f,%3.2f,%3.2f)]\n",minimo.x,minimo.y,minimo.z,maximo.x,maximo.y,maximo.z);
};


bool caixa::toque(RAY *r){
	float tmin = t_min;
	float tmax = t_max;

	for (int a = 0; a < 3; a++) {
		float t0 = fmin((minimo[a] - r->ori[a]) / r->dir[a],
				(maximo[a] - r->ori[a]) / r->dir[a]);
		float t1 = fmax((minimo[a] - r->ori[a]) / r->dir[a],
				(maximo[a] - r->ori[a]) / r->dir[a]);
		tmin = fmax(t0, tmin);
		tmax = fmin(t1, tmax);
		if (tmax <= tmin)
			return false;
	}
	return true;



	/*
	   for (int a = 0; a < 3; a++) {
	   float invD = 1.0f / r->dir[a];
	   float t0 = (minimo[a] - r->ori[a]) * invD;
	   float t1 = (maximo[a] - r->ori[a]) * invD;
	   if (invD < 0.0f)
	   std::swap(t0, t1);
	   tmin = t0 > tmin ? t0 : tmin;
	   tmax = t1 < tmax ? t1 : tmax;
	   if (tmax <= tmin)
	   return false;
	   }
	   return true;

*/
};


caixa::caixa(vec3 minimo, vec3 maximo,int indEsq, int indDir):
	minimo(minimo),maximo(maximo),indEsq(indEsq),indDir(indDir){

	};
