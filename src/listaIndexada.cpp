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
    Caja* actual=this->primero;
    if(posicion==1){
        Caja* cajaBorrar=this->primero;
        this->primero=this->primero->siguiente;
        cajaBorrar->siguiente=nullptr;
        delete cajaBorrar;
    }else{
        for (int i=1;i<posicion-1;++i){
        actual=actual->siguiente;
        }
        Caja* cajaBorrar=actual->siguiente;
        actual->siguiente=actual->siguiente->siguiente;
        cajaBorrar->siguiente=nullptr;
        delete cajaBorrar;
    }
    if(this->contador==posicion){
        this->ultimo=actual;
    }
    --contador;
}
void ListaIndexada::insertar(int dato,int posicion){
    Caja* caja=new Caja(dato);
    Caja* actual=this->primero;
    if(posicion==1){
        caja->siguiente=this->primero;
        this->primero=caja;
    }
    else if(posicion==this->contador && posicion!=1){
        this->ultimo->siguiente=caja;
    }else{
        for (int i=1;i<posicion-1;++i){
        actual=actual->siguiente;
        }
        caja->siguiente=actual->siguiente;
        actual->siguiente=caja;
    }
    ++this->contador;
    if(this->contador==posicion){
        this->ultimo=caja;
    }
}
int ListaIndexada::recuperar(int posicion){
    Caja* actual=this->primero;
    for (int i=1;i<posicion;++i){
    actual=actual->siguiente;
    }
    return actual->dato;
}
void ListaIndexada::modificar(int posicion,int dato){
    Caja* actual=this->primero;
    for (int i=1;i<posicion;++i){
    actual=actual->siguiente;
    }
    actual->dato=dato;
}
int ListaIndexada::numElem(){
    return this->contador;
}
ListaIndexada::Caja::Caja(int dato){
    this->dato=dato;
    this->siguiente=nullptr;
}
ListaIndexada::Caja::~Caja(){
    if(this->siguiente!=nullptr){
        delete this->siguiente;
    }
}

