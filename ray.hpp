#pragma once
#include "vec3.hpp"

struct OBJ;
struct CONTATO{
	bool toque;
	float dis;
	vec3 pos,normal;
	OBJ *obj;
	CONTATO(bool toque,vec3 pos,vec3 normal);

};

struct RAY{
	vec3 ori,dir;
	RAY(vec3 ori,vec3 dir);
	vec3 Em(float distancia);
};



