#include <iostream>

#include "../include/ListaIndexada.hpp"

using namespace std;
 
ListaIndexada::ListaIndexada(){
}
ListaIndexada::~ListaIndexada(){
}
void::ListaIndexada::Iniciar(){
// Se inicializan los atributos de la clase
    this->primero=nullptr;
    this->ultimo=nullptr;
    this->contador=0;
}
void::ListaIndexada::Destruir(){
// Se libera la memoria utilizada
    delete this->primero;
}
void ListaIndexada::borrar(int indice){
// Se crea un puntero para iterar por la lista
    Caja* actual=this->primero;
// Se verifica si el borrado se hace al frente de la lista
    if(indice==1){
// En caso de serlo se borra la primera posicion y
// El puntero al primer elemento apunta al antiguo segundo
        Caja* cajaBorrar=this->primero;
        this->primero=this->primero->siguiente;
        cajaBorrar->siguiente=nullptr;
        delete cajaBorrar;
    }else{
// De no serlo se elimina el elemento normalmente
        for (int i=1;i<indice-1;++i){
        actual=actual->siguiente;
        }
        Caja* cajaBorrar=actual->siguiente;
        actual->siguiente=actual->siguiente->siguiente;
        cajaBorrar->siguiente=nullptr;
        delete cajaBorrar;
    }
// Se verifica si ha cambiado el ultimo 
// En caso de haberlo hecho se modifica el puntero al ultimo
    if(this->contador==indice){
        this->ultimo=actual;
    }
// Se decrementa la cantidad de elementos de la lista
    --contador;
}

void ListaIndexada::insertar(int dato,int indice){
// Se crea una nueva caja con el numero por insertar
    Caja* caja=new Caja(dato);
// Se crea un puntero para iterar por la lista
    Caja* actual=this->primero;
// Se verifica si el insertado se hace al frente de la lista
// En caso de serlo se inserta en la primera posicion y
// El puntero al primer elemento apunta a la nueva caja
    if(indice==1){
        caja->siguiente=this->primero;
        this->primero=caja;
    }
// En cualquier otro caso se inserta normalmente,recorriendo la lista
// menos si la insercion es al final 
    else if(indice==this->contador && indice!=1){
        this->ultimo->siguiente=caja;
    }else{
// Cuando la insercion es al final se usa el puntero al ultimo 
// y se inserta directamente al final de la lista
        for (int i=1;i<indice-1;++i){
        actual=actual->siguiente;
        }
        caja->siguiente=actual->siguiente;
        actual->siguiente=caja;
    }
// Se aumenta la cantidad de elementos 
    ++this->contador;
// Se verifica si ha cambiado el ultimo 
// En caso de haberlo hecho se modifica el puntero al ultimo
    if(this->contador==indice){
        this->ultimo=caja;
    }
}
int ListaIndexada::recuperar(int indice){
// Se itera por la lista para llegar al indice deseado
    Caja* actual=this->primero;
    for (int i=1;i<indice;++i){
    actual=actual->siguiente;
    }
// El dato en ese indice se devuelve
    return actual->dato;
}
void ListaIndexada::modificar(int indice,int dato){
// Se itera por la lista para llegar al indice deseado
// y se modifica con el dato ingresado 
    Caja* actual=this->primero;
    for (int i=1;i<indice;++i){
    actual=actual->siguiente;
    }
    actual->dato=dato;
}
int ListaIndexada::numElem(){
// Se devuelve la cantidad de datos en la lista
    return this->contador;
}
ListaIndexada::Caja::Caja(int dato){
// Se inicializan los atributos de la caja
    this->dato=dato;
    this->siguiente=nullptr;
}
ListaIndexada::Caja::~Caja(){
// En caso de haber,
// Se manda a liberar la memoria del siguiente elemento de la caja 
    if(this->siguiente!=nullptr){
        delete this->siguiente;
    }
}

