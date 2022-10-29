#include <iostream>
#include <string.h>

#include "../include/Algoritmos.hpp"
#include "../include/ColaPlantilla.hpp"


using namespace std;

Algoritmos::Algoritmos(){
    this->arbol=new Arbol();
    this->nivelMaximo=1;
}
Algoritmos::~Algoritmos(){
    if (this->arbol!=nullptr){
        delete this->arbol;
    }
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
            break;
            default:
                accion=0;
            break;
        }
    }
}

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

void Algoritmos::listarPorNiveles(){
    if (this->arbol->NumNodos()!=0){
        Cola<Arbol::Nodo*> cola;
        cola.Iniciar();
        cola.Encolar(this->arbol->Raiz());
        while (cola.numElem()!=0){
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
