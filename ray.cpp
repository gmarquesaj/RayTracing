#include "ray.hpp"

void CONTATO::reflexo(RAY *raio){

};
CONTATO::CONTATO(bool toque,vec3 pos,vec3 normal):toque(toque),pos(pos),normal(normal)
{};
vec3 RAY::Em(float distancia){

	vec3 res = dir*distancia;
	return ori+res;
};

RAY::RAY(vec3 ori,vec3 dir):ori(ori),dir(dir)
{



};
