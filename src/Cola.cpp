#include <iostream>

#include "../include/Cola.hpp"

using namespace std;

Cola::Cola(){
// Se inicializan los atributos de la clase
    this->inicio=0;
    this->final=-1;
    this->capacidad=10;
    this->cola= new int[10];
    this->contador=0;
}
Cola::~Cola(){
// Se dejan en cero todos los atributos de la clase y se libera la memoria utilizada
    this->inicio=0;
    this->final=0;
    this->capacidad=10;
    this->contador=0;
    delete this->cola;
}
void Cola::Encolar(int elemento){
// Se verifica si la cola tiene espacio, de no ser asi no se puede encolar
    if(this->contador==this->capacidad){
        cout << "La cola esta llena"<<endl;
    }else{
// En caso de tener espacio se modifica el final y se incluye el nuevo 
// valor
        this->final=(this->final+1)%this->capacidad;
        this->cola[this->final]=elemento;
        ++this->contador;
    }

}
int Cola::Desencolar(){
// Se verifica si la cola esta vacia, de ser asi no se puede desencolar de ella
    if(this->contador==0){
        cout << "La cola esta vacía" << endl;
        return 123;
    }else{
// Si no lo está, se modifica el inicio y se devuelve el primer valor agregado
        int elemDevolver=cola[this->inicio];
        this->inicio=(this->inicio+1)%this->capacidad;
        --this->contador;
        return elemDevolver;
    }
    
}
int Cola::numElem(){
// Se devuelve la cantidad de elementos en la cola
    return this->contador;
}