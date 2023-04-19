#pragma once
#include "obj.hpp"
#include "ray.hpp"
class caixa{
	public:
		vec3 minimo,maximo;
		void print();
		int indEsq,indDir;
		bool toque(RAY *r);
		caixa(vec3 minimo, vec3 maximo,int indEsq, int indDir);
};

