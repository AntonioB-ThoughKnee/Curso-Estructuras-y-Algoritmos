#include <iostream>
#include "../include/GrafoListaAd.hpp"
#include "../include/ListaIndexadaPlantilla.hpp"
using namespace std;

int main(){


	GrafoListaAd* g = new GrafoListaAd();
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

	vtmp = g->primerVertice();
	vtmp = g->siguienteVertice(vtmp);
	vtmp = g->primerVerticeAdyacente(vtmp);
	vtmp = g->siguienteVerticeAdyacente(vtmp, vc);
	

	return 0;
}
