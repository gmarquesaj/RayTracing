#include "vec3.hpp"
vec3:: vec3(float x,float y, float z):x(x),y(y),z(z){

}

vec3 vec3:: normalizado(vec3 v) { return v / v.distancia();}

vec3 vec3:: operator-()  { 
	return vec3(-x, -y, -z); 
}

float& vec3:: operator[](int i) { return i==0?x:i==1?y:z; }   
vec3& vec3:: operator+=( vec3 &v) { 
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

vec3& vec3:: operator*=( float t) {  
	x *= t;
	y *= t;
	z *= t;
	return *this;
} 

vec3& vec3::  operator/=( float t) {
	return *this *= 1/t;
}
float vec3::  distancia()  {
	return sqrt(distancia2());
}
float vec3::  distancia2()  { 
	return x*x + y*y + z*z;
}


vec3 vec3:: operator+(   vec3 &v) { return vec3(x + v.x, y + v.y, z + v.z);
}
vec3  vec3::operator-(   vec3 &v) { return vec3(x - v.x, y - v.y, z - v.z);
}
vec3  vec3::operator*(   vec3 &v) { return vec3(x * v.x, y * v.y, z * v.z);
}
vec3  vec3::operator*(  float t) { return *this*t ;
}
vec3  vec3::operator/(float t) { return *this*(1.0/t);
}


float dot( vec3 &u,  vec3 &v) { return u.x * v.x          + u.y * v.y          + u.z * v.z;
}
vec3 cross( vec3 &u,  vec3 &v) { return vec3(u.y * v.z - u.z * v.y,
		u.z * v.x - u.x * v.z,
		u.x * v.y - u.y * v.x);
}

