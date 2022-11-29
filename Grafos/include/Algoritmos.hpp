#ifndef ALGORITMOS_GRAFO
#define ALGORITMOS_GRAFO
#include "ListaIndexadaPlantilla.hpp"
#include "ColaConPrioridad.hpp"
#include "SeleccionDeGrafo.hpp"
#include <map>

struct ContenedorDijkstra;

namespace Algoritmos{
  void Dijkstra(Grafo* g, Vertice* v, ListaIndexada<ContenedorDijkstra>* lista);

  /**
   * @brief 
   * Requiere:
   * Las 2 matrices deben tener dimensiones M*M, M = cantidad de vértices
   * @param g 
   * @param v 
   * @param mAdj 
   * @param mVert 
   */
  // template <typename IntM, typename StrM>
  // void Floyd(Grafo* g, IntM& mAdj, StrM& mVert){
  //   std::map<int, Vertice*> relacion1a1;
  //   mAdj[1][1] = 77777;
  //   mVert[1][1] = 88888;
  //   int numVertices = g->numVertices();
  //   Vertice tmp = g->primerVertice();
  //   Vertice tmpAd = g->primerVerticeAdyacente(tmp);


  //   for(int ii = 0; ii < numVertices ; ii++){
  //     for(int iii = 0; iii < numVertices ; iii++){
  //       if(ii == iii) iii++;
        
  //       mAdj[ii][iii] = g->peso(tmp, tmpAd);
  //       tmpAd = g->siguienteVerticeAdyacente(tmp, tmpAd);
  //     }
  //     tmp = g->siguienteVertice(tmp);
  //   }
  // }

  void Coloreo(Grafo* g);
  
}

//===========================  Usar este código para Floyd
//Crea 2 matrices, una es de adyacencia pero la otra estara vacia

  // std::map<Vertice*, int> relacion1a1; //Relación para traducir entre la matriz de adyacencia y las etiquetas

  // Vertice* tmp = g->primerVertice();
  // Vertice* tmpAd = g->primerVerticeAdyacente(tmp);
  // for(int ii = 0; ii < NN ; ii++){
  //   relacion1a1.insert(pair<Vertice*, int>(tmp, ii));
  //   tmp = g->siguienteVertice(tmp);
  // }

  // tmp = g->primerVertice();
  // for(int ii = 0; ii < NN ; ii++){
  //   for(int iii = 0; iii < NN ; iii++){
  //     CCColoreados[ii][iii] = false;
  //     if(tmpAd != nullptr){
  //       CCAdyacentes[ii][relacion1a1[tmpAd]] = true;
  //       tmpAd = g->siguienteVerticeAdyacente(tmp, tmpAd);
  //     }

  //   }

  //   tmp = g->siguienteVertice(tmp);
  //   if(tmp != nullptr) tmpAd = g->primerVerticeAdyacente(tmp);
  // }

  // cout << "Imprimiendo matriz construida de adyacencia\n " << endl;
  // printMatrix(CCAdyacentes,6, 6)
//=====  


#endif /* ALGORITMOS_GRAFO */
