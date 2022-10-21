#pragma once
//
// Created by jean on 17/10/22.
//

#ifndef TAREA_PROGRAMADA_LISTAHIJOS_HPP
#define TAREA_PROGRAMADA_LISTAHIJOS_HPP

#include <string>
typedef class ListaHijos {
public:
    struct ContenedorSublista; // "forward-declaration"
    struct ContenedorPrincipal {
        // nodo =
        ContenedorPrincipal(ContenedorPrincipal* sgte, int etiqueta, ContenedorSublista* primerHijo) : sgtePrincipal(sgte)
                , primerHijo(primerHijo), etiqueta(etiqueta) {
            //        this->nodo = new NodoLista(etiqueta);
        };

        ContenedorPrincipal* sgtePrincipal;
        //      NodoLista* nodo;
        int etiqueta;
        ContenedorSublista* primerHijo;
        ContenedorSublista* ultimoHijo;
    };

    struct ContenedorSublista {
        ContenedorSublista(ContenedorPrincipal* nodo) : nodo(nodo) {};
        ContenedorSublista* sgte = nullptr;
        ContenedorPrincipal* nodo;
    };

    //    ContenedorPrincipal* pPrimeroPrincipal = nullptr;
    ContenedorPrincipal* pPrimeroPrincipal;
    ContenedorPrincipal* pUltimoPrincipal;
    int cantNodos;

    ListaHijos() {};
    ~ListaHijos() {};

    void Crear();

    void Destruir();

    //    void PonerRaiz(TipoNodo elemento);
    void PonerRaiz(int etiqueta);


    //    void AgregarHijo(int etiqueta, TipoNodo elemento);
    ContenedorPrincipal* AgregarHijo(ContenedorPrincipal* nodoPadre, int etiqueta);


    //    void AgregarHijoMasDerecho(TipoNodo elemento);
    ContenedorPrincipal* AgregarHijoMasDerecho(ContenedorPrincipal* nodoPadre, int etiqueta);

    //    void BorrarHoja(std::string etiqueta);
    void BorrarHoja(int nodo_id_externo);

    ContenedorPrincipal* Raiz();

    ContenedorPrincipal* Padre(ContenedorPrincipal* nodoHijo);

    ContenedorPrincipal* HijoMasIzquierdo(ContenedorPrincipal* nodo);

    ContenedorPrincipal* HermanoDerecho(ContenedorPrincipal* nodo);

    int Etiqueta(ContenedorPrincipal* nodo);

    void ModificaEtiqueta(int etiqueta, ContenedorPrincipal* nodo);

    int NumNodos();
} Arbol;

#endif //TAREA_PROGRAMADA_LISTAHIJOS_HPP
