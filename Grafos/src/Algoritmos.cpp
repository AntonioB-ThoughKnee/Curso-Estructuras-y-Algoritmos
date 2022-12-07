
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

//Guardara individualmente una arista que se considera como obligatoria al calcular la  cota
struct ContenedorBERA{
  ContenedorBERA(int x, int y) 
    : fila(x), columna(y) {}
  ContenedorBERA(){}

  int fila;  
  int columna;
};

//=====  

//Función que devuelve el vértice según un "índice" de acuerdo a la relación 1 a 1
Vertice* conseguirVertice(Grafo* g, int indice){
  Vertice* v = g->primerVertice();
  for(int ii = 0; ii < g->numVertices() ; ii++){
    if(indice == ii) return v;
    v = g->siguienteVertice(v);
  }
  return nullptr;
}

static std::map<Vertice*, int> relacionVacia; //Usado para "limpiar" variables de este tipo para usarlas nuevamente 

/**
 * @brief Toma como argumento un grafo, el vértice deseado y una lista la cual sera modificada, en la misma se encontrará el resultado del algoritmo
 * Supone/Requiere: 
 *  Grafo con mas de 1 vértice
 * lista pasada como argumento N O inicializada
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
  int pesoDijkstra; //Peso de la arista entre 2 vértices, 
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
void ColoreoR(Vertice* v, Grafo* g){ //TODO BORRAR tercer parámetro
  if(v == nullptr) return;
  int coloresUsadosR = 6;
  int numVertice = relacion1a1[v];
  bool esFactible = true;


  for(int ii = 0; ii < NN ; ii++){ // "ii" serán los "colores"

    //===========================  Lógica para verificar si existe un vértice que sea adyacente a "v" Y ADEMÁS sea del color actual(ii)
    for(int iii = 0; iii < NN ; iii++){
      if(iii == numVertice) iii++;
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
        ColoreoR(g->siguienteVertice(v), g);
      }

      colorDeVerticeR[numVertice] = -1;
      CCColoreados[ii][numVertice] = false;
    }

    esFactible = true;
  }
}

int Algoritmos::Coloreo(Grafo* g){

  relacion1a1.clear();
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

  ColoreoR(g->primerVertice(), g);
  
  return coloresUsados;
}

//===========================  Variables globales para "Hamilton"
//#define NN 6 //Número de vértices en el grafo
// static std::map<Vertice*, int> relacion1a1; //Relación para traducir entre la matriz de adyacencia y las etiquetas
static std::map<Vertice*, bool> visitadosHam;
static int recorridoR[NN+1]; //el primer valor es el inicio y el que le sigue es el vértice adyacente elegido como camino
static int recorrido[NN+1]; //Recorrido solución
static int pesoDelrecorrido = 999999; // "infinito"
static int pesoDelrecorridoR = 0;
//=====  

void HamiltonR(Grafo* g, int profundidad, Vertice* vertProcedente){
  Vertice* tmpAd2;//Guarda el estado verdadero de tmpAd porque luego tmpAd se usa para verificar si se llegó a una solución
  Vertice* tmpAd;
  // int pesoDelrecorridoR = 0;
  bool esFactible = false;

  for(int ii = 0; ii < g->numVertices() ; ii++){ //Cada "ii" es un "vértice"

    tmpAd = conseguirVertice(g, ii );

    // if(tmpAd != nullptr){ //Es factible
    if(g->peso(vertProcedente, tmpAd) != -1 && !visitadosHam[tmpAd]){ //Es factible
      ;
      visitadosHam[vertProcedente] = true;
      visitadosHam[tmpAd] = true;
      recorridoR[profundidad+1] = relacion1a1[tmpAd];
      recorridoR[profundidad] = relacion1a1[vertProcedente];
      pesoDelrecorridoR += g->peso(vertProcedente, tmpAd);

      tmpAd2 = tmpAd;
      tmpAd = g->primerVerticeAdyacente(vertProcedente);

      //Verificando si se llegó a una solución
      while(profundidad == g->numVertices()-2 && tmpAd != nullptr){
        if(tmpAd == conseguirVertice(g, recorridoR[0])){ //Si se encontró solución...
          pesoDelrecorridoR += g->peso(tmpAd2, conseguirVertice(g, recorridoR[0]));
          if(pesoDelrecorrido > pesoDelrecorridoR){ //Verificar si es mejor que la anterior
            pesoDelrecorrido = pesoDelrecorridoR;
            for(int iii = 0; iii < g->numVertices()+1 ; iii++){
              recorrido[iii] = recorridoR[iii];
            }
          }
          pesoDelrecorridoR -= g->peso(tmpAd2, conseguirVertice(g, recorridoR[0]));

        }
        tmpAd = g->siguienteVerticeAdyacente(vertProcedente, tmpAd);
      }
      if(profundidad < g->numVertices()-1){
        HamiltonR(g, profundidad+1, tmpAd2);
      }

      pesoDelrecorridoR -= g->peso(vertProcedente,tmpAd2);
      visitadosHam[vertProcedente] = false;
      visitadosHam[tmpAd2] = false;

    }
    
  }
}

int Algoritmos::Hamilton(Grafo* g){
  relacion1a1.clear();
  visitadosHam.clear();
  Vertice* tmp = g->primerVertice();
  for(int ii = 0; ii < g->numVertices() ; ii++){
    visitadosHam.insert(pair<Vertice*, bool>(tmp, false));
    relacion1a1.insert(pair<Vertice*, int>(tmp, ii));
    tmp = g->siguienteVertice(tmp);
  }

  HamiltonR(g, 0, g->primerVertice());

  return pesoDelrecorrido;

}

//===========================  Variables globales para "HamiltonBERA" 
//#define NN 6 //Número de vértices en el grafo
// static std::map<Vertice*, int> relacion1a1; //Relación para traducir entre la matriz de adyacencia y las etiquetas
// static std::map<Vertice*, bool> visitadosHam;
// static int recorridoR[NN+1]; //el primer valor es el inicio y el que le sigue es el vértice adyacente elegido como camino
// static int recorrido[NN+1]; //Recorrido solución
// static int pesoDelrecorrido = 999999; // "infinito"
// static int pesoDelrecorridoR = 0;

static int matrizAd[NN][NN]; //matriz de adyacencia con pesos
static bool solucionEncontrada = false;
static bool obligatorioTomado[NN]; //Indica que el vértice "índice"(relación1a1) tiene asignado ya un vértice al cual dirigirse, o sea ya tiene arista definida
static std::map<int, ContenedorBERA> obligatorios; //Indica a que vértice en específico se dirige
//=====  

void HamiltonBERAR(Grafo* g, int profundidad, Vertice* vertProcedente){
  Vertice* tmpAd2;//Guarda el estado verdadero de tmpAd porque luego tmpAd se usa para verificar si se llegó a una solución
  Vertice* tmpAd;
  int x;
  int y;
  int minimoArista;
  ContenedorBERA contenedor;
  double cotaActual = 0;

  for(int ii = 0; ii < g->numVertices() ; ii++){ //Cada "ii" es un "vértice"

    tmpAd = conseguirVertice(g, ii );

    if(g->peso(vertProcedente, tmpAd) != -1 && !visitadosHam[tmpAd]){ //Es factible
      ;
      visitadosHam[vertProcedente] = true;
      visitadosHam[tmpAd] = true;
      recorridoR[profundidad+1] = relacion1a1[tmpAd];
      recorridoR[profundidad] = relacion1a1[vertProcedente];
      pesoDelrecorridoR += g->peso(vertProcedente, tmpAd);

      contenedor = ContenedorBERA(relacion1a1[vertProcedente], relacion1a1[tmpAd]);
      obligatorios[relacion1a1[vertProcedente]] = contenedor;
      obligatorioTomado[relacion1a1[vertProcedente]] = true;

      //===========================  Calculando cota

      for(int i2 = 0; i2 < NN ; i2++){
        ;
        if(!obligatorioTomado[i2]){
          minimoArista = matrizAd[i2][0];
          for(int i3 = 0; i3 < NN ; i3++){
            if(minimoArista > matrizAd[i2][i3] && matrizAd[i2][i3] != -1) minimoArista = matrizAd[i2][i3];
          }
          cotaActual += minimoArista;
        } else {
          x = obligatorios[i2].fila;
          y = obligatorios[i2].columna;
          cotaActual += matrizAd[x][y];

        }

      }

      //=====  

      tmpAd2 = tmpAd;
      tmpAd = g->primerVerticeAdyacente(vertProcedente);

      //Verificando si se llegó a una solución
      while(profundidad == g->numVertices()-2 && tmpAd != nullptr){
        if(tmpAd == conseguirVertice(g, recorridoR[0])){ //Si se encontró solución...
          pesoDelrecorridoR += g->peso(tmpAd2, conseguirVertice(g, recorridoR[0]));
          if(pesoDelrecorrido > pesoDelrecorridoR){ //Verificar si es mejor que la anterior
            pesoDelrecorrido = pesoDelrecorridoR;
            solucionEncontrada = true;
            for(int iii = 0; iii < g->numVertices()+1 ; iii++){
              recorrido[iii] = recorridoR[iii];
            }
          }
          pesoDelrecorridoR -= g->peso(tmpAd2, conseguirVertice(g, recorridoR[0]));

        }
        tmpAd = g->siguienteVerticeAdyacente(vertProcedente, tmpAd);
      }
      if(profundidad < g->numVertices()-1 && !solucionEncontrada ){
        HamiltonBERAR(g, profundidad+1, tmpAd2);
      }
      else if(solucionEncontrada && pesoDelrecorrido >= cotaActual ){
        HamiltonBERAR(g, profundidad+1, tmpAd2);  
      }
      pesoDelrecorridoR -= g->peso(vertProcedente,tmpAd2);
      visitadosHam[vertProcedente] = false;
      visitadosHam[tmpAd2] = false;

      obligatorioTomado[relacion1a1[vertProcedente]] = false;


    }
    
    cotaActual = 0;
  }
}

/**
 * @brief 
 * Especificaciones: 
 * Se hace un árbol n-ario, donde cada "nodo" calcula su cota con solo el recorrido que se vaya haciendo
 * 
 * @param g 
 */
int Algoritmos::HamiltonBERA(Grafo* g){
  relacion1a1.clear();
  visitadosHam.clear();
  Vertice* tmp = g->primerVertice();
  Vertice* tmpAd = g->primerVerticeAdyacente(tmp);
  ContenedorBERA contenedor = ContenedorBERA(0, 0);
  for(int ii = 0; ii < g->numVertices() ; ii++){
    visitadosHam.insert(pair<Vertice*, bool>(tmp, false));
    relacion1a1.insert(pair<Vertice*, int>(tmp, ii));
    obligatorios.insert(pair<int, ContenedorBERA>(ii, contenedor));
    tmp = g->siguienteVertice(tmp);
  }

  //===========================  Armando la "matriz de adyacencia"

  //Ciclo para limpiar la matriz
  for(int ii = 0; ii < NN ; ii++){
    for(int iii = 0; iii < NN ; iii++){
       matrizAd[ii][iii] = -1;
    }
  }

  tmp = g->primerVertice();
  for(int ii = 0; ii < NN ; ii++){
    for(int iii = 0; iii < NN ; iii++){
      if(tmpAd != nullptr){
         matrizAd[ii][relacion1a1[tmpAd]] = g->peso(tmp, tmpAd);
        tmpAd = g->siguienteVerticeAdyacente(tmp, tmpAd);
      }
    }

    tmp = g->siguienteVertice(tmp);
    if(tmp != nullptr) tmpAd = g->primerVerticeAdyacente(tmp);
  }
  //=====  

  HamiltonBERAR(g, 0, g->primerVertice());
  return pesoDelrecorrido;
}
