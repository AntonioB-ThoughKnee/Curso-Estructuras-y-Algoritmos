#ifndef ALGORITMOS_GRAFO
#define ALGORITMOS_GRAFO
#include "ListaIndexadaPlantilla.hpp"
#include "ColaConPrioridad.hpp"
#include "SeleccionDeGrafo.hpp"

struct ContenedorDijkstra;

namespace Algoritmos{
  ListaIndexada<ContenedorDijkstra> Dijkstra(Grafo* g, Vertice* v);
}

#endif /* ALGORITMOS_GRAFO */
