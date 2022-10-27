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
        "1- Contar los niveles de un abol 2- Listar Etiquetas de un nivel"
        "3- Recorrer el arbol en PreOrden 4- Recorrer el arbol por niveles"
        "OTRO- Salir"
        ;
        cout<<opciones<<endl;
        cin >> accion;
        switch(accion){
            case 1:
                cout<<"El arbol tiene "<<this->contarPorNiveles()<<" niveles"<<endl;
            break;
            case 2:
                int nivel;
                cout<<"Seleccione el nivel: "<<endl;
                cin>>nivel;
                this->listaEtiquetasNivel(nivel);
            break;
            case 3:
                this->recorridoPreOrden();
            break;
            case 4:
                this->recorridoPorNiveles();
            break;
            default:
                accion=0;
            break;
        }
    }
}