#include "../include/relacion1A1.hpp"

Relacion1A1::Relacion1A1(){
    this->izqADer=new std::map<Vertice*,int>;
    this->derAizq=new std::map<int,Vertice*>;
}

Relacion1A1::~Relacion1A1(){
    delete this->izqADer;
    delete this->derAizq;
}

void Relacion1A1::insertar(Vertice* izq,int der){
    izqADer->insert({izq,der});
    derAizq->insert({der,izq});
}
Vertice* Relacion1A1::getIzquierda(int& der){
    return ((*this->derAizq)[der]);
}
int Relacion1A1::getDerecha(Vertice*& izq){
    return((*(this->izqADer))[izq]);
}