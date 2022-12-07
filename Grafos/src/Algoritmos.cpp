
#include "../include/Algoritmos.hpp"
#include <cstring>
using namespace std;

bool existePar(vector<pair<Vertice*, Vertice*>> vec, Vertice* v1, Vertice* v2);
int encontrarPosCCDeVertice(vector<vector<Vertice*>> CC, Vertice* vert);
vector<vector<Vertice*>> unir(vector<vector<Vertice*>> CC, int indice1, int indice2);

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

// ----------------------------------------------------------------------------
void Algoritmos::Prim(Grafo* g) {
  // Declaraciones e inicalizaciones.
  map<int, Vertice*> identificador;
  int id = 0;
  vector<vector<int>> G;
  G.resize(g->numVertices());
  for (int i = 0; i < G.size(); ++i) {
    G[i].resize(g->numVertices());
    fill(G[i].begin(), G[i].end(), 99999);
  }
  // Llenar map
  Vertice* v = g->primerVertice();
  while (v != nullptr) {
    identificador.insert(pair<int, Vertice*>(id, v));
    v = g->siguienteVertice(v);
    id++;
  }
  // Llenar matriz.
  map<int, Vertice*>::iterator itrI;
  map<int, Vertice*>::iterator itrJ;
  for (itrI = identificador.begin(); itrI != identificador.end(); ++itrI) {
    for (itrJ = identificador.begin(); itrJ != identificador.end(); ++itrJ) {
      Vertice* v1 = itrI->second;
      Vertice* v2 = itrJ->second;
      int peso = g->peso(v1, v2);
      if (peso != -1) {
        G[itrI->first][itrJ->first] = peso;
      } else {
        G[itrI->first][itrJ->first] = 99999;
      }
    }
  }

  // Una vez llenada la matriz, se hace el recorrido de prim.
  int no_edge;  // number of edge

  // create a array to track selected vertex
  // selected will become true otherwise false
  int selected[g->numVertices()];

  // set selected false initially
  memset(selected, false, sizeof(selected));

  // set number of edge to 0
  no_edge = 0;

  // the number of egde in minimum spanning tree will be
  // always less than (V -1), where V is number of vertices in
  //graph

  // choose 0th vertex and make it true
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  // print for edge and weight
  cout << "Edge"
     << " : "
     << "Weight";
  cout << endl;
  while (no_edge < g->numVertices() - 1) {
    //For every vertex in the set S, find the all adjacent vertices
    // , calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    //choose another vertex nearest to selected vertex  at step 1.

    int min = 99999;
    x = 0;
    y = 0;

    for (int i = 0; i < g->numVertices(); i++) {
      if (selected[i]) {
        for (int j = 0; j < g->numVertices(); j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << G[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
  }
}

void Algoritmos::Kruskal(Grafo* g) {
  // Declaraciones e inicializaciones
  priority_queue<pair<int, int>, std::vector<pair<int,int>>,
    std::greater<pair<int,int>>> queue; // APO(peso, keyMap)
  // map<int, pair<Vertice*, Vertice*>> mapa; // map(key, (v, va))
  vector<pair<Vertice*, Vertice*>> agregados;
  vector<vector<Vertice*>> CC;
  CC.resize(g->numVertices());
  
  // Recorrido de Kruskal
  Vertice* v = g->primerVertice();
  int indiceCC = 0;
  int indiceAgregados = 0;
  while (v != nullptr) {
    CC[indiceCC].push_back(v);
    indiceCC++;

    Vertice* va = g->primerVerticeAdyacente(v);
    while (va != nullptr) {
      if (!existePar(agregados, v, va)) {
        queue.push(pair<int, int>(g->peso(v, va), indiceAgregados));
        agregados.push_back(pair<Vertice*, Vertice*>(v, va));
        indiceAgregados++;
      }
      va = g->siguienteVerticeAdyacente(v, va);
    }
    v = g->siguienteVertice(v);
  }

  int n = g->numVertices();
  int aristasElegidas = 0;
  while (aristasElegidas < (n-1)) {
    pair<int, int> parApo = queue.top(); // peso, key
    queue.pop();
    pair<Vertice*, Vertice*> arista = agregados[parApo.second];
    int ident1 = encontrarPosCCDeVertice(CC, arista.first);
    int ident2 = encontrarPosCCDeVertice(CC, arista.second);
    if ((ident1 != -1 && ident2 != -1) && (ident1 != ident2)) {
      cout << g->etiqueta(arista.first) << " - " << g->etiqueta(arista.second) << std::endl;
      aristasElegidas++;
      CC = unir(CC, ident1, ident2);
    }
  }

}

bool existePar(vector<pair<Vertice*, Vertice*>> vec, Vertice* v1, Vertice* v2) {
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i].first == v1 && vec[i].second == v2) {
      return true;
    } else if ((vec[i].first == v2 && vec[i].second == v1)) {
      return true;
    }
  }
  return false;
}

int encontrarPosCCDeVertice(vector<vector<Vertice*>> CC, Vertice* vert) {
  for (int i = 0; i < CC.size(); i++) {
    for (int m = 0; m < CC[i].size(); m++) {
      if (CC[i][m] == vert) {
        return i;
      }
    }
  }
  return -1;
}

vector<vector<Vertice*>> unir(vector<vector<Vertice*>> CC, int indice1, int indice2) {
  CC[indice1].insert( CC[indice1].end(), CC[indice2].begin(), CC[indice2].end());
  CC.erase( next( begin( CC ), indice2 ) );
  return CC;
}