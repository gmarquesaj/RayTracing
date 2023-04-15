#pragma once

#include "obj.hpp"



class aabb{
	public:
		vec3 minimo;
		vec3 maximo;
		OBJ * objDir;
		OBJ * objEsq;
		aabb * caixaDir;
		aabb * caixaEsq;
		aabb();
		aabb(vec3 min,vec3 max,OBJ * objDir,OBJ * objEsq,aabb * caixaDir,aabb * caixaEsq);
		aabb(aabb * caixaDir,aabb * caixaEsq);
		aabb(OBJ * objDir,OBJ * objEsq);
};
