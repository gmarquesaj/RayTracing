#pragma once
#include "vec3.hpp"
#include "ray.hpp"
#include "obj.hpp"
#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cmath>
#include"aleatorio.hpp"
#include"aabb.hpp"
using std::cout;
using std::vector;
using std::string;
using std::to_string;
using std::ifstream;
using std::ofstream;

class arvore{
	public:
		MAT matNulo ;
		vector<OBJ> objs;
		vector<int> indices;
		vector<caixa> caixas;
		bool ultimaCamada(int v);
		int nosNaUltimaCamada();
		void adicionaObj(OBJ obj);
		void calcCaixas(int ini, int fim,int c);
		void print();
		void popularArvore();
		void ordenar(int ini, int fim, int elemento);
		void trocar(int a,int b);
		arvore();
};
