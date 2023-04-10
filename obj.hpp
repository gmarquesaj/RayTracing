#pragma once
#include "vec3.hpp"
#include "ray.hpp"
#include "material.hpp"
#define t_min 0.0000001f
#define t_max 1000000.0f
struct OBJ
{
	vec3 pos;
	float raio;
	CONTATO colide(RAY *r);
	MAT *material;
	OBJ(vec3 pos,float raio, MAT *material);
};
