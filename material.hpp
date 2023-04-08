#pragma once
#include "vec3.hpp"
struct MAT
{
	vec3 albedo;
	float rugosidade;
	int metalico;
	MAT(vec3 albedo,float rugosidade, int metalico):albedo(albedo),metalico(metalico)
	{

	}
};
