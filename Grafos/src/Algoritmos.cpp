
#include "../include/Algoritmos.hpp"
#include <cstring>
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

  //===========================  Iniciando valores en el mapa para los "visitados" y la lista resultado del algoritmo y Se hace el primer paso de Dijkstra
  Vertice* tmp = g->primerVertice();
  contenedor = ContenedorDijkstra(tmp, -1);
  for(int ii = 0; ii < g->numVertices() ; ii++){
    visitados.insert(pair<Vertice*, bool>(tmp, false));

    pesoDijkstra = g->peso(tmp, v);
    if(pesoDijkstra == -1) { pesoDijkstra = -1; } //Asignando "infinito" si no existe conexión
    contenedor = ContenedorDijkstra(tmp, pesoDijkstra);
    lista->insertar(contenedor, lista->numElem()+1);
    cola.acolar(contenedor, contenedor.pesoAcumulado);
    tmp = g->siguienteVertice(tmp);
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

//===========================  Variables globales para "Coloreo"
#define NN 6 //Número de vértices en el grafo
static int coloresUsados = NN; //Usado para comparar las soluciones
static bool CCAdyacentes[NN][NN]; //Lo mismo que una matriz de adyacencia
static bool CCColoreados[NN][NN]; //La fila es un "color" y cada columna representa el "número de vértice"
static int colorDeVerticeR[NN]; //int para mostrar de que coolor es cada vértice dentro del algoritmo
static int colorDeVertice[NN]; //int para mostrar de que coolor es cada vértice
static std::map<Vertice*, int> relacion1a1; //Relación para traducir entre la matriz de adyacencia y las etiquetas
//=====  
template <typename Pmatrix>// This is the easiest way to make a function with templates to pass as an argument a matrix
void ColoreoR(Vertice* v, Grafo* g, Pmatrix& CCColoreadosP){
  if(v == nullptr) return;
  int coloresUsadosR = 6;
  int numVertice = relacion1a1[v];
  bool esFactible = true;
  bool CCColoreadosR[NN][NN];

  for(int ii = 0; ii < NN ; ii++){
    for(int iii = 0; iii < NN ; iii++){
      CCColoreadosR[NN][NN] = CCColoreadosP[NN][NN]; // Hay que hacer un CCColores local para mantener el estado
    }
  }

  for(int ii = 0; ii < NN ; ii++){ // "ii" serán los "colores"

    //===========================  Lógica para verificar si existe un vértice que sea adyacente a "v" Y ADEMÁS sea del color actual(ii)
    for(int iii = 0; iii < NN ; iii++){
      if(iii == numVertice) iii++;
      // if(CCAdyacentes[numVertice][iii] && CCColoreados[ii][iii] && ii < NN){
      //   ii++;
      //   iii = 0;
      // }
      if(CCAdyacentes[numVertice][iii] && CCColoreados[ii][iii]){
        esFactible = false;
        iii = NN;
      }
    }
    //=====  
    if(esFactible){
      colorDeVerticeR[numVertice] = ii;
      CCColoreados[ii][numVertice] = true;
      coloresUsadosR++;
    

      //Calculando los colores usados
      //Se inicia en el final porque se deduce que ese sera el número máximo de colores usados
      for(int iii = NN; iii >= 0 ; iii--){
        for(int iv = 0; iv < NN ; iv++){
          if(CCColoreados[iii][iv]){
            iv = NN;
            coloresUsadosR = iii;
            coloresUsadosR++;
            iii = -1;
          }
        }
      }
      
      if(g->siguienteVertice(v) == nullptr){

        if(coloresUsados > coloresUsadosR){
          coloresUsados = coloresUsadosR;
          for(int iii = 0; iii < NN ; iii++){
            colorDeVertice[iii] = colorDeVerticeR[iii]; 
          }
        }
      } else {
        ColoreoR(g->siguienteVertice(v), g, CCColoreados);
      }

      colorDeVerticeR[numVertice] = -1;
      CCColoreados[ii][numVertice] = false;
    }

    esFactible = true;
  }
}

void Algoritmos::Coloreo(Grafo* g){

  //===========================  Armando relación 1a1
  Vertice* tmp = g->primerVertice();
  Vertice* tmpAd = g->primerVerticeAdyacente(tmp);
  for(int ii = 0; ii < NN ; ii++){
    relacion1a1.insert(pair<Vertice*, int>(tmp, ii));
    tmp = g->siguienteVertice(tmp);
  }
  //=====  

  //===========================  Armando los "Conjuntos de conjuntos"
  tmp = g->primerVertice();
  for(int ii = 0; ii < NN ; ii++){
    for(int iii = 0; iii < NN ; iii++){
      CCColoreados[ii][iii] = false;
      if(tmpAd != nullptr){
        CCAdyacentes[ii][relacion1a1[tmpAd]] = true;
        tmpAd = g->siguienteVerticeAdyacente(tmp, tmpAd);
      }

    }

    tmp = g->siguienteVertice(tmp);
    if(tmp != nullptr) tmpAd = g->primerVerticeAdyacente(tmp);
  }
  //=====  

  //Coloreando
  //Se pasa como "coloresUsadosR" 1 porque el algoritmo al principio piensa que todos los vértices estén pintados de un color ya
  ColoreoR(g->primerVertice(), g, CCColoreados);
  
  return;
}


