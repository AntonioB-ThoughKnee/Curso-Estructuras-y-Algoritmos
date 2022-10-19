#include <iostream>
#include "../include/Opciones.hpp"

using namespace std;

Opciones::Opciones(){
    ListaIndexada* lista = nullptr;
    Cola* cola = nullptr;
    Arbol* arbol = nullptr;
}
Opciones::~Opciones(){
    if(this->lista!=nullptr){
        delete this->lista;
    }
    if(this->cola!=nullptr){
        delete this->cola;
    }
    if(this->arbol!=nullptr){
        delete this->arbol;
    }
}
void Opciones::menuLista(){
    this->lista=new ListaIndexada();
    cout << "Una lista ha sido creada" << endl;
    int accion=0;
    while (!accion){
        cout << "Digite una opcion: 1-Insertar 2-Borrar 3-Recuperar 4-Modificar 5- NumElem 5-Destruir (salir)" << endl;
        cin >> accion;
        switch(accion){
            case 1:
            
            break;
            case 2:
            //opciones.menuCola();
            break;
            case 3:
            //opciones.menuArbol();
            break;
            case 4:
            break;
            default:
            cout << "Debe elegir una opción valida" << endl;
            accion=0;
            break;
        }
    }

}
void Opciones::menuCola(){

}
