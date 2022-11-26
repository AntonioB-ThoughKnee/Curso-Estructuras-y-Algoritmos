
#include "../include/Algoritmos.hpp"

//===========================  Estructuras auxiliares
//Contenedor para guardar un vértice y el peso para llegar hasta este vértice
struct ContenedorDijkstra{
  ContenedorDijkstra(Vertice* v, int pesoAcumulado) 
    : vertice(v), pesoAcumulado(pesoAcumulado) {}
  ContenedorDijkstra(){}

  Vertice* vertice;  //Vértice de llegada
  int pesoAcumulado; //Peso total para llegar hasta al vértice de llegada
};

//=====  


/**
 * @brief 
 * Supone/Requiere: 
 *  Grafo con mas de 1 vértice
 * 
 * @param g 
 * @param v 
 * @return ListaIndexada<ContenedorDijkstra> 
 */
ListaIndexada<ContenedorDijkstra> Algoritmos::Dijkstra(Grafo* g, Vertice* v){
  Vertice* visitados[g->numVertices()];
  ListaIndexada<ContenedorDijkstra> lista; 
  ColaPrioridad<ContenedorDijkstra> cola;
  ContenedorDijkstra contenedor;
  int pesoDijkstra; //Peso de la arista entre 2 vértices, si no existe conexión entnces sera igual a 1000000(será usado como el infinito )
  lista.iniciar();

  Vertice* tmp = g->primerVertice();
  if(tmp == v) { tmp = g->siguienteVertice(tmp);}

  //Se hace el primer paso de Dijkstra
  for(int ii = 0; ii < g->numVertices()-1 ; ii++){

    pesoDijkstra = g->peso(tmp, v);
    if(pesoDijkstra== -1) { pesoDijkstra = 1000000; } //Asignando "infinito" si no existe conexión
    contenedor = ContenedorDijkstra(tmp, pesoDijkstra);

    cola.acolar(contenedor, contenedor.pesoAcumulado);

    tmp = g->siguienteVertice(tmp);
    if(tmp == v) {tmp = g->siguienteVertice(tmp);}
    //
    //ーーーーーーーーーーーーーーーーーーー  Añadir elementos a la lista
    //
  }

  Vertice* tmpAd; 
  visitados[g->numVertices()-1] = v; //Esto evita que cuando el "tmpAd" tenga que cambiar, no sea uno de los  vértices visitados o el "de salida"
  int pesoDijkstraAc; //Es el que acumula los pesos para llegar a los vértices que se llegan mediante otros vértices, los que no se pueden llegar con una sola arista
  //Ciclo que navega por cada vértice para encontrar el camino mas corto
  for(int ii = 0; ii < g->numVertices()-1 ; ii++){
    contenedor = cola.desacolar();
    visitados[ii] = contenedor.vertice;
    tmp = contenedor.vertice; //c
    tmpAd = g->primerVerticeAdyacente(tmp); //b
    if(tmpAd == v) { tmpAd = g->siguienteVerticeAdyacente(tmp, v); }
    pesoDijkstra = contenedor.pesoAcumulado;
    while(tmpAd != nullptr){
      pesoDijkstraAc = pesoDijkstra;
      pesoDijkstraAc += g->peso(tmp, tmpAd);
      contenedor = ContenedorDijkstra(tmpAd, pesoDijkstraAc);
      cola.acolar(contenedor, contenedor.pesoAcumulado);
      tmpAd = g->siguienteVerticeAdyacente(tmp, tmpAd);
      // if(tmp == v){ tmpAd = g->siguienteVerticeAdyacente(tmp, tmpAd); } BORRAR
      //=====  TODO:
      //Crear estructura de datos "Conjunto" por medio de hashmap
      //Lógica faltante seria ir añadiendo en la "lista" 「 cada desencolada 」 que reemplazara los vertices que vaya sacando, no va a repetir ningún vértice por el "conjunto" y las desencolafas serán 「 n-1 veces 」 
      //PERO después de cada añadida se debe VERIFICAR que ciertamente el elemento desencolado ofrece un 「 camino menor 」 que el que quequeque「 ya está 」
      }

    }
  }



  return lista;
}
