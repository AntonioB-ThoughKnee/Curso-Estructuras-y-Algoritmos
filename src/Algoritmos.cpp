#include <iostream>
#include <string.h>

#include "../include/Algoritmos.hpp"


using namespace std;

Algoritmos::Algoritmos(){
    this->arbol=new Arbol();
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
            default:
                accion=0;
            break;
        }
    }
}