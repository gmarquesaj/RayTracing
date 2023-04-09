#pragma once
#include<iostream>
#include "vec3.hpp"

float randomFloat()
{
	return (float)rand()/(float)(RAND_MAX+1);
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


