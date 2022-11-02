#include <iostream>
#include "../include/Opciones.hpp"

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
    if(this->lista!=nullptr){
        delete this->lista;
        this->lista=nullptr;
    }
    if(this->cola!=nullptr){
        delete this->cola;
        this->cola=nullptr;
    }
    if(this->arbol!=nullptr){
        delete this->arbol;
        this->arbol=nullptr;
    }
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
    this->lista=new ListaIndexada();
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
                this->lista->insertar(elementoAgregar,indiceAgregar);
                accion=0;
            break;
            case 2:
                int indiceBorrar;
                cout << "Digite un indice: " << endl;
                cin >> indiceBorrar;
                this->lista->borrar(indiceBorrar);
                accion=0;
            break;
            case 3:
                int indiceRecuperar;
                cout << "Digite un indice: " << endl;
                cin >> indiceRecuperar;
                cout << "El elemento recuperado es: " << this->lista->recuperar(indiceRecuperar) << endl;
                accion=0;
            break;
            case 4:
                int indiceModificar;
                int elementoModificar;
                cout << "Digite un indice: " << endl;
                cin >> indiceModificar;
                cout << "Digite el nuevo valor: " << endl;
                cin >> elementoModificar;
                this->lista->modificar(elementoModificar,indiceModificar);
                accion=0;
            break;
            case 5:
                cout << "La cantidad de elementos es: " << this->lista->numElem() << endl;
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
    this->cola=new Cola();
    this->cola->Iniciar();
    cout << "Una cola ha sido creada" << endl;
    int accion=0;
// Se despliega un menu para controlar la cola
    while (!accion){
        cout << "Digite una opcion: 1-Encolar 2-Desencolar 3-NumElem 4-Destruir (salir)" << endl;
        cin >> accion;
        switch(accion){
            case 1:
                int elementoEncolar;
                cout << "Digite el valor que desea agregar: " << endl;
                cin >> elementoEncolar;
                this->cola->Encolar(elementoEncolar);
                accion=0;
            break;
            case 2:
                cout << "El elemento recuperado es: " << this->cola->Desencolar() << endl;
                accion=0;
            break;
            case 3:
                cout << "La cantidad de elementos es: " << this->cola->numElem() << endl;
                accion=0;
            break;
            case 4:
                delete this->cola;
                this->cola=nullptr;
                cout << "La cola ha sido destruida" << endl;
            break;
            default:
                cout << "Debe elegir una opción valida" << endl;
                accion=0;
            break;
        }
    }
}
void Opciones::menuArbol(){
// Se inicializa la lista
    cout << "Un arbol ha sido creado" << endl;
    int accion=1;
    bool raizDefinida = false;
// Se despliega un menu para controlar la lista
    while (accion != 0){
        cout << "\nDigite una opcion: 1-PonerRaíz  2-AgregarHijo 3-AgregarHijoMásDerecho 4-BorrarHoja  5-Raíz 6-Padre 7-HijoMásIzquierdo 8-Hermano Derecho 9-Etiqueta 10-ModificaEtiqueta 11-NumNodos" << endl;
        cin >> accion;
        //TODO: HACER FUNCIONAR ESTE MENU CON LAS OPCIONES DEL ARBOL
        switch(accion){
            case 1:
                if(raizDefinida) {
                    cout << "Ya hay una raiz en el árbol " << endl; 
                    break;
                }
                int numeroEtiqueta;
                cout << "Digite el numero de la etiqueta: " << endl;
                cin >> numeroEtiqueta;
                this->arbol->PonerRaiz(numeroEtiqueta);
            break;
            case 2:
                int raiz = this->arbol->Etiqueta(this->arbol->Raiz());
                // auto raiz = this->arbol->Raiz();
                cout << raiz << endl;
            break;
            // default:
            //     cout << "Debe elegir una opción valida" << endl;
            //     accion=0;
            // break;
        }
    }
}