#include "obj.hpp"


vec3 OBJ:: normalToUV(vec3 normal)
{
	const float PI = 3.1415f;
	float theta = acos(-normal.y);
	float phi = atan(-(normal).x / (normal).z) + PI;
	float ui = phi / (2.0f * PI);
	float vi = theta / PI;
	return vec3(ui,vi,0.0f);
};
//funciona como uma textura provisoria ate que seja implementado uma classe de texturas
//desenha faixas/linhas na esfera
vec3 OBJ:: corEm(float u, float v){
	const int x = 50;
	return ((int)(u*x)%10)<5  || ((int)(v*x)%15)<5 ?vec3(0,0,0):vec3(0.9,0.8,0.1);	
};


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
