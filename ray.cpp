#include "ray.hpp"
#include "obj.hpp"
#include "aleatorio.hpp"
bool CONTATO::reflexo(){

	vec3 ndir(0,0,0);
	bool saltar = true;
	vec3 dirEspec = raio->dir - 2.0f * dot(raio->dir, normal)  * normal;
	vec3 dirDif =  (normal+ randomFloatVec3MinMax(-1,1)).normalizado();
	switch(obj->material->tipo)
	{
		case METALICO:
			ndir = dirEspec;
			especular =0;
			break;
		case DIFUSO:
			especular = float(obj->material->especular>randomFloatMinMax(0,1));
			ndir = lerp3(dirDif,dirEspec,especular*obj->material->rugosidade);
			break;
		case EMISSOR:
			especular =0;
			saltar = false;
			break;
	}


	vec3 nori = pos+(normal * 0.001f);
	*raio = RAY(nori,ndir);
	return saltar;
};
CONTATO::CONTATO(bool toque,vec3 pos,vec3 normal):toque(toque),pos(pos),normal(normal)
{};
vec3 RAY::Em(float distancia){

	vec3 res = dir*distancia;
	return ori+res;
};

RAY::RAY(vec3 ori,vec3 dir):ori(ori),dir(dir.normalizado())
{



};
