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
void ListaIndexada::borrar(int indice){
    Caja* actual=this->primero;
    if(indice==1){
        Caja* cajaBorrar=this->primero;
        this->primero=this->primero->siguiente;
        cajaBorrar->siguiente=nullptr;
        delete cajaBorrar;
    }else{
        for (int i=1;i<indice-1;++i){
        actual=actual->siguiente;
        }
        Caja* cajaBorrar=actual->siguiente;
        actual->siguiente=actual->siguiente->siguiente;
        cajaBorrar->siguiente=nullptr;
        delete cajaBorrar;
    }
    if(this->contador==indice){
        this->ultimo=actual;
    }
    --contador;
}
void ListaIndexada::insertar(int dato,int indice){
    Caja* caja=new Caja(dato);
    Caja* actual=this->primero;
    if(indice==1){
        caja->siguiente=this->primero;
        this->primero=caja;
    }
    else if(indice==this->contador && indice!=1){
        this->ultimo->siguiente=caja;
    }else{
        for (int i=1;i<indice-1;++i){
        actual=actual->siguiente;
        }
        caja->siguiente=actual->siguiente;
        actual->siguiente=caja;
    }
    ++this->contador;
    if(this->contador==indice){
        this->ultimo=caja;
    }
}
int ListaIndexada::recuperar(int indice){
    Caja* actual=this->primero;
    for (int i=1;i<indice;++i){
    actual=actual->siguiente;
    }
    return actual->dato;
}
void ListaIndexada::modificar(int indice,int dato){
    Caja* actual=this->primero;
    for (int i=1;i<indice;++i){
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

