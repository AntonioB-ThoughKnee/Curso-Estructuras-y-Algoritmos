#include <iostream>
// #include "../include/GrafoListaAd.hpp"
#include "../include/GrafoMatrizAd.hpp"
#include "../include/ListaIndexadaPlantilla.hpp"
using namespace std;

//===========================  testing functions
template <typename Pmatrix>//It is the easiest way to make a function with templates to pass it as an argument a matrix
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

template <typename Pmatrix>
void setRowAndColumn(Pmatrix& matrix, int rows, int columns){
	int value;
	for(int ii = 0; ii < rows ; ii++){
		matrix[1][ii] = 0;
		matrix[ii][1] = 0;
	}
}

//=====  

int main(){

	//===========================  Test for matrices and map
	int matrix[5][5] = {1, 2, 3, 4, 5,
											2, 4, 6, 8, 10,
											3, 6, 9, 12, 15,
											4, 8, 12,16, 20,
											5, 10,15,20, 25};
	setRowAndColumn(matrix, 5, 5);
	printMatrix(matrix, 5, 5);

	//=====  

	Grafo* g = new Grafo();
	Vertice* vtmp;
	Vertice* va = g->agregarVertice("a");
	Vertice* vb = g->agregarVertice("b");
	Vertice* vc = g->agregarVertice("c");
	Vertice* vd = g->agregarVertice("d");
	Vertice* ve = g->agregarVertice("e");
	Vertice* vf = g->agregarVertice("f");

	g->agregarArista(va, vb, 5);
	g->agregarArista(va, vc, 1);
	g->agregarArista(vc, vb, 9);
	g->agregarArista(vd, vb, 8);
	g->agregarArista(vf, vb, 2);
	g->agregarArista(vc, ve, 5);
	g->agregarArista(vd, vf, 3);
	g->agregarArista(va, vf, 5);
	g->agregarArista(ve, vb, 8);

	g->eliminarArista(va, vc);
	g->eliminarArista(vb, va);

	printMatrix(g->matrizVertices, 10, 10);

	vtmp = g->primerVertice();
	vtmp = g->siguienteVertice(vtmp);
	vtmp = g->primerVerticeAdyacente(vtmp);
	vtmp = g->siguienteVerticeAdyacente(vtmp, vc);
	

	return 0;
}
