#include <iostream>
#include <string.h>

#include "../include/Algoritmos.hpp"
// #include "../include/ColaPlantilla.hpp"


using namespace std;

Algoritmos::Algoritmos(){
    this->arbol=new Arbol();
}
Algoritmos::~Algoritmos(){
    if (this->arbol!=nullptr){
        delete this->arbol;
    }
}

void Algoritmos::inicializarArbol() {

    this->arbol->PonerRaiz(0);
    Arbol::Nodo* nodo1 = this->arbol->AgregarHijo(this->arbol->Raiz(), 1);
    Arbol::Nodo* nodo2 = this->arbol->AgregarHijo(this->arbol->Raiz(), 2);
    // std::cout << nodo1->nodo_id << endl;
    Arbol::Nodo* nodo3 = this->arbol->AgregarHijoMasDerecho(this->arbol->Raiz(), 3);
    Arbol::Nodo* nodo4 = this->arbol->AgregarHijo(nodo1, 4);
    Arbol::Nodo* nodo5 = this->arbol->AgregarHijoMasDerecho(nodo2, 5);
    Arbol::Nodo* nodo6 = this->arbol->AgregarHijoMasDerecho(nodo2, 6);
    Arbol::Nodo* nodo7 = this->arbol->AgregarHijoMasDerecho(nodo3, 7);
    Arbol::Nodo* nodo8 = this->arbol->AgregarHijoMasDerecho(nodo4, 8);
    Arbol::Nodo* nodo9 = this->arbol->AgregarHijoMasDerecho(nodo4, 9);
    Arbol::Nodo* nodo10 = this->arbol->AgregarHijoMasDerecho(nodo7, 10);
    Arbol::Nodo* nodo11 = this->arbol->AgregarHijoMasDerecho(nodo7, 11);
    Arbol::Nodo* nodo12 = this->arbol->AgregarHijoMasDerecho(nodo11, 12);

    // Pruebas:
    this->hermanoIzquierdo(nodo2); // ? no imprime nada y deberia imprimir 1 (solo ocurre error con hmihdconcontador, arregloPadre). (creo que solo sirve con listaHijos)
    this->contieneEtiquetasRepetidas(); // Funciona perfecto
    // this->profundidadNodo(nodo10);
    this->cantidadNivelesPreOrden(); // Funciona perfecto.

}

void Algoritmos::menu(){
    int accion=1;
    cout<<"Bienvenido al programa que prueba Algoritmos!"<<endl;
        //TODO: HACER FUNCIONAR ESTE MENU CON LAS OPCIONES DEL ARBOL
    while (accion != 0){
        cout<<"Seleccione el algoritmo que desea probar: "<<endl;
        // TODO: Terminar de agregar las opciones
        string opciones =
        "\n1- Encontrar el hermano izquierdo de un nodo \n2- Averiguar si el árbol tiene etiquetas repetidas\n"
        "3- Encontrar la profundidad de un nodo \n4- Encontrar la cantidad de niveles del árbol en Pre-Orden\n"
        "5- Encontrar la cantidad de niveles del árbol Por Niveles \n6- Listar las etiquetas de un nivel\n"
        "7- Listar las etiquetas del árbol en Pre-Orden \n8- Listar las etiquetas del árbol Por Niveles\n"
        "9- Buscar el nodo correspondiente con una etiqueta \n10- Eliminar subárbol a partir de un nodo\n"
        "11- Construir árbol de i-niveles y k-hijos a partir de una Lista Indexada\n"
        "OTRO- Salir"
        ;
        this->inicializarArbol();

        cout<<opciones<<endl;
        cin >> accion;
        switch(accion){
            case 1:
                // cout<<"El arbol tiene "<<this->contarPorNiveles()<<" niveles"<<endl;
            break;
            case 2:
                int nivel;
                // cout<<"Seleccione el nivel: "<<endl;
                cin>>nivel;
                // this->listaEtiquetasNivel(nivel);
            break;
            case 3:
                // this->recorridoPreOrden();
            break;
            case 4:
                // this->recorridoPorNiveles();
            break;
            default:
                accion=0;
            break;
        }
    }
}

void Algoritmos::hermanoIzquierdo(Arbol::Nodo* nodo) {
    //TODO: Arreglar caso nodo = 3
    if (this->arbol->NumNodos() != 0) {
        Cola<Arbol::Nodo*> C;
        C.Iniciar();
        C.Encolar(this->arbol->Raiz());
        while (C.numElem() != 0) {
            auto n = C.Desencolar();
            auto nh = this->arbol->HijoMasIzquierdo(n);
            while (nh != nullptr) {
                auto hermDer = this->arbol->HermanoDerecho(nh);
                if (hermDer == nodo) {
                    // return nh;
                    std::cout << nh->etiqueta << std::endl;
                }
                C.Encolar(nh);
                nh = this->arbol->HermanoDerecho(nh);
            }
        }
    }
}


void Algoritmos::contieneEtiquetasRepetidas() {
    if (this->arbol->NumNodos() != 0) {
        ListaIndexada<Arbol::Nodo*> L;
        L.Iniciar();
        L.insertar(this->arbol->Raiz(), L.numElem() + 1);
        int indexSacar = 1;
        bool repetida = false;
        while (indexSacar < L.numElem() +1 && !repetida) {
            auto n = L.recuperar(indexSacar);
            auto nh = this->arbol->HijoMasIzquierdo(n);
            while (nh != nullptr) {
                // repetida = BuscarRepetidaEnLista(this->arbol->Etiqueta(nh), &L);
                for (int i = 0; i < (L.numElem() + 1); i++) {
                    if (this->arbol->Etiqueta((L.recuperar(i))) == this->arbol->Etiqueta(nh)) {
                        repetida = true; // si es repetida
                    }
                }
                if (repetida) {
                    break;
                }
                L.insertar(nh, L.numElem() + 1);
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
    // return repetida;
}

// bool Algoritmos::BuscarRepetidaEnLista(int etiqueta, ListaIndexada<Arbol::Nodo*>* L) {
//     for (int i = 0; i < (L->numElem() + 1); i++) {
//         if (this->arbol->Etiqueta((L->recuperar(i))) == etiqueta) {
//             return true; // si es repetida
//         }
//     }
//     return false; // no se encontró repetida
// }

// ================== EMPIEZA PROFUNDIDAD NODO ======================
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
