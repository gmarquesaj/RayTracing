#include "vec3.hpp"

vec3::vec3(float v):x(v),y(v),z(v)
{

};

void vec3::print()
{
	printf("[%4.3f %4.3f %4.3f]\n", x, y, z);
}
// construtor
vec3::vec3(float x, float y, float z) : x(x), y(y), z(z){};
// construtor via copia
vec3::vec3(const vec3 &cpy)
{
	*this = cpy;
	//  cout << "construido via copia\n";
}
vec3 &vec3::operator=(const vec3 &cpy)
{
	x = cpy.x;
	y = cpy.y;
	z = cpy.z;
	//  cout << "copiado via operador\n";
	return *this;
}
vec3 vec3::operator+(float b)
{
	return vec3(x + b, y + b, z + b);
}
vec3 vec3::operator*(float b)
{
	return vec3(x * b, y * b, z * b);
}
vec3 vec3::operator+(vec3 b)
{
	return vec3(x + b.x, y + b.y, z + b.z);
}
vec3 vec3::operator*(vec3 b)
{
	return vec3(x * b.x, y * b.y, z * b.z);
}

vec3 operator+(float b, vec3 a)
{
	return vec3(a.x + b, a.y + b, a.z + b);
}
vec3 operator*(float b, vec3 a)
{
	return vec3(a.x * b, a.y * b, a.z * b);
}

float dot(vec3 &u, vec3 &v)
{
	return u.x * v.x + u.y * v.y + u.z * v.z;
}
vec3 cross(vec3 &u, vec3 &v)
{
	return vec3(u.y * v.z - u.z * v.y,
			u.z * v.x - u.x * v.z,
			u.x * v.y - u.y * v.x);
}

vec3 lerp3(vec3 &a, vec3 &b, float v)
{
	return vec3(a.x + (b.x - a.x) * v, a.y + (b.y - a.y) * v, a.z + (b.z - a.z) * v);
}



float vec3::comprimento(){
	return sqrt(x*x+y*y+z*z);

};

float vec3::comprimento2(){
	return (x*x+y*y+z*z);

};
vec3 vec3::normalizado()
{
	vec3 res = *this;
	res = res/comprimento();
	return res;
};

vec3 vec3::operator-(float b)
{
	return vec3(x - b, y - b, z - b);
}
vec3 vec3::operator/(float b)
{
	return vec3(x / b, y / b, z / b);
}
vec3 vec3::operator-(vec3 b)
{
	return vec3(x - b.x, y - b.y, z - b.z);
}
vec3 vec3::operator/(vec3 b)
{
	return vec3(x / b.x, y / b.y, z / b.z);
}

vec3 operator-(float b, vec3 a)
{
	return vec3(a.x - b, a.y - b, a.z - b);
}
vec3 operator/(float b, vec3 a)
{
	return vec3(a.x / b, a.y / b, a.z / b);
}

