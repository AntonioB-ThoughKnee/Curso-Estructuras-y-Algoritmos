#ifndef ALGORITMOS_GRAFO
#define ALGORITMOS_GRAFO
#include "ListaIndexadaPlantilla.hpp"
#include "ColaConPrioridad.hpp"
#include "SeleccionDeGrafo.hpp"
#include <map>

struct ContenedorDijkstra;

namespace Algoritmos{
  void Dijkstra(Grafo* g, Vertice* v, ListaIndexada<ContenedorDijkstra>* lista);
}

#endif /* ALGORITMOS_GRAFO */
