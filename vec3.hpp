#pragma once
#include <cmath>
#include<iostream>
using std::cout;

class vec3
{
	public:
		float x, y, z;
		void print();
		// construtor
		vec3(float v);
		vec3(float x, float y, float z);
		// construtor via copia
		vec3(const vec3 &cpy);
		vec3 &operator=(const vec3 &cpy);
		vec3 operator+(float b);
		vec3 operator*(float b);
		vec3 operator+(vec3 b);
		vec3 operator*(vec3 b);

		vec3 operator-(float b);
		float comprimento2();
		vec3 operator/(float b);
		vec3 operator-(vec3 b);
		vec3 operator/(vec3 b);
		float comprimento();
		vec3 normalizado();
		void clamp1();
		void clamp1sqrt();

};
float dot(vec3 &u, vec3 &v);
vec3 cross(vec3 &u, vec3 &v);
vec3 lerp3(vec3 &a, vec3 &b, float v);
vec3 operator+(float b, vec3 a);
vec3 operator-(float b, vec3 a);
vec3 operator*(float b, vec3 a);
vec3 operator/(float b, vec3 a);
