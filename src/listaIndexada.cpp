#include <iostream>

#include "../include/ListaIndexada.hpp"

using namespace std;
 
ListaIndexada::ListaIndexada(){
    this->primero=nullptr;
    this->ultimo=nullptr;
    this->contador=0;
}
ListaIndexada::~ListaIndexada(){
    delete this->primero;
}
void ListaIndexada::borrar(int posicion){
    Nodo* actual=this->primero;
    if(posicion==1){
        Nodo* nodoBorrar=this->primero;
        this->primero=this->primero->siguiente;
        nodoBorrar->siguiente=nullptr;
        delete nodoBorrar;
    }else{
        for (int i=1;i<posicion-1;++i){
        actual=actual->siguiente;
        }
        Nodo* nodoBorrar=actual->siguiente;
        actual->siguiente=actual->siguiente->siguiente;
        nodoBorrar->siguiente=nullptr;
        delete nodoBorrar;
    }
    if(this->contador==posicion){
        this->ultimo=actual;
    }
    --contador;
}
void ListaIndexada::insertar(int dato,int posicion){
    Nodo* nodo=new Nodo(dato);
    Nodo* actual=this->primero;
    if(posicion==1){
        nodo->siguiente=this->primero;
        this->primero=nodo;
    }
    else if(posicion==this->contador && posicion!=1){
        this->ultimo->siguiente=nodo;
    }else{
        for (int i=1;i<posicion-1;++i){
        actual=actual->siguiente;
        }
        nodo->siguiente=actual->siguiente;
        actual->siguiente=nodo;
    }
    ++this->contador;
    if(this->contador==posicion){
        this->ultimo=nodo;
    }
}
int ListaIndexada::recuperar(int posicion){
    Nodo* actual=this->primero;
    for (int i=1;i<posicion;++i){
    actual=actual->siguiente;
    }
    return actual->dato;
}
void ListaIndexada::modificar(int posicion,int dato){
    Nodo* actual=this->primero;
    for (int i=1;i<posicion;++i){
    actual=actual->siguiente;
    }
    actual->dato=dato;
}
int ListaIndexada::numElem(){
    return this->contador;
}
ListaIndexada::Nodo::Nodo(int dato){
    this->dato=dato;
    this->siguiente=nullptr;
}
ListaIndexada::Nodo::~Nodo(){
    if(this->siguiente!=nullptr){
        delete this->siguiente;
    }
}
void ListaIndexada::imprimir(){
    for(int i=1;i<=this->contador;++i){
        cout << recuperar(i) << " ";
    }
    cout <<endl;
}

