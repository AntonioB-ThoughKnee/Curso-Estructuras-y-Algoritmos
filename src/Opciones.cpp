#include <iostream>
#include "../include/Opciones.hpp"
#include "../include/Algoritmos.hpp"
using namespace std;

Opciones::Opciones(Arbol* arbol){
// Se inicializan los punteros a las estructuras por probar
    this->lista = nullptr;
    this->cola = nullptr;
    this->arbol = arbol;
}

Opciones::Opciones(){
// Se inicializan los punteros a las estructuras por probar
    this->lista = nullptr;
    this->cola = nullptr;
    this->arbol = nullptr;
}
Opciones::~Opciones(){
// En caso de ser necesario se libera la memoria
    // if(this->lista!=nullptr){
    //     delete this->lista;
    //     this->lista=nullptr;
    // }
    // if(this->cola!=nullptr){
    //     delete this->cola;
    //     this->cola=nullptr;
    // }
    // if(this->arbol!=nullptr){
    //     delete this->arbol;
    //     this->arbol=nullptr;
    // }
}

void Opciones::menuGeneral() {
  int accion = -1;
  while (accion != 0){
    cout << "1- Lista 2-Cola 3-Árbol OTRO-Salir" << endl;
    cin >> accion;
    switch(accion){
      case 1:
        this->menuLista();
      break;
      case 2:
        this->menuCola();
      break;
      case 3:
        this->menuArbol();
      break;
      default:
          accion=0;
      break;
    }
  }
}
void Opciones::menuLista(){
// Se inicializa la lista
    this->lista=new ListaIndexada<int>();
    cout << "Una lista ha sido creada" << endl;
    int accion=0;
// Se despliega un menu para controlar la lista
    while (!accion){
        cout << "Digite una opcion: 1-Insertar 2-Borrar 3-Recuperar 4-Modificar 5- NumElem 6-Destruir (salir)" << endl;
        cin >> accion;
        switch(accion){
            case 1:
                int indiceAgregar;
                int elementoAgregar;
                cout << "Digite un indice: " << endl;
                cin >> indiceAgregar;
                cout << "Digite el valor que desea agregar: " << endl;
                cin >> elementoAgregar;
                this->lista->Insertar(elementoAgregar,indiceAgregar);
                accion=0;
            break;
            case 2:
                int indiceBorrar;
                cout << "Digite un indice: " << endl;
                cin >> indiceBorrar;
                this->lista->Borrar(indiceBorrar);
                accion=0;
            break;
            case 3:
                int indiceRecuperar;
                cout << "Digite un indice: " << endl;
                cin >> indiceRecuperar;
                cout << "El elemento recuperado es: " << this->lista->Recuperar(indiceRecuperar) << endl;
                accion=0;
            break;
            case 4:
                int indiceModificar;
                int elementoModificar;
                cout << "Digite un indice: " << endl;
                cin >> indiceModificar;
                cout << "Digite el nuevo valor: " << endl;
                cin >> elementoModificar;
                this->lista->Modificar(elementoModificar,indiceModificar);
                accion=0;
            break;
            case 5:
                cout << "La cantidad de elementos es: " << this->lista->NumElem() << endl;
                accion=0;
            break;
            case 6:
                delete this->lista;
                this->lista=nullptr;
                cout << "La lista ha sido destruida" << endl;
            break;
            default:
                cout << "Debe elegir una opción valida" << endl;
                accion=0;
            break;
        }
    }
}
void Opciones::menuCola(){
// Se inicializa la cola
    this->cola=new Cola<int*>();
    this->cola->Iniciar();
    cout << "Una cola ha sido creada" << endl;
    int accion=0;
// Se despliega un menu para controlar la cola
    while (!accion){
        cout << "Digite una opcion: 1-Encolar 2-Desencolar 3-NumElem 4-Destruir (salir)" << endl;
        cin >> accion;
        switch(accion){
            case 1:  {
                int* elementoEncolar = new int();
                cout << "Digite el valor que desea agregar: " << endl;
                cin >> *elementoEncolar;
                this->cola->Encolar(elementoEncolar);
                accion=0;
            } break;
            case 2: {
                int* punt = this->cola->Desencolar();
                cout << "El elemento recuperado es: " << *punt << endl;
                accion=0;
                delete punt;
                punt = nullptr;
            } break;
            case 3: {
                cout << "La cantidad de elementos es: " << this->cola->NumElem() << endl;
                accion=0;
            } break;
            case 4: {
                delete this->cola;
                this->cola=nullptr;
                cout << "La cola ha sido destruida" << endl;
            } break;
            default: {
                cout << "Debe elegir una opción valida" << endl;
                accion=0;
            } break;
        }
    }
}
void Opciones::menuArbol(){
// Se inicializa la lista
  cout << "Un arbol ha sido creado" << endl;
  int accion=1;
  bool raizDefinida = false;
  Algoritmos temp(this->arbol);
  Arbol::Nodo* nodo;
  int numNodo = -1;
  int numPadre = -1;
  int numeroEtiqueta = -1;
// Se despliega un menu para controlar la lista
  while (accion != 0){
    cout << "\nDigite una opcion: 0-Salir 1-PonerRaíz  2-AgregarHijo 3-AgregarHijoMásDerecho \n4-BorrarHoja  5-Raíz 6-Padre 7-HijoMásIzquierdo 8-Hermano Derecho \n9-Etiqueta 10-ModificaEtiqueta 11-NumNodos" << endl;
    cin >> accion;
    //TODO: HACER FUNCIONAR ESTE MENU CON LAS OPCIONES DEL ARBOL
    switch(accion){
      case 0: {
        accion = 0;
      }
      break; // Vuelve a preguntar
      case 1: {
        if(raizDefinida) {
            cout << "Ya hay una raiz en el árbol " << endl; 
            break;
        }
        cout << "Digite el numero de la etiqueta: " << endl;
        cin >> numeroEtiqueta;
        this->arbol->PonerRaiz(numeroEtiqueta);
      }
      break;
      case 2: {
        cout << "Digite la etiqueta del nodo padre:" << endl;
        cin >> numPadre;
        nodo = temp.BuscarEtiqueta(numPadre, this->arbol);

        cout << "Digite el numero de la etiqueta: " << endl;
        cin >> numeroEtiqueta;
        this->arbol->AgregarHijo(nodo, numeroEtiqueta);
        cout << "Se agregó el hijo." << endl;
      }
      break;
      case 3: {
        cout << "Digite la etiqueta del nodo padre:" << endl;
        cin >> numPadre;
        nodo = temp.BuscarEtiqueta(numPadre, this->arbol);

        cout << "Digite el numero de la etiqueta: " << endl;
        cin >> numeroEtiqueta;
        this->arbol->AgregarHijoMasDerecho(nodo, numeroEtiqueta);
        cout << "Se agregó el hijo." << endl;
      } break;
      case 4: {
        cout << "Digite la etiqueta de la hoja que desea borrar:" << endl;
        cin >> numNodo;
        nodo = temp.BuscarEtiqueta(numNodo, this->arbol);

        this->arbol->BorrarHoja(nodo);
        cout << "Se borró la hoja." << endl;
      } break;
      case 5: {
        auto raiz = this->arbol->Raiz();
        cout << this->arbol->Etiqueta(raiz) << endl;
      } break;
      case 6: {
        cout << "Digite la etiqueta del nodo que desea conocerle el padre:" << endl;
        cin >> numNodo;
        nodo = temp.BuscarEtiqueta(numNodo, this->arbol);
        this->arbol->Padre(nodo);
        cout << "Padre: " << this->arbol->Etiqueta(nodo) << endl;
      } break;
      case 7: {
        cout << "Digite la etiqueta del nodo al cual desea conocer su hijo mas izquierdo" << endl;
        cin >> numNodo;
        nodo = temp.BuscarEtiqueta(numNodo, this->arbol);
        auto nodo2 = this->arbol->HijoMasIzquierdo(nodo);
        cout << "Hijo Izquierdo: " << this->arbol->Etiqueta(nodo2) << endl; 
      } break;
      case 8: {
        cout << "Digite la etiqueta del nodo al cual desea conocer su hermano derecho" << endl;
        
        cin >> numNodo;
        nodo = temp.BuscarEtiqueta(numNodo, this->arbol);
        this->arbol->HermanoDerecho(nodo);
      } break;
      case 9: {
        // TODO: etiqueta

        cout << "Digite la etiqueta del nodo del cual le desea conocer la etiqueta: ";
        cin >> numeroEtiqueta;
        nodo = temp.BuscarEtiqueta(numeroEtiqueta, this->arbol);
        if (nodo) {
          cout << "Etiqueta: " << this->arbol->Etiqueta(nodo) << endl;
        }
        else {
          cout << "No existe nodo con esa etiqueta.";
        }
      } break;
      case 10: {
        cout << "Digite la etiqueta del nodo al cual desea cambiarle la etiqueta" << endl;
        cin >> numNodo;
        nodo = temp.BuscarEtiqueta(numNodo, this->arbol);
        cout << "Digite el numero de la nueva etiqueta: " << endl;
        cin >> numeroEtiqueta;
        this->arbol->ModificarEtiqueta(nodo, numeroEtiqueta);
      } break;
      case 11: {
        cout << "La cantidad de nodos que contiene el árbol es: " << 
          this->arbol->NumNodos() << endl;
      } break;
      default: {
        accion = 0;
      } break;
    }
  }
}