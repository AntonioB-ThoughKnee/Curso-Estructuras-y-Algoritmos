#include <iostream>
#include "../include/ListaIndexadaPlantilla.hpp"
#include "../include/SeleccionDeGrafo.hpp"
#include "../include/ColaConPrioridad.hpp"
#include "../include/Algoritmos.hpp"
#include <map>

using namespace Algoritmos;
using namespace std;

//===========================  testing functions
template <typename Pmatrix>// This is the easiest way to make a function with templates to pass as an argument a matrix
void printMatrix(Pmatrix& matrix, int rows, int columns){
	cout << "\n# Copiar y pegar este resultado a un archivo markdown para una mejor visualización " << endl;
	int value;
	cout << "|-";
	for(int ii = 0; ii < rows ; ii++){
		cout << "|" << ii;
	}
	cout << "|" << endl;

	cout << "|-";
	for(int ii = 0; ii < rows ; ii++){
		cout << "|-";
	}
	cout << "|" << endl;

	for(int ii = 0; ii < rows ; ii++){
		cout << "|" << ii << "|";
		for(int iii = 0; iii < columns ; iii++){
			value = matrix[ii][iii];
			if(value != -1){
				cout << value << "|";
			} else{
				cout << "-" << "|";
			}
		}
		cout  << endl;
	}
}



//=====  

int main(){

	Grafo* g = new Grafo();
	Vertice* vtmp;
	Vertice* va = g->agregarVertice("a");
	Vertice* vb = g->agregarVertice("b");
	Vertice* vc = g->agregarVertice("c");
	Vertice* vd = g->agregarVertice("d");
	Vertice* ve = g->agregarVertice("e");
	Vertice* vf = g->agregarVertice("f");

	g->agregarArista(va, vb, 8);
	g->agregarArista(va, vc, 1);
	g->agregarArista(vc, vb, 9);
	g->agregarArista(vd, vb, 8);
	g->agregarArista(vf, vb, 2);
	g->agregarArista(vc, ve, 5);
	g->agregarArista(vd, vf, 3);
	g->agregarArista(va, vf, 5);
	g->agregarArista(ve, vb, 8);


	Relacion1A1* relacion1a1=new Relacion1A1;
	int ** matrizPesos=new int *[g->numVertices()];
	Vertice *** matrizVertices=new Vertice **[g->numVertices()];

	relacion1a1->insertar(va,0);
	relacion1a1->insertar(vb,1);
	relacion1a1->insertar(vc,2);

	Floyd(g,matrizPesos,matrizVertices,relacion1a1);


	for(int i =0;i<g->numVertices();++i){
		cout<<endl;
		for(int j=0;j<g->numVertices();++j){
			if (matrizPesos[i][j]==99999){
				cout<<0<<" ";				
			}else{
				cout<<matrizPesos[i][j]<<" ";
			}

		}
	}
	
	for(int i = 0; i < g->numVertices(); ++i){
		delete[] matrizPesos[i];//deletes an inner array of integer;
		delete[] matrizVertices[i];
	}

	delete[] matrizPesos; //delete pointer holding array of pointers;
	delete[] matrizVertices; //delete pointer holding array of pointers;

	return 0;
}
