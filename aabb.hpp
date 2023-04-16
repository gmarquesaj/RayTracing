#pragma once
#include "obj.hpp"

class caixa{
	public:
		vec3 minimo,maximo;
		int indEsq,indDir;
		caixa(vec3 minimo, vec3 maximo,int indEsq, int indDir);
};

