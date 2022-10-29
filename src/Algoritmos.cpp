#include <iostream>
#include <string.h>

#include "../include/Algoritmos.hpp"
#include "../include/ColaPlantilla.hpp"
#include "../include/ListaIndexadaPlantilla.hpp"

using namespace std;

Algoritmos::Algoritmos(){
    this->arbol=new Arbol();
    this->nivelMaximo=1;
    this->inicializarArbol();
}
Algoritmos::~Algoritmos(){
    if (this->arbol){
        delete this->arbol;
    }
}

void Algoritmos::inicializarArbol() {

    this->arbol->PonerRaiz(0);
    Arbol::Nodo* nodo1 = this->arbol->AgregarHijoMasDerecho(this->arbol->Raiz(), 1);
    Arbol::Nodo* nodo2 = this->arbol->AgregarHijoMasDerecho(this->arbol->Raiz(), 2);
    Arbol::Nodo* nodo3 = this->arbol->AgregarHijoMasDerecho(this->arbol->Raiz(), 3);
    Arbol::Nodo* nodo4 = this->arbol->AgregarHijoMasDerecho(nodo1, 4);
    Arbol::Nodo* nodo5 = this->arbol->AgregarHijoMasDerecho(nodo2, 5);
    Arbol::Nodo* nodo6 = this->arbol->AgregarHijoMasDerecho(nodo2, 6);
    Arbol::Nodo* nodo7 = this->arbol->AgregarHijoMasDerecho(nodo3, 7);
    Arbol::Nodo* nodo8 = this->arbol->AgregarHijoMasDerecho(nodo4, 8);
    Arbol::Nodo* nodo9 = this->arbol->AgregarHijoMasDerecho(nodo4, 9);
    Arbol::Nodo* nodo10 = this->arbol->AgregarHijoMasDerecho(nodo7, 10);
    Arbol::Nodo* nodo11 = this->arbol->AgregarHijoMasDerecho(nodo7, 11);
    Arbol::Nodo* nodo12 = this->arbol->AgregarHijoMasDerecho(nodo11, 12);
}

void Algoritmos::menu(){
    int accion=1;
    cout<<"Bienvenido al programa que prueba Algoritmos!"<<endl;
    ListaIndexada<int> lista;
    Arbol::Nodo* nodo;
    while (accion != 0){
        cout<<"Seleccione el algoritmo que desea probar: "<<endl;
        string opciones =
        "\n1- Encontrar el hermano izquierdo de un nodo \n2- Averiguar si el árbol tiene etiquetas repetidas\n"
        "3- Encontrar la profundidad de un nodo \n4- Encontrar la cantidad de niveles del árbol en Pre-Orden\n"
        "5- Encontrar la cantidad de niveles del árbol Por Niveles \n6- Listar las etiquetas de un nivel\n"
        "7- Listar las etiquetas del árbol en Pre-Orden \n8- Listar las etiquetas del árbol Por Niveles\n"
        "9- Buscar el nodo correspondiente con una etiqueta \n10- Eliminar subárbol a partir de un nodo\n"
        "11- Construir árbol de i-niveles y k-hijos a partir de una Lista Indexada\n"
        "OTRO- Salir"
        ;
        cout<<opciones<<endl;
        cin >> accion;
        switch(accion){
            case 1:
                int etiqueta;
                cout<<"Digite la etiqueta del nodo del cual quiere conocer el hermano izquierdo: "<<endl;
                cin>>etiqueta;
                this->hermanoIzquierdo(this->BuscarEtiqueta(etiqueta,this->arbol));
            break;
            case 2:
                this->contieneEtiquetasRepetidas();
            break;
            case 3:
                int etiqueta;
                cout<<"Digite la etiqueta del nodo del cual quiere conocer la profundidad: "<<endl;
                cin>>etiqueta;
                this->profundidadNodo(this->BuscarEtiqueta(etiqueta,this->arbol));
            break;
            case 4:
                this->cantidadNivelesPreOrden();
            break;
            case 5:
                this->cantidadNivelesPorNiveles();
            break;
            case 6:
                int nivelDeseado;
                cout << "Ingrese el nivel del que desea listar las etiquetas:"<<endl;
                cin >> nivelDeseado;
                this->listarEtiquetasNivel(nivelDeseado);
            break;
            case 7:
                this->listarPreOrden();
            break;
            case 8:
                this->listarPorNiveles();
            case 9:
                cout << "A cual nodo desea buscar? " << endl;     
                cin >> accion;   
                nodo = BuscarEtiqueta(accion, this->arbol);
                if(nodo == nullptr){
                  cout << "No existe nodo con esa etiqueta " << endl;
                } else {
                  cout << "Si existe nodo con esa etiqueta " << endl;
                }
            break;
            case 10: //  Borrar sub árbol
              cout << "Cuál nodo desea borrar?\nDigite la etiqueta del nodo " << endl;
              cin >> accion;
              nodo = BuscarEtiqueta(accion, this->arbol);
              if(nodo == nullptr){
                cout << "No existe nodo con esa etiqueta " << endl;
              } else {
                EliminarSubarbol(BuscarEtiqueta(accion, this->arbol), this->arbol);
                cout << "SubArbol eliminado" << endl;
              }
            break;
            case 11: // Construir arbol
              cout << "Se creará una lista con los números del 1 hasta el número que digite, y estos números formarán parte del nuevo árbol" << endl;
              cout << "La lista creada debe cumplir un tamaño igual a \n(k**i-1) / (k-1)\nDonde 'k' = hijos por nodo e 'i' = nivel de profundidad del arbol " << endl;
              cin >> accion;

              for(int ii = 1; ii <= accion ; ii++){ //bg
                lista.Insertar(ii, ii);
              }

              cout << "Ingrese la cantidad de hijos por nodo " << endl;
              cin >> accion;
              arbol = HacerArbol(accion, lista);
            break;
            default:
                accion=0;
            break;
        }
    }
}


// ALGORITMO 1:

void Algoritmos::hermanoIzquierdo(Arbol::Nodo* nodo) {
    //TODO: Arreglar caso nodo = 3
    if (this->arbol->NumNodos() != 0) {
        Cola<Arbol::Nodo*> C;
        C.Iniciar();
        C.Encolar(this->arbol->Raiz());
        while (C.NumElem() != 0) {
            Arbol::Nodo* n = C.Desencolar();
            Arbol::Nodo* nh = this->arbol->HijoMasIzquierdo(n);
            while (nh != nullptr) {
                
                Arbol::Nodo* hermDer = this->arbol->HermanoDerecho(nh);
                // if (hermDer == nodo) {
                if (hermDer != nullptr) {
                    if (this->arbol->Etiqueta(hermDer) == this->arbol->Etiqueta(nodo)) {
                        // return nh;
                        // cout << "Si entra" << endl;
                        std::cout << "El hermano izquierdo del nodo es: " << 
                            this->arbol->Etiqueta(nh) << std::endl;
                    }
                }
                C.Encolar(nh);
                nh = this->arbol->HermanoDerecho(nh);
            }
        }
    }
}

// ALGORITMO 2:

void Algoritmos::contieneEtiquetasRepetidas() {
    if (this->arbol->NumNodos() != 0) {
        ListaIndexada<Arbol::Nodo*> L;
        L.Iniciar();
        L.Insertar(this->arbol->Raiz(), L.NumElem() + 1);
        int indexSacar = 1;
        bool repetida = false;
        while (indexSacar < L.NumElem() +1 && !repetida) {
            auto n = L.Recuperar(indexSacar);
            auto nh = this->arbol->HijoMasIzquierdo(n);
            while (nh != nullptr) {
                // repetida = BuscarRepetidaEnLista(this->arbol->Etiqueta(nh), &L);
                for (int i = 0; i < (L.NumElem() + 1); i++) {
                    if (this->arbol->Etiqueta((L.Recuperar(i))) == this->arbol->Etiqueta(nh)) {
                        repetida = true; // si es repetida
                    }
                }
                if (repetida) {
                    break;
                }
                L.Insertar(nh, L.NumElem() + 1);
                nh = this->arbol->HermanoDerecho(nh);
            }
            indexSacar++;
        }
        L.Destruir();
        if (repetida) {
            std::cout << "El árbol sí tiene etiquetas repetidas" << endl;
        } else {
            std::cout << "El árbol no tiene etiquetas repetidas" << endl;
        }
    }
}

// ALGORITMO 3:

void Algoritmos::profundidadNodo(Arbol::Nodo* nodoBuscar) {
    bool encontrado = false;
    int nivelRet = -1;
    if (this->arbol->NumNodos() != 0) {
        ListarPreOrdenRProfundidad(this->arbol->Raiz(), 1, nodoBuscar,
            &nivelRet, &encontrado);
    }
    cout << "La profundidad desde la raíz hasta el nodo introducido es: " << nivelRet << endl;
}

void Algoritmos::ListarPreOrdenRProfundidad(Arbol::Nodo* nodo, int nivel,
  Arbol::Nodo* nodoBuscar, int* nivelRet, bool* encontrado) {
    // if (nodo == nodoBuscar) {
    if (this->arbol->Etiqueta(nodo) == this->arbol->Etiqueta(nodoBuscar)) {
        *encontrado = true;
        *nivelRet = nivel;
    }
    nodo = this->arbol->HijoMasIzquierdo(nodo);
    while (nodo != nullptr && !(*encontrado)) {
        ListarPreOrdenRProfundidad(nodo, nivel+1, nodoBuscar, nivelRet, encontrado);
        nodo = this->arbol->HermanoDerecho(nodo);
    }
}

// ALGORITMOS 4:

void Algoritmos::cantidadNivelesPreOrden() {
    int nivelRet = -1;
    if (this->arbol->NumNodos() != 0) {
        this->ListarPreOrdenR(this->arbol->Raiz(), 1, &nivelRet);
    }
    cout << "La cantidad de niveles del árbol es: " << nivelRet << endl;
}

void Algoritmos::ListarPreOrdenR(Arbol::Nodo* nodo, int nivel, int* nivelRet) {
    if (nivel > *nivelRet) {
        *nivelRet = nivel;
    }
    nodo = this->arbol->HijoMasIzquierdo(nodo);
    while (nodo != nullptr) {
        ListarPreOrdenR(nodo, nivel+1, nivelRet);
        nodo = this->arbol->HermanoDerecho(nodo);
    }
}

// ALGORITMO 5: NO FUNCIONA (ARREGLAR)

void Algoritmos::cantidadNivelesPorNiveles(){
    if(this->arbol->NumNodos()!=0){
        contarNivelesR(this->arbol->Raiz(),1);
    }
    cout << "El nivel maximo del arbol es: "<<this->nivelMaximo<<endl;
}

void Algoritmos::contarNivelesR(Arbol::Nodo* nodo,int nivelActual){
    if(nivelActual>this->nivelMaximo){
        this->nivelMaximo=nivelActual;
    }
    nodo=this->arbol->HijoMasIzquierdo(nodo);
    nivelActual=nivelActual+1;
    while (nodo!=nullptr){
        contarNivelesR(nodo,nivelActual);
        nodo=this->arbol->HermanoDerecho(nodo);
    }
}

// ALGORITMO 6: 

void Algoritmos::listarEtiquietasNivel(int nivelDeseado){
    if(this->arbol->NumNodos()!=0){
        listarEtiquietasNivelR(this->arbol->Raiz(),1,nivelDeseado);
    }
}

void Algoritmos::listarEtiquietasNivelR(Arbol::Nodo* nodo,int nivelActual,int nivelDeseado){
    if(nivelActual==nivelDeseado){
        cout<<this->arbol->Etiqueta(nodo)<<" ";
    }
    nodo=this->arbol->HijoMasIzquierdo(nodo);
    nivelActual=nivelActual+1;
    while (nodo!=nullptr){
        listarEtiquietasNivelR(nodo,nivelActual,nivelDeseado);
        nodo=this->arbol->HermanoDerecho(nodo);
    }
}

//ALGORITMO 7:

void Algoritmos::listarPreOrden(){
    if (this->arbol->NumNodos()!=0){
    listarPreOrdenR(this->arbol->Raiz());
    }
}
void Algoritmos::listarPreOrdenR(Arbol::Nodo* nodo){
    cout<<this->arbol->Etiqueta(nodo)<<" ";
    Arbol::Nodo* n1= this->arbol->HijoMasIzquierdo(nodo);
    while (n1 != nullptr){
    listarPreOrdenR(n1);
    n1 = this->arbol->HermanoDerecho(n1);
    }
}

//ALGORITMO 8:

void Algoritmos::listarPorNiveles(){
    if (this->arbol->NumNodos()!=0){
        Cola<Arbol::Nodo*> cola;
        cola.Iniciar();
        cola.Encolar(this->arbol->Raiz());
        while (cola.NumElem()!=0){
            Arbol::Nodo* nodo = cola.Desencolar();
            cout<<this->arbol->Etiqueta(nodo)<<" ";
            Arbol::Nodo* n1= this->arbol->HijoMasIzquierdo(nodo);
            while (n1 != nullptr){
                cola.Encolar(n1);
                n1 = this->arbol->HermanoDerecho(n1);
            }
        }
        cola.Destruir();
    }
}

//ALGORITMO 9:

Arbol::Nodo* Algoritmos::BuscarEtiqueta(int etiqueta, Arbol* A)
{
  Arbol::Nodo* tmp;
  ListaIndexada<Arbol::Nodo*> auxiliar;
  auxiliar.Insertar(A->Raiz(), auxiliar.NumElem()+1);
  int i = 1;
  //Se hace recorrido por niveles y se usa un if para encontrar el nodo buscado
  while(i <= auxiliar.NumElem())
  {
    tmp = auxiliar.Recuperar(i);
    i++;
    if(A->Etiqueta(tmp) == etiqueta) { return tmp; } 
    tmp = A->HijoMasIzquierdo(tmp);
    while(tmp != nullptr)
    {
      auxiliar.Insertar(tmp, auxiliar.NumElem()+1);
      tmp = A->HermanoDerecho(tmp);
    }
  }
  return nullptr;
}

// ALGORITMO 10:

void  Algoritmos::EliminarSubarbol(Arbol::Nodo* nodo, Arbol* A){
  Arbol::Nodo* tmp = A->HijoMasIzquierdo(nodo); //Hijo de nodo
  Arbol::Nodo* tmpHermanoDerecho; // Hermano derecho del hijo de nodo, existe porque se necesita guardar antes de que se elimine tmp al salir de la llamada recursiva en el while loop
  while(tmp != nullptr){
    tmpHermanoDerecho = A->HermanoDerecho(tmp);
    EliminarSubarbol(tmp, A);
    tmp = tmpHermanoDerecho;
  } 

  //Si se llegó al final del subárbol, se elimina la hoja y se crea un efecto dominó hacía arriba
  if(tmp == nullptr){
    A->BorrarHoja(nodo);
  }
}

// ALGORITMO 11:

Arbol* Algoritmos::HacerArbol(int nodosPorHijo, ListaIndexada<int> lista){
  Arbol* nuevoArbol = new Arbol();
  ListaIndexada<Arbol::Nodo*> auxiliar;
  int iLista = 1; 
  int iAuxiliar = 1;
  nuevoArbol->PonerRaiz(lista.Recuperar(iLista));
  iLista++; //Se suma 1 porque ya se añadió la raíz
  Arbol::Nodo* tmp = nuevoArbol->Raiz(); 

  //Se pasa por toda la lista dada
  while(iLista < lista.NumElem() ){
    //Agregando nodos correspondientes segun "nodosPorHijo" a tmp
    for(int ii = 0; ii < nodosPorHijo ; ii++){
      nuevoArbol->AgregarHijoMasDerecho(tmp, lista.Recuperar(iLista));
      iLista++;
    }
    //===========================  Guardando los nodos agregados para agregarles mas tarde los nodos correspondientes
    Arbol::Nodo* hijoDeTmp = nuevoArbol->HijoMasIzquierdo(tmp);
    while(hijoDeTmp != nullptr){
      auxiliar.Insertar(hijoDeTmp, auxiliar.NumElem()+1);
      hijoDeTmp = nuevoArbol->HermanoDerecho(hijoDeTmp);
    }
    //=====  

    //Sacando de auxiliar los nodos guardados para seguir agregando nodos
    tmp = auxiliar.Recuperar(iAuxiliar);
    iAuxiliar++;
  }
  return nuevoArbol;
}