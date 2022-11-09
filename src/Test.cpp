#include <iostream>

#include "../include/Test.hpp"
#include "../include/Algoritmos.hpp"

Test::Test(){
    this->arbolAnchoPeq=new Arbol();
    this->arbolAnchoPeq->Crear();
    this->arbolAnchoMed=new Arbol();
    this->arbolAnchoMed->Crear();
    this->arbolAnchoGrande=new Arbol();
    this->arbolAnchoGrande->Crear();

    this->arbolLargoPeq=new Arbol();
    this->arbolLargoPeq->Crear();
    this->arbolLargoMed=new Arbol();
    this->arbolLargoMed->Crear();
    this->arbolLargoGrande=new Arbol();
    this->arbolLargoGrande->Crear();

    this->arbolComunPeq=new Arbol();
    this->arbolComunPeq->Crear();
    this->arbolComunMed=new Arbol();
    this->arbolComunMed->Crear();
    this->arbolComunGrande=new Arbol();
    this->arbolComunGrande->Crear();

    this->npeq=10;
    this->nmed=100;
    this->ngran=1000;
}
Test::~Test(){
        delete this-> arbolAnchoPeq;
        delete this-> arbolAnchoMed;
        delete this-> arbolAnchoGrande;

        delete this-> arbolLargoPeq;
        delete this-> arbolLargoMed;
        delete this-> arbolLargoGrande;

        delete this-> arbolComunPeq;
        delete this-> arbolComunMed;
        delete this-> arbolComunGrande;
}
void Test::CrearArboles(){
    Algoritmos algoritmos;

    this->arbolAnchoPeq->PonerRaiz(0);
    this->arbolAnchoMed->PonerRaiz(0);
    this->arbolAnchoGrande->PonerRaiz(0);
    for(int i=0;i<this->npeq;++i){
        this->arbolAnchoPeq->AgregarHijoMasDerecho(this->arbolAnchoPeq->Raiz(),i);
    }
    for(int i=0;i<this->nmed;++i){
        this->arbolAnchoMed->AgregarHijoMasDerecho(this->arbolAnchoMed->Raiz(),i);
    }
    for(int i=0;i<this->ngran;++i){
        this->arbolAnchoGrande->AgregarHijoMasDerecho(this->arbolAnchoMed->Raiz(),i);
    }

    ListaIndexada<int> listapeq;
    listapeq.Iniciar();
    for(int i = 1; i <= this->npeq ; ++i){
    listapeq.Insertar(i, i);
    }

    ListaIndexada<int> listamed;
    listamed.Iniciar();
    for(int i = 1; i <= this->nmed ; ++i){
    listamed.Insertar(i, i);
    }
    
    ListaIndexada<int> listagran;
    listagran.Iniciar();
    for(int i = 1; i <= this->ngran ; ++i){
    listagran.Insertar(i, i);
    }
    
    this-> arbolLargoPeq=algoritmos.HacerArbol(1, listapeq);
    this-> arbolLargoMed=algoritmos.HacerArbol(1, listamed);
    this-> arbolLargoGrande=algoritmos.HacerArbol(1, listagran);

    this-> arbolComunPeq=algoritmos.HacerArbol(3, listapeq);
    this-> arbolComunMed=algoritmos.HacerArbol(3, listamed);
    this-> arbolComunGrande=algoritmos.HacerArbol(3, listagran);
}