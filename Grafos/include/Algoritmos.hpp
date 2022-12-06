#ifndef ALGORITMOS_GRAFO
#define ALGORITMOS_GRAFO
#include "ListaIndexadaPlantilla.hpp"
#include "ColaConPrioridad.hpp"
#include "SeleccionDeGrafo.hpp"
#include <map>

struct ContenedorDijkstra;

namespace Algoritmos{
  void Dijkstra(Grafo* g, Vertice* v, ListaIndexada<ContenedorDijkstra>* lista);

  void Coloreo(Grafo* g);

  void Hamilton(Grafo* g);
  
}


#endif /* ALGORITMOS_GRAFO */
