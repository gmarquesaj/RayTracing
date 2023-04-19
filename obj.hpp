#pragma once
#include "vec3.hpp"
#include "ray.hpp"
#include "material.hpp"
#define t_min 0.0000001f
#define t_max 1000000.0f
class OBJ
{
	public:
		vec3 pos;
		float raio;
		CONTATO colide(RAY *r);
		MAT *material;
		vec3 minCaixa;
		vec3 maxCaixa;
		vec3 corEm(float u, float v);
		vec3 normalToUV(vec3 normal);
		OBJ(vec3 pos,float raio, MAT *material);

};
