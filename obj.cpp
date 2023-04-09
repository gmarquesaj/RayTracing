#include "obj.hpp"
CONTATO OBJ::colide(RAY *r){
	CONTATO res (false,{0,0,0},{0,0,0});
	
	vec3 oc = r->ori-pos;
	float a = r->dir.distancia2();
	float mb = dot(oc,r->dir);
	float c =  oc.distancia2()-raio*raio;
	float d=mb*mb-a*c;
	if(d<0)
		return res;
	res.dis =  (-mb-sqrt(d))/a;
	res.toque =true;
	res.obj = NULL;
	return res;
};

OBJ::OBJ(vec3 pos,float raio, MAT *material):pos(pos),raio(raio),material(material)

{
};
