#pragma once
#include "vec3.hpp"

struct OBJ;

struct RAY{
	vec3 ori,dir;
	RAY(vec3 ori,vec3 dir);
	vec3 Em(float distancia);
};


struct CONTATO{
	bool toque;
	float especular = 0.0;
	float dis=10000;
	vec3 pos,normal;
	RAY *raio;
	OBJ *obj;
	CONTATO(bool toque,vec3 pos,vec3 normal);
	bool	reflexo();
};

