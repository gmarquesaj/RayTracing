#include "arvore.hpp"

void arvore:: trocar(int a,int b){
	OBJ temp = objs[a];
	objs[a]=objs[b];
	objs[b]= temp;
};
void arvore:: adicionaObj(OBJ obj){
	objs.push_back(obj);
};

void arvore::ordenar(int ini, int fim, int elemento){
	for(int x=ini;x<fim;x++)
		for(int y=x;y<fim;y++)
			if(objs[x].pos[elemento]>objs[y].pos[elemento])
				trocar(x,y);
};

void arvore::calcCaixas(){
	int exp=0;
	int nTam = 0;
	while(nTam<objs.size())
	{
		exp++;
		nTam = pow(2,exp);
	}
	caixas.resize(nTam,caixa(vec3(0),vec3(0),0,0));
	//
	for(int i=0;i<nTam/2;i++)
	{
		caixas[i].indEsq = i*2+1;
		caixas[i].indDir = i*2+2;
	}

	//
	
	ordenar(0,objs.size(),0);

};

bool arvore::ultimaCamada(int v)
{
	return (v + 1 >= (objs.size() + 1) / 2);
};
