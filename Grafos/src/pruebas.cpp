/*
  GRAFO 1: solo 100 vertices
  GRAFO 2: solo 1000 vertices
  GRAFO 3: 100 vertices conexo
  GRAFO 4: 1000 vertices conexo
*/
#include "../include/pruebas.hpp"
using namespace std;
Pruebas::Pruebas() {
  map<int, Vertice*> mapGrafo3;
  map<int, Vertice*> mapGrafo4;
  // GRAFO 1
  this->grafo1 = new Grafo();
  for (int i = 0; i < 10; i++) {
    this->grafo1->agregarVertice(std::to_string(i));
  }

  // GRAFO 2
  this->grafo2 = new Grafo();
  for (int i = 0; i < 50; i++) {
    this->grafo2->agregarVertice(std::to_string(i));
  }

  // GRAFO 3
  this->grafo3 = new Grafo();
  for (int i = 0; i < 10; i++) {
    Vertice* vertAgregado = this->grafo3->agregarVertice(std::to_string(i));
    mapGrafo3.insert({i, vertAgregado});
  }
  for (int i = 0; i < grafo3->numVertices(); i++) {
    for (int m = 0; m < grafo3->numVertices(); m++) {
      if (i != m) {
        grafo3->agregarArista(mapGrafo3[i], mapGrafo3[m], m*i);
      }
    }
  }


  // GRAFO 4
  this->grafo4 = new Grafo();
  for (int i = 0; i < 50; i++) {
    Vertice* vertAgregado1 = this->grafo4->agregarVertice(std::to_string(i));
    mapGrafo4.insert({i, vertAgregado1});
  }
    for (int i = 0; i < grafo4->numVertices(); i++) {
    for (int m = 0; m < grafo4->numVertices(); m++) {
      if (i != m) {
        grafo4->agregarArista(mapGrafo4[i], mapGrafo4[m], m*i);
      }
    }
  }
}

Pruebas::~Pruebas() {
  delete this->grafo1;
  delete this->grafo2;
  delete this->grafo3;
  delete this->grafo4;
}

void Pruebas::test() {

  // grafo1
  Relacion1A1* relacion1a1G1=new Relacion1A1;
	int ** matrizPesosG1=new int *[grafo1->numVertices()];
	Vertice *** matrizVerticesG1=new Vertice **[grafo1->numVertices()];
	Floyd(grafo1,matrizPesosG1,matrizVerticesG1,relacion1a1G1);
  
  delete relacion1a1G1;
  for(int i = 0; i < grafo1->numVertices(); ++i){
		delete[] matrizPesosG1[i];
	 	delete[] matrizVerticesG1[i];
	}
	delete[] matrizPesosG1;
	delete[] matrizVerticesG1;


  // grafo2
  Relacion1A1* relacion1a1G2=new Relacion1A1;
	int ** matrizPesosG2=new int *[grafo2->numVertices()];
	Vertice *** matrizVerticesG2=new Vertice **[grafo2->numVertices()];
	Floyd(grafo2,matrizPesosG2,matrizVerticesG2,relacion1a1G2);
  
  delete relacion1a1G2;
  for(int i = 0; i < grafo2->numVertices(); ++i){
		delete[] matrizPesosG2[i];
	 	delete[] matrizVerticesG2[i];
	}
	delete[] matrizPesosG2;
	delete[] matrizVerticesG2;

  // grafo3
  Relacion1A1* relacion1a1G3=new Relacion1A1;
	int ** matrizPesosG3=new int *[grafo3->numVertices()];
	Vertice *** matrizVerticesG3=new Vertice **[grafo3->numVertices()];
	Floyd(grafo3,matrizPesosG3,matrizVerticesG3,relacion1a1G3);

  delete relacion1a1G3;
  for(int i = 0; i < grafo3->numVertices(); ++i){
		delete[] matrizPesosG3[i];
	 	delete[] matrizVerticesG3[i];
	}
	delete[] matrizPesosG3;
	delete[] matrizVerticesG3;

  // grafo4
  Relacion1A1* relacion1a1G4=new Relacion1A1;
	int ** matrizPesosG4=new int *[grafo4->numVertices()];
	Vertice *** matrizVerticesG4=new Vertice **[grafo4->numVertices()];
	Floyd(grafo4,matrizPesosG4,matrizVerticesG4,relacion1a1G4);

  delete relacion1a1G4;
  for(int i = 0; i < grafo4->numVertices(); ++i){
		delete[] matrizPesosG4[i];
	 	delete[] matrizVerticesG4[i];
	}

	delete[] matrizPesosG4;
	delete[] matrizVerticesG4;

  ListaIndexada<ContenedorDijkstra>* listaG1=new ListaIndexada<ContenedorDijkstra>[grafo1->numVertices()];
  Algoritmos::NDijkstra(grafo1,listaG1);
  ListaIndexada<ContenedorDijkstra>* listaG2=new ListaIndexada<ContenedorDijkstra>[grafo2->numVertices()];
  Algoritmos::NDijkstra(grafo2,listaG2);
  ListaIndexada<ContenedorDijkstra>* listaG3=new ListaIndexada<ContenedorDijkstra>[grafo3->numVertices()];
  Algoritmos::NDijkstra(grafo3,listaG3);
  ListaIndexada<ContenedorDijkstra>* listaG4=new ListaIndexada<ContenedorDijkstra>[grafo4->numVertices()];
  Algoritmos::NDijkstra(grafo4,listaG4);

  delete[] listaG1;
  delete[] listaG2;
  delete[] listaG3;
  delete[] listaG4;

  // ALGORITMOS D Y E
  Prim(grafo1);
  Prim(grafo2);
  Prim(grafo3);
  Prim(grafo4);
  Kruskal(grafo1);
  Kruskal(grafo2);
  Kruskal(grafo3);
  Kruskal(grafo4);
  
  // ALGORITMOS F Y H
  Hamilton(grafo1);
  Hamilton(grafo2);
  Hamilton(grafo3);
  Hamilton(grafo4);
  HamiltonBERA(grafo1);
  HamiltonBERA(grafo2);
  HamiltonBERA(grafo3);
  HamiltonBERA(grafo4);

}