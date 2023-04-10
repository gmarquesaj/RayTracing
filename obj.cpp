#include "obj.hpp"
CONTATO OBJ::colide(RAY *r){
	CONTATO res (false,{0,0,0},{0,0,0});

	vec3 oc = r->ori-pos;
	float a = r->dir.comprimento2();
	float mb = dot(r->dir,oc);
	float c =  oc.comprimento2()-raio*raio;
	float d=mb*mb-a*c;
	if(d<t_min)
		return res;
	res.dis =  (-mb-sqrt(d))/a;
	if(res.dis<t_min||t_max <res.dis)
	{
		res.dis = (-mb+sqrt(d))/a;
		if(res.dis<t_min || t_max<res.dis)
			return res;
	}
	res.pos = r->Em(res.dis);
	res.normal = ((res.pos-pos)/raio).normalizado();
	bool EmFrente = dot(r->dir, res.normal) < 0.0f;
	res.normal = EmFrente ? res.normal : -1.0f*res.normal;
	//res.normal = (res.pos-pos)/raio;
	res.toque =true;
	res.obj = this;
	return res;
};

OBJ::OBJ(vec3 pos,float raio, MAT *material):pos(pos),raio(raio),material(material)

{
};
