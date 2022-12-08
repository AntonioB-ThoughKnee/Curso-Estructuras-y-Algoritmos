#ifndef ALGORITMOS_GRAFO
#define ALGORITMOS_GRAFO
#include "ListaIndexadaPlantilla.hpp"
#include "ColaConPrioridad.hpp"
#include "SeleccionDeGrafo.hpp"
#include "relacion1A1.hpp"
#include <map>
#include <vector>


struct ContenedorDijkstra;

namespace Algoritmos{
  void Dijkstra(Grafo* g, Vertice* v, ListaIndexada<ContenedorDijkstra>* lista);
  /**
   * @brief Implementacion del algoritmo de Floyd.
   * EFECTO: Encuentra el camino mas corto entre todo par de vertices.
   * REQUIERE: Grafo inicializado, no vacio, matriz de pesos, matriz de vertices y relacion1a1
   * ademas, requiere que ningun peso del grafo sea mayor a 99998.
   * MODIFICA: matriz de pesos, matriz de vertices y relacion1a1.
   * @param g grafo a utilizar.
   * @param matrizPesos puntero a puntero de int(matriz de int) que contiene
   * los pesos de las aristas, termina conteniendo el valor de las distancias
   * entre aristas.
   * @param matrizVertices puntero a puntero a puntero de Vertices(matriz de punteros
   * a Vertices) contiene los vertices intermedios por los que se pasa para llegar de un 
   * vertice al otro.
   * @param relacion1a1 Relacion1a1 entre los vertices y el indice que los representa en 
   * las matrices
  */
  void Floyd(Grafo* g,int**& matrizPesos,Vertice***& matrizVertices,Relacion1A1* relacion1a1);
  /**
   * @brief Implementacion del algoritmo de Dijkstra n veces.
   * EFECTO: Encuentra el camino mas corto entre todo par de vertices.
   * REQUIERE: grafo inicializado no vacio. +Req de Dijkstra
   * MODIFICA: Arreglo de listas
   * @param g grafo a utilizar.
   * @param arregloListas puntero a ListaIndexada<ContenedorDijkstra>
   * (arreglo de listas) termina conteniendo las listas con los caminos 
   * mas cortos entre todos los vertices.
  */
  void NDijkstra(Grafo* g,ListaIndexada<ContenedorDijkstra>* arregloListas);
  void Coloreo(Grafo* g);
}
#endif /* ALGORITMOS_GRAFO */
