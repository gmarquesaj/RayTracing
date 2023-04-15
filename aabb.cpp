#include "aabb.hpp"



aabb::aabb():minimo(vec3(0)),maximo(vec3(0)),objDir(NULL),objEsq(NULL),caixaDir(NULL),caixaEsq(NULL)
{

};

aabb::aabb(vec3 min,vec3 max,OBJ * objDir,OBJ * objEsq,aabb * caixaDir,aabb * caixaEsq):minimo(min),maximo(max),objDir(objDir),objEsq(objEsq),caixaDir(caixaDir),caixaEsq(caixaEsq)
{
};

aabb::aabb(aabb * caixaDir,aabb * caixaEsq):minimo(vec3(0)),maximo(vec3(0)),objDir(NULL),objEsq(NULL),caixaDir(caixaDir),caixaEsq(caixaEsq){};
aabb::aabb(OBJ * objDir,OBJ * objEsq):minimo(vec3(0)),maximo(vec3(0)),objDir(objDir),objEsq(objEsq),caixaDir(NULL),caixaEsq(NULL){};
