#pragma once
#include<iostream>
#include <thread>
#include<vector>
#include<string>
#include "vec3.hpp"
using std::string;
using std::thread;
using std::vector;
struct PPM
{
	int w,h;
	vector<unsigned char> pxl;
	PPM(int w,int h);
	void save(string caminho="img.ppm");
	void saveP3();
	void setPxl(int x,int y,int r,int g,int b);
	void paraCadaPX(void( *func)(PPM *,int, int,int, float, float));
	void setPxl(int x,int y,vec3 cor);
	//
	//A FAZER
	//PPM DOBRO(RETORNA UMA IMAGEM COM O DOBRO DO TAMANHO, ESPECIFICANDO O TIPO de FILTRO)
	//PPM METADE(RETORNA UMA IMAGEM COM O metade DO TAMANHO, ESPECIFICANDO O TIPO de FILTRO)

};
