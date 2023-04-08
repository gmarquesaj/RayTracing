#pragma once
#include <cmath>
class vec3{
	public:
		float x,y,z;
		vec3(float x,float y, float z);
		vec3 operator-();
		float& operator[](int i);
		vec3& operator+=( vec3 &v);
		vec3& operator*=( float t);  
		vec3& operator/=( float t);
		float distancia();
		float distancia2();
		vec3 normalizado(vec3 v);
		vec3  operator+(   vec3 &v);
		vec3  operator-(   vec3 &v) ;
		vec3  operator*(   vec3 &v);
		vec3  operator*( float t) ;
		vec3  operator/( float t);
};
float dot( vec3 &u,  vec3 &v);
vec3 cross( vec3 &u,  vec3 &v);


