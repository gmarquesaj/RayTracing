#include "arvore.hpp"
using std::min;
using std::max;


void arvore:: print(){
	int pOBJ = nosNaUltimaCamada()-1;
	printf("\npOBJ = %d\n",pOBJ);
	for(int c=0;c<caixas.size();c++){
		int esq = caixas[c].indEsq;
		int dir = caixas[c].indDir;
		if(c>=pOBJ)
		{
			printf("\nultima linha\n");
			dir=dir-caixas.size();
			esq=esq-caixas.size();
		}
		//printf("\n\nCaixa %d indEsq %d {raio = %f} indDir %d{raio = %f} \n",c,esq,objs[esq].raio,dir,objs[dir].raio);
		//else
			printf("Caixa %d indEsq %d indDir %d\n",c,esq,dir);
	}

};
arvore::arvore():matNulo(vec3(1.0f,0.0f,1.0f),0.5f,0.5f,DIFUSO)
{


};


bool arvore::ultimaCamada(int v)
{
	return (v  >= (caixas.size() + 1) / 2-1);
};
int arvore:: nosNaUltimaCamada(){
	return ((caixas.size()+1)/2);
};


void arvore:: trocar(int a,int b){
	//OBJ temp = objs[a];
	//objs[a]=objs[b];
	//objs[b]= temp;
	//if(a<objs.size() and b<objs.size())
	std::swap(indices[a],indices[b]);
};


void arvore:: adicionaObj(OBJ obj){
	objs.push_back(obj);
};

void arvore::ordenar(int ini, int fim, int elemento){
	for(int x=ini;x<fim;x++)
		for(int y=x;y<fim;y++)
			if(y<objs.size() and x<objs.size())
				if(objs[x].pos[elemento]>objs[y].pos[elemento])
					trocar(x,y);
};


void arvore::popularArvore()
{
	int exp=0;
	int nTam = 0;
	while(nTam<objs.size())
	{
		exp++;
		nTam = pow(2,exp);
	}
	nTam-=1;
	caixas.resize(nTam,caixa(vec3(0),vec3(0),-1,-1));
	indices.resize(nosNaUltimaCamada()*2,-1);
	//objs.resize(nosNaUltimaCamada()*2,OBJ(vec3(0),1.0,&matNulo));
	printf("o numero de caixas é %d com %d nos na ultima camada e %ld objetos\n",nTam,nosNaUltimaCamada(),objs.size());
	//
	int c =0;//camada atualmente trabalhada
	int p = caixas.size();// tamanho atual de cada pedaço, que é a quantidade de OBJS a serem agrupados na caixa

	int np =1;// numero de pedaços
	int ale =0;
	int pOBJ = nosNaUltimaCamada();
	for(int i=0;i<objs.size();i++)
	{
	indices[i]=i;
	}
	while(p>=1)
	{

		for(int i= 0;i<np;i++)
		{
			int ini = i*(p+1);
			int fim = ini+p+1;
			//int fim = i==np-1?caixas.size():ini+p;
			ordenar(ini,fim,ale%3);
			calcCaixas(ini,fim,c);
                         int indD = c*2+2;
                          int indE = c*2+1;
                          caixas[c].indDir = indD;
                          caixas[c].indEsq = indE;

			
			c+=1;
		}
		ale+=1;
		np*=2;
		p= caixas.size()/np;
		//printf("\nP = %d, NP = %d\n",p,np);
	}
};


void arvore::calcCaixas(int ini, int fim, int c){
	vec3 mini = objs[indices[ini]].minCaixa;
	vec3 maxi = objs[indices[ini]].maxCaixa;
	for(int i = ini+1; i<fim;i++)
	{
		//if(objs[i].indEsq<0 or objs[i].indDir<0) continue;
		mini.x=fmin(objs[indices[i]].minCaixa.x,mini.x);
		mini.y=fmin(objs[indices[i]].minCaixa.y,mini.y);
		mini.z=fmin(objs[indices[i]].minCaixa.z,mini.z);

		maxi.x=fmax(objs[indices[i]].maxCaixa.x,maxi.x);
		maxi.y=fmax(objs[indices[i]].maxCaixa.y,maxi.y);
		maxi.z=fmax(objs[indices[i]].maxCaixa.z,maxi.z);
	}
	caixas[c].minimo = mini;
	caixas[c].maximo = maxi;
//	printf("Calculando caixa %d com os objeto entre %d e %d com dimensoes [%3.2f,%3.2f,%3.2f]->[%3.2f,%3.2f,%3.2f]\n",c,ini,fim,mini.x,mini.y,mini.z,maxi.x,maxi.y,maxi.z);
};

