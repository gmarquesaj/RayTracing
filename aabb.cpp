#include "aabb.hpp"

#include<vector>
#include<string>
#include<fstream>
#include<cmath>
#include"aleatorio.hpp"
using std::cout;
using std::vector;
using std::string;
using std::to_string;
using std::ifstream;
using std::ofstream;

caixa::caixa(vec3 minimo, vec3 maximo,int indEsq, int indDir):
	minimo(minimo),maximo(maximo),indEsq(indEsq),indDir(indDir){

	};
