#pragma once
#include "vec3.hpp"
#include "ray.hpp"
#include "material.hpp"
struct OBJ
{
	vec3 pos;
	float raio;
	CONTATO colide(RAY *r);
	MAT *material;
	OBJ(vec3 pos,float raio, MAT *material);
};
