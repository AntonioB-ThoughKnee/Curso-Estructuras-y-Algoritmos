
#include "../include/Algoritmos.hpp"

using namespace std;

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
 * @brief Toma como argumento un grafo, el vértice deseado y una lista la cual sera modificada, en la misma se encontrará el resultado del algoritmo
 * Supone/Requiere: 
 *  Grafo con mas de 1 vértice
 * lista pasada como argumento NO inicializada
 * IMPORTANTE: Debe probarse que el algoritmo funcione con varios nodos y pocos aristas(O sea verificar que no ocurra ningún error con la cola de prioridad de desencolar cuando la cola esta vacía)
 * 
 * @param g 
 * @param v 
 * @return ListaIndexada<ContenedorDijkstra> 
 */
void Algoritmos::Dijkstra(Grafo* g, Vertice* v, ListaIndexada<ContenedorDijkstra>* lista){
  map<Vertice*, bool> visitados; 
  ColaPrioridad<ContenedorDijkstra> cola;
  ContenedorDijkstra contenedor;
  int pesoDijkstra; //Peso de la arista entre 2 vértices, si no existe conexión entnces sera igual a 1000000(será usado como el infinito )
  lista->iniciar();

  //===========================  Iniciando valores en el mapa para los "visitados" y la lista resultado del algoritmo
  Vertice* tmp = g->primerVertice();
  contenedor = ContenedorDijkstra(tmp, -1);
  for(int ii = 0; ii < g->numVertices() ; ii++){
    visitados.insert(pair<Vertice*, bool>(tmp, false));
    lista->insertar(contenedor, lista->numElem()+1);
    tmp = g->siguienteVertice(tmp);
    contenedor = ContenedorDijkstra(tmp, -1);
  }

  //===========================  Se hace el primer paso de Dijkstra
  tmp = g->primerVertice();
  int offset = 0; //Existe únicamente para mantener el orden en la lista indexadas
  if(tmp == v) { tmp = g->siguienteVertice(tmp); offset++;}
  for(int ii = 0; ii < g->numVertices()-1 ; ii++){

    pesoDijkstra = g->peso(tmp, v);
    if(pesoDijkstra == -1) { pesoDijkstra = 1000000; } //Asignando "infinito" si no existe conexión
    contenedor = ContenedorDijkstra(tmp, pesoDijkstra);
    lista->modificar(contenedor, ii+1+offset);

    cola.acolar(contenedor, contenedor.pesoAcumulado);

    tmp = g->siguienteVertice(tmp);
    if(tmp == v) {tmp = g->siguienteVertice(tmp); offset++;}
  }

  //===========================  Ciclo que navega por cada vértice para encontrar el camino mas corto
  Vertice* tmpAd; //Usado para navegar por losvértices adyacentes a todos los vértices excepto el "v" 
  visitados[v] = true; 
  int pesoDijkstraAc; //Es el que acumula los pesos para llegar a los vértices que se llegan mediante otros vértices, los que no se pueden llegar con una sola arista
  for(int ii = 0; ii < g->numVertices()-1 ; ii++){
    contenedor = cola.desacolar();
    if( !(visitados[contenedor.vertice]) ){ //Verificando que el vértice por el cual navegaremos sus vértices adyacentes no se haya navegaado ya

      //Ciclo que busca en la lista el contenedor que actualizaremos
      for(int iii = 1; iii <= lista->numElem() ; iii++){
        if(lista->recuperar(iii).vertice == contenedor.vertice){
          lista->modificar(contenedor, iii);
          iii = lista->numElem()+1;
        }
      }

      visitados[contenedor.vertice] = true;
      tmp = contenedor.vertice; 
      tmpAd = g->primerVerticeAdyacente(tmp); 
      pesoDijkstra = contenedor.pesoAcumulado;

      // Navegando los vértices adyacentes
      while(tmpAd != nullptr){
        // Verificar si la siguiente arista mas pequeña no conduce a un vértice ya visitado
        if( !(visitados[tmpAd]) ){
          pesoDijkstraAc = pesoDijkstra;
          pesoDijkstraAc += g->peso(tmp, tmpAd);
          contenedor = ContenedorDijkstra(tmpAd, pesoDijkstraAc);
          cola.acolar(contenedor, contenedor.pesoAcumulado);
          tmpAd = g->siguienteVerticeAdyacente(tmp, tmpAd);
        } else {
          tmpAd = g->siguienteVerticeAdyacente(tmp, tmpAd);
        }
      }
    } else{
      ii--;
    }
    
  }



}
