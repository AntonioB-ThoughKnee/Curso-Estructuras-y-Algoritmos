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
  this->grafo1->iniciar();
  for (int i = 0; i < 3; i++) {
    this->grafo1->agregarVertice(std::to_string(i));
  }

  // GRAFO 2
  this->grafo2 = new Grafo();
  this->grafo2->iniciar();
  for (int i = 0; i < 8; i++) {
    this->grafo2->agregarVertice(std::to_string(i));
  }

  // GRAFO 3
  this->grafo3 = new Grafo();
  this->grafo3->iniciar();
  for (int i = 0; i < 3; i++) {
    Vertice* vertAgregado = this->grafo3->agregarVertice(std::to_string(i));
    mapGrafo3.insert({i, vertAgregado});
  }
  for (int i = 0; i < grafo3->numVertices()-1; i++) {
    for (int m = (i); m < grafo3->numVertices(); m++) {
      if (i != m) {
        grafo3->agregarArista(mapGrafo3[i], mapGrafo3[m], m*i);
      }
    }
  }


  // GRAFO 4
  this->grafo4 = new Grafo();
  this->grafo4->iniciar();
  for (int i = 0; i < 8; i++) {
    Vertice* vertAgregado1 = this->grafo4->agregarVertice(std::to_string(i));
    mapGrafo4.insert({i, vertAgregado1});
  }
    for (int i = 0; i < grafo4->numVertices()-1; i++) {
    for (int m = (i); m < grafo4->numVertices(); m++) {
      if (i != m) {
        grafo4->agregarArista(mapGrafo4[i], mapGrafo4[m], m*i);
      }
    }
  }
}

Pruebas::~Pruebas() {
  this->grafo1->destruir();
  this->grafo2->destruir();
  this->grafo3->destruir();
  this->grafo4->destruir();
  if (this->grafo1){
    delete this->grafo1;
  }
  if (this->grafo2){
    delete this->grafo2;
  }
  if (this->grafo3){
    delete this->grafo3;
  }
  if (this->grafo4){
    delete this->grafo4;
  }
}

void Pruebas::test() {

    clock_t start, end;
  // grafo1
  Relacion1A1* relacion1a1G1=new Relacion1A1;
	int ** matrizPesosG1=new int *[grafo1->numVertices()];
	Vertice *** matrizVerticesG1=new Vertice **[grafo1->numVertices()];
  start = clock();
	Floyd(grafo1,matrizPesosG1,matrizVerticesG1,relacion1a1G1);
  end = clock();
  double test1 = double(end - start) / double(CLOCKS_PER_SEC);
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
  start = clock();
	Floyd(grafo2,matrizPesosG2,matrizVerticesG2,relacion1a1G2);
  end = clock();
  double test2 = double(end - start) / double(CLOCKS_PER_SEC);
  
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
  start = clock();
	Floyd(grafo3,matrizPesosG3,matrizVerticesG3,relacion1a1G3);
  end = clock();
  double test3 = double(end - start) / double(CLOCKS_PER_SEC);

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
  start = clock();
	Floyd(grafo4,matrizPesosG4,matrizVerticesG4,relacion1a1G4);
  end = clock();
  double test4 = double(end - start) / double(CLOCKS_PER_SEC);

  delete relacion1a1G4;
  for(int i = 0; i < grafo4->numVertices(); ++i){
		delete[] matrizPesosG4[i];
	 	delete[] matrizVerticesG4[i];
	}

	delete[] matrizPesosG4;
	delete[] matrizVerticesG4;

  ListaIndexada<ContenedorDijkstra>* listaG1=new ListaIndexada<ContenedorDijkstra>[grafo1->numVertices()];
  start = clock();
  Algoritmos::NDijkstra(grafo1,listaG1);
  end = clock();
  double test5 = double(end - start) / double(CLOCKS_PER_SEC);
  ListaIndexada<ContenedorDijkstra>* listaG2=new ListaIndexada<ContenedorDijkstra>[grafo2->numVertices()];
  start = clock();
  Algoritmos::NDijkstra(grafo2,listaG2);
  end = clock();
  double test6 = double(end - start) / double(CLOCKS_PER_SEC);
  ListaIndexada<ContenedorDijkstra>* listaG3=new ListaIndexada<ContenedorDijkstra>[grafo3->numVertices()];
  start = clock();
  Algoritmos::NDijkstra(grafo3,listaG3);
  end = clock();
  double test7 = double(end - start) / double(CLOCKS_PER_SEC);
  ListaIndexada<ContenedorDijkstra>* listaG4=new ListaIndexada<ContenedorDijkstra>[grafo4->numVertices()];
  start = clock();
  Algoritmos::NDijkstra(grafo4,listaG4);
  end = clock();
  double test8 = double(end - start) / double(CLOCKS_PER_SEC);

  delete[] listaG1;
  delete[] listaG2;
  delete[] listaG3;
  delete[] listaG4;

  // ALGORITMOS D Y E
  start = clock();
  Prim(grafo1);
  end = clock();
  double test9 = double(end - start) / double(CLOCKS_PER_SEC);
  start = clock();
  Prim(grafo2);
  end = clock();
  double test10 = double(end - start) / double(CLOCKS_PER_SEC);
  start = clock();
  Prim(grafo3);
  end = clock();
  double test11 = double(end - start) / double(CLOCKS_PER_SEC);
  start = clock();
  Prim(grafo4);
  end = clock();
  double test12 = double(end - start) / double(CLOCKS_PER_SEC);

  start = clock();
  // Kruskal(grafo1);
  start = clock();
  end = clock();
  double test13punto5 = double(end - start) / double(CLOCKS_PER_SEC);
  // Kruskal(grafo2);
  end = clock();
  double test13 = double(end - start) / double(CLOCKS_PER_SEC);
  start = clock();
  Kruskal(grafo3);
  end = clock();
  double test14 = double(end - start) / double(CLOCKS_PER_SEC);
  start = clock();
  Kruskal(grafo4);
  end = clock();
  double test15 = double(end - start) / double(CLOCKS_PER_SEC);
  
  // // ALGORITMOS F Y H
  // start = clock();
  // Hamilton(grafo1);
  // end = clock();
  // double test16 = double(end - start) / double(CLOCKS_PER_SEC);
  // start = clock();
  // Hamilton(grafo2);
  // end = clock();
  // double test17 = double(end - start) / double(CLOCKS_PER_SEC);
  // start = clock();
  // Hamilton(grafo3);
  // end = clock();
  // double test18 = double(end - start) / double(CLOCKS_PER_SEC);
  // start = clock();
  // Hamilton(grafo4);
  // end = clock();
  // double test19 = double(end - start) / double(CLOCKS_PER_SEC);
  // start = clock();
  // HamiltonBERA(grafo1);
  // end = clock();
  // double test20 = double(end - start) / double(CLOCKS_PER_SEC);
  // start = clock();
  // HamiltonBERA(grafo2);
  // end = clock();
  // double test21 = double(end - start) / double(CLOCKS_PER_SEC);
  // start = clock();
  // HamiltonBERA(grafo3);
  // end = clock();
  // double test22 = double(end - start) / double(CLOCKS_PER_SEC);
  // start = clock();
  // HamiltonBERA(grafo4);
  // end = clock();
  // double test23 = double(end - start) / double(CLOCKS_PER_SEC);

  start = clock();
  Coloreo(grafo1);
  end = clock();
  double test24 = double(end - start) / double(CLOCKS_PER_SEC);
  start = clock();
  Coloreo(grafo2);
  end = clock();
  double test25 = double(end - start) / double(CLOCKS_PER_SEC);
  start = clock();
  Coloreo(grafo3);
  end = clock();
  double test26 = double(end - start) / double(CLOCKS_PER_SEC);
  start = clock();
  Coloreo(grafo4);
  end = clock();
  double test27 = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "Floyd grafo pequenho no conexo: " << fixed 
         << test1 << setprecision(5);
    cout << " sec " << endl;

    cout << "Floyd grafo grande no conexo: " << fixed 
         << test2 << setprecision(5);
    cout << " sec " << endl;

    cout << "Floyd grafo pequenho conexo: " << fixed 
         << test3 << setprecision(5);
    cout << " sec " << endl;

    cout << "Floyd grafo grande conexo: " << fixed 
         << test4 << setprecision(5);
    cout << " sec " << endl;

    cout << "NDijsktra grafo pequenho no conexo: " << fixed 
         << test5 << setprecision(5);
    cout << " sec " << endl;

    cout << "NDijsktra grafo grande no conexo: " << fixed 
         << test6 << setprecision(5);
    cout << " sec " << endl;

    cout << "NDijsktra grafo pequenho conexo: " << fixed 
         << test7 << setprecision(5);
    cout << " sec " << endl;

    cout << "NDijsktra grafo grande conexo: " << fixed 
         << test8 << setprecision(5);
    cout << " sec " << endl;

    cout << "Prim grafo pequenho no conexo: " << fixed 
         << test9 << setprecision(5);
    cout << " sec " << endl;

    cout << "Prim grafo grande no conexo: " << fixed 
         << test10 << setprecision(5);
    cout << " sec " << endl;

    cout << "Prim grafo pequenho conexo: " << fixed 
         << test11 << setprecision(5);
    cout << " sec " << endl;

    cout << "Prim grafo grande conexo: " << fixed 
         << test12 << setprecision(5);
    cout << " sec " << endl;

    cout << "Kruskal grafo pequenho no conexo: " << fixed 
         << test13punto5 << setprecision(5);
    cout << " sec " << endl;

    cout << "Kruskal grafo grande no conexo: " << fixed 
         << test13 << setprecision(5);
    cout << " sec " << endl;

    cout << "Kruskal grafo pequenho conexo: " << fixed 
         << test14 << setprecision(5);
    cout << " sec " << endl;

    cout << "Kruskal grafo grande conexo: " << fixed 
         << test15 << setprecision(5);
    cout << " sec " << endl;

    // cout << "Hamilton grafo pequenho no conexo: " << fixed 
    //      << test16 << setprecision(5);
    // cout << " sec " << endl;

    // cout << "Hamilton grafo grande no conexo: " << fixed 
    //      << test17 << setprecision(5);
    // cout << " sec " << endl;

    // cout << "Hamilton grafo pequenho conexo: " << fixed 
    //      << test18 << setprecision(5);
    // cout << " sec " << endl;

    // cout << "Hamilton grafo grande conexo: " << fixed 
    //      << test19 << setprecision(5);
    // cout << " sec " << endl;

    // cout << "HamiltonBERA grafo pequenho no conexo: " << fixed 
    //      << test20 << setprecision(5);
    // cout << " sec " << endl;

    // cout << "HamiltonBERA grafo grande no conexo: " << fixed 
    //      << test21 << setprecision(5);
    // cout << " sec " << endl;

    // cout << "HamiltonBERA grafo pequenho conexo: " << fixed 
    //      << test22 << setprecision(5);
    // cout << " sec " << endl;

    // cout << "HamiltonBERA grafo grande conexo: " << fixed 
    //      << test23 << setprecision(5);
    // cout << " sec " << endl;

    cout << "Coloreo grafo pequenho no conexo: " << fixed 
         << test24 << setprecision(5);
    cout << " sec " << endl;

    cout << "Coloreo grafo grande no conexo: " << fixed 
         << test25 << setprecision(5);
    cout << " sec " << endl;

    cout << "Coloreo grafo pequenho conexo: " << fixed 
         << test26 << setprecision(5);
    cout << " sec " << endl;

    cout << "Coloreo grafo grande conexo: " << fixed 
         << test27 << setprecision(5);
    cout << " sec " << endl;

}