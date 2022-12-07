#ifndef ALGORITMOS_GRAFO
#define ALGORITMOS_GRAFO
#include "ListaIndexadaPlantilla.hpp"
#include "ColaConPrioridad.hpp"
#include "SeleccionDeGrafo.hpp"
#include <map>
#include <vector>

struct ContenedorDijkstra;

namespace Algoritmos{
  /**
   * @brief Algoritmo que dado un vÃ©rtice de inicio, se le calcula el peso total para ir a todos los vÃ©rtices, junto al vÃ©rtice anterior que se usa para llegar a ese vÃ©rtice destino, se logra por medio de una lista pasada como parÃ¡metro para modificarla y guardar el resultado, en Ã©sta lista se encuentran "contenedores Dijsktra" los cuales contienen el "peso total" y "vÃ©rtice anterior"
   * @remark Requiere: Grafo vÃ¡lido con al menos un elemento, lista pasada como parÃ¡metro NO inicializada
   * @remark Efecto: Modificar una lista pasada como parÃ¡metro donde se encuentra el resultado de aplicar Dijsktra con el vÃ©rtice dado
   * @remark Modifica: La lista pasada com
   * 
   * @param g Grafo
   * @param v  Vértice de partida
   * @param lista Lista resultante del algoritmo
   */
  void Dijkstra(Grafo* g, Vertice* v, ListaIndexada<ContenedorDijkstra>* lista);

  /**
   * @brief Algoritmo que hace bÃºsqueda exhaustiva pura para resolver el problema de "Coloreo", Usa variables globales y 2 Conjuntos de Conjuntos  
   * La soluciÃ³n se encuentra en la variable global "colorDeVÃ©rtice", el cual es un arreglo donde cada Ã­ndice representa un vÃ©rtice(por medio de la variable global "relaciÃ³n1a1") y el valor en el arreglo representa el color del que estÃ¡ pintado,  retorna el menor nÃºmero de colores para pintar el grafo  
   * IMPORTANTE: Existe un "#define NN" en "Algoritmos.cpp" el cual debe ser modificado de acuerdo al nÃºmero de vÃ©rtices en en grafo  
   * @remark Requiere: Grafo con al menos un vÃ©rtice  
   * @remark Efecto: Resuelve el problema de coloreo en un grafo dado  
   * @remark Modifica: Variables globales
   * 
   * @param g  Grafo
   * @return int Número mínimo de colores para pintar el grafo
   */
  int Coloreo(Grafo* g);

  int Hamilton(Grafo* g);

  int HamiltonBERA(Grafo* g);
  
}


#endif /* ALGORITMOS_GRAFO */
