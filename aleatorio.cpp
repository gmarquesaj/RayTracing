#include "aleatorio.hpp"

float randomFloat()
{
	return (float)rand()/(float)(RAND_MAX);
}
float randomFloatMinMax(float min,float max)
{
	return min+(max-min)*randomFloat();
};

vec3 randomFloatVec3(){
	return vec3(randomFloat(),randomFloat(),randomFloat());
};

vec3 randomFloatVec3MinMax(float min, float max)
{
	return vec3(randomFloatMinMax(min,max),randomFloatMinMax(min,max),randomFloatMinMax(min,max));
}


vec3 randomHemisphereDirection(vec3 normal){
vec3 dir = randomFloatVec3MinMax(-1,1).normalizado();
if(dot(dir,normal)>0.0)
	return dir;
else return dir *-1;



};
