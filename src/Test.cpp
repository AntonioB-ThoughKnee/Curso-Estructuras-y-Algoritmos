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
        this-> arbolAnchoPeq->Destruir();
        delete this-> arbolAnchoPeq;
        this-> arbolAnchoMed->Destruir();
        delete this-> arbolAnchoMed;
        this-> arbolAnchoGrande->Destruir();
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
    for(int i=1;i<=this->npeq;++i){
        this->arbolAnchoPeq->AgregarHijoMasDerecho(this->arbolAnchoPeq->Raiz(),i);
    }
    for(int i=1;i<=this->nmed;++i){
        this->arbolAnchoMed->AgregarHijoMasDerecho(this->arbolAnchoMed->Raiz(),i);
    }
    for(int i=1;i<=this->ngran;++i){
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
void Test::Correr(){
    Algoritmos algoritmos1(this->arbolAnchoPeq);
    algoritmos1.listarPreOrden();
    algoritmos1.cantidadNivelesPreOrden();
    algoritmos1.contieneEtiquetasRepetidas();
    algoritmos1.profundidadNodo(algoritmos1.BuscarEtiqueta((this->npeq)-1,this->arbolAnchoPeq));

    Algoritmos algoritmos2(this->arbolAnchoMed);
    algoritmos2.listarPreOrden();
    algoritmos2.cantidadNivelesPreOrden();
    algoritmos2.contieneEtiquetasRepetidas();
    algoritmos2.profundidadNodo(algoritmos2.BuscarEtiqueta((this->nmed)-1,this->arbolAnchoMed));

    Algoritmos algoritmos3(this->arbolAnchoGrande);
    algoritmos3.listarPreOrden();
    algoritmos3.cantidadNivelesPreOrden();
    algoritmos3.contieneEtiquetasRepetidas();
    algoritmos3.profundidadNodo(algoritmos3.BuscarEtiqueta((this->ngran)-1,this->arbolAnchoGrande));

    Algoritmos algoritmos4(this->arbolLargoPeq);
    algoritmos4.listarPreOrden();
    algoritmos4.cantidadNivelesPreOrden();
    algoritmos4.contieneEtiquetasRepetidas();
    algoritmos4.profundidadNodo(algoritmos4.BuscarEtiqueta((this->npeq)-1,this->arbolLargoPeq));

    Algoritmos algoritmos5(this->arbolLargoMed);
    algoritmos5.listarPreOrden();
    algoritmos5.cantidadNivelesPreOrden();
    algoritmos5.contieneEtiquetasRepetidas();
    algoritmos5.profundidadNodo(algoritmos5.BuscarEtiqueta((this->nmed)-1,this->arbolLargoMed));

    Algoritmos algoritmos6(this->arbolLargoGrande);
    algoritmos6.listarPreOrden();
    algoritmos6.cantidadNivelesPreOrden();
    algoritmos6.contieneEtiquetasRepetidas();
    algoritmos6.profundidadNodo(algoritmos6.BuscarEtiqueta((this->ngran)-1,this->arbolLargoGrande));

    Algoritmos algoritmos7(this->arbolComunPeq);
    algoritmos7.listarPreOrden();
    algoritmos7.cantidadNivelesPreOrden();
    algoritmos7.contieneEtiquetasRepetidas();
    algoritmos7.profundidadNodo(algoritmos7.BuscarEtiqueta((this->npeq)-1,this->arbolComunPeq));

    Algoritmos algoritmos8(this->arbolComunMed);
    algoritmos8.listarPreOrden();
    algoritmos8.cantidadNivelesPreOrden();
    algoritmos8.contieneEtiquetasRepetidas();
    algoritmos8.profundidadNodo(algoritmos8.BuscarEtiqueta((this->nmed)-1,this->arbolComunMed));

    Algoritmos algoritmos9(this->arbolComunGrande);
    algoritmos9.listarPreOrden();
    algoritmos9.cantidadNivelesPreOrden();
    algoritmos9.contieneEtiquetasRepetidas();
    algoritmos9.profundidadNodo(algoritmos9.BuscarEtiqueta((this->ngran)-1,this->arbolComunGrande));    
}