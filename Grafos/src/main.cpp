#include <iostream>
#include "../include/ListaIndexadaPlantilla.hpp"
#include "../include/SeleccionDeGrafo.hpp"
#include "../include/Algoritmos.hpp"
#include "../include/pruebas.hpp"
#include "../include/Menu.hpp"
#include <map>

using namespace Algoritmos;
using namespace std;

#define ORIGINAL  // KRUSKAL, PRIM

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

Menu* menu= new Menu;
menu->Run();
delete  menu;

return 0;



}
#if 0
	Grafo* g = new Grafo();
	// g->iniciar();
	Vertice* vtmp;
	Vertice* va = g->agregarVertice("a");
	Vertice* vb = g->agregarVertice("b");
	Vertice* vc = g->agregarVertice("c");
	Vertice* vd = g->agregarVertice("d");
	Vertice* ve = g->agregarVertice("e");
	Vertice* vf = g->agregarVertice("f");

#ifdef ORIGINAL
	g->agregarArista(va, vb, 8);
	g->agregarArista(va, vc, 1);
	g->agregarArista(vc, vb, 9);
	g->agregarArista(vd, vb, 8);
	g->agregarArista(vf, vb, 2);
	g->agregarArista(vc, ve, 5);
	g->agregarArista(vd, vf, 3);
	g->agregarArista(va, vf, 5);
	g->agregarArista(ve, vb, 8);
#endif



#ifdef PRIM
	g->agregarArista(va, vb, 2);
	g->agregarArista(va, vc, 8);
	g->agregarArista(vc, vb, 3);
	g->agregarArista(vc, ve, 1);
	g->agregarArista(va, ve, 7);
	g->agregarArista(ve, vf, 4);
	g->agregarArista(va, vf, 3);
	g->agregarArista(vf, vd, 9);
	g->agregarArista(va, vd, 6);
	g->agregarArista(vb, vd, 9);
	g->agregarArista(vc, vf, 6);
	g->agregarArista(vb, vf, 5);
#endif
	// Relacion1A1* relacion1a1=new Relacion1A1;
	// int ** matrizPesos=new int *[g->numVertices()];
	// Vertice *** matrizVertices=new Vertice **[g->numVertices()];
	// relacion1a1->insertar(va,0);
	// relacion1a1->insertar(vb,1);
	// relacion1a1->insertar(vc,2);

	// Floyd(g,matrizPesos,matrizVertices,relacion1a1);



#ifdef KRUSKAL
	g->agregarArista(va, vb, 3);
	g->agregarArista(vb, vc, 9);
	g->agregarArista(vc, va, 7);
	g->agregarArista(va, vd, 6);
	g->agregarArista(va, ve, 8);
	g->agregarArista(vd, ve, 2);
	g->agregarArista(vd, vf, 4);
	g->agregarArista(ve, vf, 5);
	g->agregarArista(vc, ve, 10);
#endif

	//Floyd(g, va, mAdj, mVert);
  	// Coloreo(g);
	// Hamilton(g);
	// HamiltonBERA(g);
  #ifdef PRIM
  Prim(g);
  #endif
  #ifdef KRUSKAL
  Kruskal(g);
  #endif
	// Coloreo(g);

  // g->agregarArista(vc, va, 12);
  Pruebas* prueba=new Pruebas;
  prueba->test();
  delete prueba;


	vtmp = g->primerVertice();
	vtmp = g->siguienteVertice(vtmp);
	vtmp = g->primerVerticeAdyacente(vtmp);
	vtmp = g->siguienteVerticeAdyacente(vtmp, vb);
	

	return 0;
}
#endif
