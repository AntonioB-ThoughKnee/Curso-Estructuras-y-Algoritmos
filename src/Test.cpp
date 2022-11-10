#include <iostream>
#include <bits/stdc++.h>

#include "time.h"

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

    this->npeq=50;
    this->nmed=500;
    this->ngran=5000;
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
        this->arbolAnchoGrande->AgregarHijoMasDerecho(this->arbolAnchoGrande->Raiz(),i);
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
    clock_t start, end;


    Algoritmos algoritmos1(this->arbolAnchoPeq);
    
    start = clock();
    algoritmos1.listarPreOrden();
    end = clock();
    double time_taken1 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos1.cantidadNivelesPreOrden();
    end = clock();
    double time_taken2 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos1.contieneEtiquetasRepetidas();
    end = clock();
    double time_taken3 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos1.profundidadNodo(algoritmos1.BuscarEtiqueta((this->npeq)-1,this->arbolAnchoPeq));
    end = clock();
    double time_taken4 = double(end - start) / double(CLOCKS_PER_SEC);

    Algoritmos algoritmos2(this->arbolAnchoMed);

    start = clock();
    algoritmos2.listarPreOrden();
    end = clock();
    double time_taken5 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos2.cantidadNivelesPreOrden();
    end = clock();
    double time_taken6 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos2.contieneEtiquetasRepetidas();
    end = clock();
    double time_taken7 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos2.profundidadNodo(algoritmos2.BuscarEtiqueta((this->nmed)-1,this->arbolAnchoMed));
    end = clock();
    double time_taken8 = double(end - start) / double(CLOCKS_PER_SEC);

    Algoritmos algoritmos3(this->arbolAnchoGrande);
    start = clock();
    algoritmos3.listarPreOrden();
    end = clock();
    double time_taken9 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos3.cantidadNivelesPreOrden();
    end = clock();
    double time_taken10 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos3.contieneEtiquetasRepetidas();
    end = clock();
    double time_taken11 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos3.profundidadNodo(algoritmos3.BuscarEtiqueta((this->ngran)-1,this->arbolAnchoGrande));
    end = clock();
    double time_taken12 = double(end - start) / double(CLOCKS_PER_SEC);

    Algoritmos algoritmos4(this->arbolLargoPeq);
    start = clock();
    algoritmos4.listarPreOrden();
    end = clock();
    double time_taken13 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos4.cantidadNivelesPreOrden();
    end = clock();
    double time_taken14 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos4.contieneEtiquetasRepetidas();
    end = clock();
    double time_taken15 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos4.profundidadNodo(algoritmos4.BuscarEtiqueta((this->npeq)-1,this->arbolLargoPeq));
    end = clock();
    double time_taken16 = double(end - start) / double(CLOCKS_PER_SEC);

    Algoritmos algoritmos5(this->arbolLargoMed);
    start = clock();
    algoritmos5.listarPreOrden();
    end = clock();
    double time_taken17 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos5.cantidadNivelesPreOrden();
    end = clock();
    double time_taken18 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos5.contieneEtiquetasRepetidas();
    end = clock();
    double time_taken19 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos5.profundidadNodo(algoritmos5.BuscarEtiqueta((this->nmed)-1,this->arbolLargoMed));
    end = clock();
    double time_taken20 = double(end - start) / double(CLOCKS_PER_SEC);


    Algoritmos algoritmos6(this->arbolLargoGrande);

    start = clock();
    algoritmos6.listarPreOrden();
    end = clock();
    double time_taken21 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos6.cantidadNivelesPreOrden();
    end = clock();
    double time_taken22 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos6.contieneEtiquetasRepetidas();
    end = clock();
    double time_taken23 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos6.profundidadNodo(algoritmos6.BuscarEtiqueta((this->ngran)-1,this->arbolLargoGrande));
    end = clock();
    double time_taken24 = double(end - start) / double(CLOCKS_PER_SEC);

    Algoritmos algoritmos7(this->arbolComunPeq);
    start = clock();
    algoritmos7.listarPreOrden();
    end = clock();
    double time_taken25 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos7.cantidadNivelesPreOrden();
    end = clock();
    double time_taken26 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos7.contieneEtiquetasRepetidas();
    end = clock();
    double time_taken27 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos7.profundidadNodo(algoritmos7.BuscarEtiqueta((this->npeq)-1,this->arbolComunPeq));
    end = clock();
    double time_taken28 = double(end - start) / double(CLOCKS_PER_SEC);

    Algoritmos algoritmos8(this->arbolComunMed);
    start = clock();
    algoritmos8.listarPreOrden();
    end = clock();
    double time_taken29 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos8.cantidadNivelesPreOrden();
    end = clock();
    double time_taken30 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos8.contieneEtiquetasRepetidas();
    end = clock();
    double time_taken31 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos8.profundidadNodo(algoritmos8.BuscarEtiqueta((this->nmed)-1,this->arbolComunMed));
    end = clock();
    double time_taken32 = double(end - start) / double(CLOCKS_PER_SEC);

    Algoritmos algoritmos9(this->arbolComunGrande);
    start = clock();
    algoritmos9.listarPreOrden();
    end = clock();
    double time_taken33 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos9.cantidadNivelesPreOrden();
    end = clock();
    double time_taken34 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos9.contieneEtiquetasRepetidas();
    end = clock();
    double time_taken35 = double(end - start) / double(CLOCKS_PER_SEC);
    start = clock();
    algoritmos9.profundidadNodo(algoritmos9.BuscarEtiqueta((this->ngran)-1,this->arbolComunGrande));
    end = clock();
    double time_taken36 = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "arbol Ancho peq algoritmo1 : " << fixed 
         << time_taken1 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Ancho peq algoritmo2 : " << fixed 
         << time_taken2 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Ancho peq algoritmo3 : " << fixed 
         << time_taken3 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Ancho peq algoritmo4 : " << fixed 
         << time_taken4 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Ancho med algortimo1: " << fixed 
         << time_taken5 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Ancho med algortimo2: " << fixed 
         << time_taken6 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Ancho med algortimo3: " << fixed 
         << time_taken7 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Ancho med algortimo4: " << fixed 
         << time_taken8 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Ancho grande algoritmo1: " << fixed 
         << time_taken9 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Ancho grande algoritmo2: " << fixed 
         << time_taken10 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Ancho grande algoritmo3: " << fixed 
         << time_taken11 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Ancho grande algoritmo4: " << fixed 
         << time_taken12 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo peq algoritmo1: " << fixed 
         << time_taken13 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo peq algoritmo2: " << fixed 
         << time_taken14 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo peq algoritmo3: " << fixed 
         << time_taken15 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo peq algoritmo4: " << fixed 
         << time_taken16 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo med algoritmo1: " << fixed 
         << time_taken17 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo med algoritmo2: " << fixed 
         << time_taken18 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo med algoritmo3: " << fixed 
         << time_taken19 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo med algoritmo4: " << fixed 
         << time_taken20 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo grande algoritmo1: " << fixed 
         << time_taken21 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo grande algoritmo2: " << fixed 
         << time_taken22 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo grande algoritmo3: " << fixed 
         << time_taken23 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Largo grande algoritmo4: " << fixed 
         << time_taken24 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun peq algoritmo1: " << fixed 
         << time_taken25 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun peq algoritmo2: " << fixed 
         << time_taken26 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun peq algoritmo3: " << fixed 
         << time_taken27 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun peq algoritmo4: " << fixed 
         << time_taken28 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun med algoritmo1: " << fixed 
         << time_taken29 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun med algoritmo2: " << fixed 
         << time_taken30 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun med algoritmo3: " << fixed 
         << time_taken31 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun med algoritmo4: " << fixed 
         << time_taken32 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun grande algoritmo1: " << fixed 
         << time_taken33 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun grande algoritmo2: " << fixed 
         << time_taken34 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun grande algoritmo3: " << fixed 
         << time_taken35 << setprecision(5);
    cout << " sec " << endl;

    cout << "arbol Comun grande algoritmo4: " << fixed 
         << time_taken36 << setprecision(5);
    cout << " sec " << endl;    
}