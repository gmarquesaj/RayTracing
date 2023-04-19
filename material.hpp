#pragma once
#include "vec3.hpp"
enum tipoMat
{
	DIFUSO,METALICO,EMISSOR

};
class MAT
{
	public:
		vec3 albedo;
		vec3 especColor;
		float rugosidade;
		float especular;
		int tipo;
		MAT(vec3 albedo,float rugosidade,float especular, int tipo):rugosidade(rugosidade),especColor(vec3(1.0)),albedo(albedo),tipo(tipo),especular(especular)
	{

	}
};
