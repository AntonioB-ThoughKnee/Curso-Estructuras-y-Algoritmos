#include <iostream>

#include "../include/cola.hpp"

using namespace std;

Cola::Cola(){
    this->inicio=0;
    this->final=-1;
    this->capacidad=10;
    this->cola= new int[10];
    this->contador=0;
}
Cola::~Cola(){
    this->inicio=0;
    this->final=0;
    this->capacidad=10;
    this->contador=0;
    delete this->cola;
}
void Cola::Encolar(int elemento){
    if(this->contador==this->capacidad){
        cout << "La cola esta llena"<<endl;
    }else{
        this->final=(this->final+1)%this->capacidad;
        this->cola[this->final]=elemento;
        ++this->contador;
    }

}
int Cola::Desencolar(){
    if(this->contador==0){
        cout << "La cola esta vacía" << endl;
        return 123;
    }else{
        int elemDevolver=cola[this->inicio];
        this->inicio=(this->inicio+1)%this->capacidad;
        --this->contador;
        return elemDevolver;
    }
    
}
int Cola::numElem(){
    return this->contador;
}