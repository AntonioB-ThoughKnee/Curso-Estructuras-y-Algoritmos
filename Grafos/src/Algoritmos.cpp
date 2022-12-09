
#include "../include/Algoritmos.hpp"
#include <cstring>
#include <iostream>
using namespace std;

bool existePar(vector<pair<Vertice*, Vertice*>> vec, Vertice* v1, Vertice* v2);
int encontrarPosCCDeVertice(vector<vector<Vertice*>> CC, Vertice* vert);
vector<vector<Vertice*>> unir(vector<vector<Vertice*>> CC, int indice1, int indice2);

//===========================  Estructuras auxiliares
//Contenedor para guardar un vértice y el peso para llegar hasta este vértice


// Clase necesaria para usar una cola de prioridad en Dijkstra
class Comparador{

	public:
	int operator()(const ContenedorDijkstra& c1,const ContenedorDijkstra& c2 ){
		return c1.pesoAcumulado > c2.pesoAcumulado;
	}
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

void Algoritmos::Dijkstra(Grafo* g, Vertice* v, ListaIndexada<ContenedorDijkstra>* lista){
  map<Vertice*, bool> visitados; 
	priority_queue<ContenedorDijkstra, vector<ContenedorDijkstra>, Comparador> cola;
  ContenedorDijkstra contenedor;
  int pesoDijkstra; //Peso de la arista entre 2 vértices, 
  lista->iniciar();

  //===========================  Iniciando valores en el mapa para los "visitados" y la lista resultado del algoritmo y Se hace el primer paso de Dijkstra
  Vertice* tmp = g->primerVertice();
  contenedor = ContenedorDijkstra(tmp, -1);
  for(int ii = 0; ii < g->numVertices() ; ii++){
    visitados.insert(pair<Vertice*, bool>(tmp, false));

    pesoDijkstra = g->peso(tmp, v);
    if(pesoDijkstra == -1) { pesoDijkstra = 99999; } //Asignando "infinito" si no existe conexión
    contenedor = ContenedorDijkstra(tmp, pesoDijkstra);
    lista->insertar(contenedor, lista->numElem()+1);
    cola.push(contenedor);
    tmp = g->siguienteVertice(tmp);
  }

  //===========================  Ciclo que navega por cada vértice para encontrar el camino mas corto
  Vertice* tmpAd; //Usado para navegar por losvértices adyacentes a todos los vértices excepto el "v" 
  visitados[v] = true; 
  int pesoDijkstraAc; //Es el que acumula los pesos para llegar a los vértices que se llegan mediante otros vértices, los que no se pueden llegar con una sola arista
  for(int ii = 0; ii < g->numVertices()-1 ; ii++){
    contenedor = cola.top(); cola.pop();
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
          cola.push(contenedor);
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

void Algoritmos::Floyd(Grafo* g,int**& matrizPesos,Vertice***& matrizVertices,Relacion1A1* relacion1a1){
  Vertice * v= g->primerVertice();
  int contador =0;
  // Se carga la relacion 1 a 1 con los vertices 
  // y los indices a los que corresponden.
  while (v!=nullptr)
  {
    relacion1a1->insertar(v,contador++);
    v=g->siguienteVertice(v);
  }
  v=g->primerVertice();
  // Se cargan las matrices con los valores 
  // iniciales.
  for(int i =0;i<g->numVertices();++i){
    matrizPesos[i]=new int[g->numVertices()];
    matrizVertices[i]=new Vertice*[g->numVertices()];
    for(int j=0;j<g->numVertices();++j){
      matrizPesos[i][j]=99999;
      matrizVertices[i][j]=nullptr;
    }
  }
  // Se carga la matriz de pesos con los 
  // pesos del grafo. 
  v=g->primerVertice();
  int numero= relacion1a1->getDerecha(v);
  while (v!=nullptr){
    Vertice * va=g->primerVerticeAdyacente(v);
    while (va!=nullptr){
      int fila = relacion1a1->getDerecha(v);
      int columna = relacion1a1->getDerecha(va);
      matrizPesos[fila][columna]=g->peso(v,va);
      va=g->siguienteVerticeAdyacente(v,va);
    }
    v=g->siguienteVertice(v);
  }
  //Se corre el algoritmo de Floyd
  for(int pivote =0;pivote<g->numVertices();++pivote){

    for(int fila=0;fila<g->numVertices();++fila){
      if(fila!=pivote && matrizPesos[fila][pivote]<99999){
        for(int columna=0;columna<g->numVertices();++columna){
          int valorActual=matrizPesos[fila][columna];
          int temp1 = matrizPesos[fila][pivote];
          int temp2 = matrizPesos[pivote][columna];
          int valorNuevo=matrizPesos[fila][pivote]+matrizPesos[pivote][columna];
          if (fila!=columna && matrizPesos[fila][columna]>(matrizPesos[fila][pivote]+matrizPesos[pivote][columna])){
            matrizPesos[fila][columna]=valorNuevo;
            matrizVertices[fila][columna]=relacion1a1->getIzquierda(pivote);
          }
        }
      }
    }
  }
}


void Algoritmos::NDijkstra(Grafo* g,ListaIndexada<ContenedorDijkstra>* lista){
  Vertice * v= g->primerVertice();
  int contador =0;
  // Se carga la relacion 1 a 1 con los vertices 
  // y los indices a los que corresponden.
  while (v!=nullptr)
  {
    Algoritmos::Dijkstra(g,v,&(lista[contador++]));
    v=g->siguienteVertice(v);
  }
};

//===========================  Variables globales para "Coloreo"
static int coloresUsados; //Usado para comparar las soluciones
typedef std::vector<std::vector<bool>> CC;
typedef std::vector<bool> Fila;
static CC CCAdyacentes; //Lo mismo que una matriz de adyacencia
static CC CCColoreados; //La fila es un "color" y cada columna representa el "número de vértice"
static int* colorDeVerticeR; //int para mostrar de que coolor es cada vértice dentro del algoritmo
static int* colorDeVertice; //int para mostrar de que coolor es cada vértice
static std::map<Vertice*, int> relacion1a1; //Relación para traducir entre la matriz de adyacencia y las etiquetas
//=====  
void ColoreoR(Vertice* v, Grafo* g){
  if(v == nullptr) return;
  int coloresUsadosR = 6;
  int numVertice = relacion1a1[v];
  bool esFactible = true;


  for(int ii = 0; ii < g->numVertices() ; ii++){ // "ii" serán los "colores"

    //===========================  Lógica para verificar si existe un vértice que sea adyacente a "v" Y ADEMÁS sea del color actual(ii)
    for(int iii = 0; iii < g->numVertices() ; iii++){
      if(iii == numVertice) iii++;
      if(CCAdyacentes[numVertice][iii] && CCColoreados[ii][iii]){
        esFactible = false;
        iii = g->numVertices();
      }
    }
    //=====  
    if(esFactible){
      colorDeVerticeR[numVertice] = ii;
      CCColoreados[ii][numVertice] = true;
      coloresUsadosR++;
    

      //Calculando los colores usados
      //Se inicia en el final porque se deduce que ese sera el número máximo de colores usados
      for(int iii = g->numVertices()-1; iii >= 0 ; iii--){
        for(int iv = 0; iv < g->numVertices() ; iv++){
          if(CCColoreados[iii][iv]){
            iv = g->numVertices();
            coloresUsadosR = iii;
            coloresUsadosR++;
            iii = -1;
          }
        }
      }
      
      if(g->siguienteVertice(v) == nullptr){

        if(coloresUsados > coloresUsadosR){
          coloresUsados = coloresUsadosR;
          for(int iii = 0; iii < g->numVertices() ; iii++){
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

  colorDeVertice  = new int[g->numVertices()];
  colorDeVerticeR = new int[g->numVertices()];
  coloresUsados = g->numVertices();
  //===========================  Armando relación 1a1
  Vertice* tmp = g->primerVertice();
  Vertice* tmpAd = g->primerVerticeAdyacente(tmp);
  for(int ii = 0; ii < g->numVertices() ; ii++){
    relacion1a1.insert(pair<Vertice*, int>(tmp, ii));
    tmp = g->siguienteVertice(tmp);
  }
  //=====  

  //===========================  Armando los "Conjuntos de conjuntos"
  Fila fila(g->numVertices());
  for(int ii = 0; ii < g->numVertices() ; ii++){
    CCAdyacentes.push_back(fila);
    CCColoreados.push_back(fila);
  }

  tmp = g->primerVertice();
  for(int ii = 0; ii < g->numVertices() ; ii++){
    for(int iii = 0; iii < g->numVertices() ; iii++){
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

  delete colorDeVertice;
  delete colorDeVerticeR;
  for(int ii = 0; ii < g->numVertices() ; ii++){
    CCAdyacentes[ii].clear();
    CCColoreados[ii].clear();
  }
  CCAdyacentes.clear();
  CCColoreados.clear();
  relacion1a1.clear();
  
  return coloresUsados;
}

//===========================  Variables globales para "Hamilton"
// static std::map<Vertice*, int> relacion1a1; //Relación para traducir entre la matriz de adyacencia y las etiquetas
static std::map<Vertice*, bool> visitadosHam;
static int* recorridoR; //el primer valor es el inicio y el que le sigue es el vértice adyacente elegido como camino
static int* recorrido; //Recorrido solución
static int pesoDelrecorrido; // "infinito"
static int pesoDelrecorridoR = 0;
static bool solucionAlcanzada;
//=====  

void HamiltonR(Grafo* g, int profundidad, Vertice* vertProcedente){
  Vertice* tmpAd2;//Guarda el estado verdadero de tmpAd porque luego tmpAd se usa para verificar si se llegó a una solución
  Vertice* tmpAd;

  for(int ii = 0; ii < g->numVertices() ; ii++){ //Cada "ii" es un "vértice"

    tmpAd = conseguirVertice(g, ii );
    if(tmpAd == conseguirVertice(g, recorridoR[0]) 
    && profundidad >= g->numVertices()-1
    && g->peso(vertProcedente, tmpAd) != -1 ) solucionAlcanzada = true;

    if(g->peso(vertProcedente, tmpAd) != -1 && (!visitadosHam[tmpAd] || solucionAlcanzada)){ //Es factible
      visitadosHam[vertProcedente] = true;
      visitadosHam[tmpAd] = true;
      recorridoR[profundidad+1] = relacion1a1[tmpAd];
      recorridoR[profundidad] = relacion1a1[vertProcedente];
      pesoDelrecorridoR += g->peso(vertProcedente, tmpAd);

      tmpAd2 = tmpAd;
      tmpAd = g->primerVerticeAdyacente(vertProcedente);


      //Verificando si se llegó a una solución
      while(profundidad >= g->numVertices()-1 && tmpAd != nullptr){

        if(solucionAlcanzada){ //Si se encontró solución...
          solucionAlcanzada = false;
          if(pesoDelrecorrido > pesoDelrecorridoR){ //Verificar si es mejor que la anterior
            pesoDelrecorrido = pesoDelrecorridoR;
            for(int iii = 0; iii < g->numVertices()+1 ; iii++){
              recorrido[iii] = recorridoR[iii];
            }
          }

        }
        tmpAd = g->siguienteVerticeAdyacente(vertProcedente, tmpAd);
      }
      if(profundidad < g->numVertices()-1){
        HamiltonR(g, profundidad+1, tmpAd2);
      }

      pesoDelrecorridoR -= g->peso(vertProcedente,tmpAd2);
      visitadosHam[vertProcedente] = false;
      if(relacion1a1[tmpAd2] != recorrido[0]) visitadosHam[tmpAd2] = false;

    }
    solucionAlcanzada = false;
    
  }
}

int Algoritmos::Hamilton(Grafo* g){
  pesoDelrecorridoR = 0;
  pesoDelrecorrido = 99999;
  solucionAlcanzada = false;
  recorrido = new int[g->numVertices()+1];
  recorridoR = new int[g->numVertices()+1];
  Vertice* tmp = g->primerVertice();
  for(int ii = 0; ii < g->numVertices() ; ii++){
    visitadosHam.insert(pair<Vertice*, bool>(tmp, false));
    relacion1a1.insert(pair<Vertice*, int>(tmp, ii));
    tmp = g->siguienteVertice(tmp);
  }

  HamiltonR(g, 0, g->primerVertice());

  relacion1a1.clear();
  visitadosHam.clear();
  delete recorridoR;
  delete recorrido;

  return pesoDelrecorrido;
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


// ----------------------------------------------------------------------------
std::vector<std::pair<Vertice*, Vertice*>> Algoritmos::Prim(Grafo* g) {
  // Declaraciones e inicalizaciones.
  map<int, Vertice*> identificador;
  int id = 0;
  vector<vector<int>> G;
  G.resize(g->numVertices());
  for (int i = 0; i < G.size(); ++i) {
    G[i].resize(g->numVertices());
    fill(G[i].begin(), G[i].end(), 99999);
  }
  // Vector de devolucion
  vector<pair<Vertice*, Vertice*>> toRet;
  toRet.resize(g->numVertices() - 1);
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
  int numAristaPuesta;  

  int verticesSeleccionados[g->numVertices()];

  /*
    Ningun vertice ha sido seleccionado, por lo que se deben poner todos en los
    valores pertenecientes al arreglo en 0, se puede realizar mediante for pero
    con memset queda mas simple el codigo
  */
  memset(verticesSeleccionados, 0, sizeof(verticesSeleccionados));

  /*
    Inicialmente no se han puesto aristas.
  */
  numAristaPuesta = 0;

  /*
    Similarmente a como fue realizado en clase, se selecciona el primer vertice
    para que el algoritmo quede mejor definido en terminos de simplicidad.
  */
  verticesSeleccionados[0] = true;

  // int menorFila;  
  // int menorColumna;  
  cout << "Aristas resultantes del recorrido de Prim: " << endl;
  cout << endl;
  while (numAristaPuesta < g->numVertices() - 1) {
    int minimoEncontradoActual = 99999;
    int menorFila = 0;
    int menorColumna = 0;

    for (int i = 0; i < g->numVertices(); i++) {
      if (verticesSeleccionados[i]) {
        for (int j = 0; j < g->numVertices(); j++) {
          if ((!verticesSeleccionados[j]) && (G[i][j] != 0)) {  
            if (minimoEncontradoActual > G[i][j]) {
              minimoEncontradoActual = G[i][j];
              menorFila = i;
              menorColumna = j;
            }
          }
        }
      }
    }
    cout << g->etiqueta(identificador.find(menorFila)->second) << " - "
      << g->etiqueta(identificador.find(menorColumna)->second);
    cout << endl;
    verticesSeleccionados[menorColumna] = true;
    numAristaPuesta++;
    toRet.push_back(pair<Vertice*, Vertice*>(identificador.find(menorFila)->second,
      identificador.find(menorColumna)->second));
  }
  return toRet;
}

std::vector<std::pair<Vertice*, Vertice*>> Algoritmos::Kruskal(Grafo* g) {
  // Declaraciones e inicializaciones
  // priority_queue<pair<int, int>, std::vector<pair<int,int>>,
  //   std::greater<pair<int,int>>>* queue= new priority_queue<pair<int, int>, std::vector<pair<int,int>>,
  //   std::greater<pair<int,int>>>; // APO(peso, keyMap)
  priority_queue<pair<int, int>, std::vector<pair<int,int>>,
    std::greater<pair<int,int>>> queue; // APO(peso, keyMap)
  // map<int, pair<Vertice*, Vertice*>> mapa; // map(key, (v, va))
  vector<pair<Vertice*, Vertice*>> agregados;
  vector<vector<Vertice*>> CC;
  CC.resize(g->numVertices());
  // Vector de devolucion
  std::vector<std::pair<Vertice*, Vertice*>> toRet;
  toRet.resize(g->numVertices());

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
  cout << "Resultado del recorrido mediante Kruskal" << endl;
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
      toRet.push_back(pair<Vertice*, Vertice*>(arista.first, arista.second));
    }
  }
  // delete queue;
  return toRet;
}


//===========================  Variables globales para "HamiltonBERA" 
// static std::map<Vertice*, int> relacion1a1; //Relación para traducir entre la matriz de adyacencia y las etiquetas
// static std::map<Vertice*, bool> visitadosHam;
// static int* recorridoR; //el primer valor es el inicio y el que le sigue es el vértice adyacente elegido como camino
// static int* recorrido; //Recorrido solución

typedef std::vector<std::vector<int>> CCint;
CCint matrizAd; //matriz de adyacencia con pesos
typedef std::vector<int> Filaint;
static bool solucionEncontrada;
static bool* obligatorioTomado; //Indica que el vértice "índice"(relación1a1) tiene asignado ya un vértice al cual dirigirse, o sea ya tiene arista definida
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
    if(tmpAd == conseguirVertice(g, recorridoR[0]) 
    && profundidad >= g->numVertices()-1
    && g->peso(vertProcedente, tmpAd) != -1 ) solucionAlcanzada = true;

    if(g->peso(vertProcedente, tmpAd) != -1 && (!visitadosHam[tmpAd] || solucionAlcanzada)){ //Es factible
      visitadosHam[vertProcedente] = true;
      visitadosHam[tmpAd] = true;
      recorridoR[profundidad+1] = relacion1a1[tmpAd];
      recorridoR[profundidad] = relacion1a1[vertProcedente];
      pesoDelrecorridoR += g->peso(vertProcedente, tmpAd);

      contenedor = ContenedorBERA(relacion1a1[vertProcedente], relacion1a1[tmpAd]);
      obligatorios[relacion1a1[vertProcedente]] = contenedor;
      obligatorioTomado[relacion1a1[vertProcedente]] = true;

      //===========================  Calculando cota
      for(int i2 = 0; i2 < g->numVertices() ; i2++){
        if(!obligatorioTomado[i2]){
          minimoArista = 99999;
          for(int i3 = 0; i3 < g->numVertices() ; i3++){
            if(minimoArista > matrizAd[i2][i3] && matrizAd[i2][i3] != -1) minimoArista = matrizAd[i2][i3];
          }
          cotaActual += minimoArista;
        } else {
          x = obligatorios[i2].fila;
          y = obligatorios[i2].columna;
          cotaActual += matrizAd[x][y];

        }
      }
      cotaActual += minimoArista;
      //=====  

      tmpAd2 = tmpAd;
      tmpAd = g->primerVerticeAdyacente(vertProcedente);

      //Verificando si se llegó a una solución
      while(profundidad >= g->numVertices()-1 && tmpAd != nullptr){
        if(solucionAlcanzada){ //Si se encontró solución...
          solucionAlcanzada = false;
          if(pesoDelrecorrido > pesoDelrecorridoR){ //Verificar si es mejor que la anterior
            pesoDelrecorrido = pesoDelrecorridoR;
            solucionEncontrada = true;
            for(int iii = 0; iii < g->numVertices()+1 ; iii++){
              recorrido[iii] = recorridoR[iii];
            }
          }

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
      if(relacion1a1[tmpAd2] != recorrido[0]) visitadosHam[tmpAd2] = false;

      obligatorioTomado[relacion1a1[vertProcedente]] = false;


    }
    
    cotaActual = 0;
  }
}

int Algoritmos::HamiltonBERA(Grafo* g){
  pesoDelrecorridoR = 0;
  pesoDelrecorrido = 999999; // "infinito"
  solucionAlcanzada = false;
  obligatorioTomado = new bool[g->numVertices()];
  recorrido = new int[g->numVertices()+1];
  recorridoR = new int[g->numVertices()+1];
  solucionEncontrada = false;

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

  Filaint fila(g->numVertices());

  //Ciclo para limpiar la matriz
  for(int ii = 0; ii < g->numVertices() ; ii++){
    matrizAd.push_back(fila);
    for(int iii = 0; iii < g->numVertices() ; iii++){
      matrizAd[ii][iii] = -1;
    }
  }

  tmp = g->primerVertice();
  for(int ii = 0; ii < g->numVertices() ; ii++){
    for(int iii = 0; iii < g->numVertices() ; iii++){
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

  relacion1a1.clear();
  visitadosHam.clear();
  delete obligatorioTomado;
  delete [] recorrido;
  delete [] recorridoR;
  return pesoDelrecorrido;
}
