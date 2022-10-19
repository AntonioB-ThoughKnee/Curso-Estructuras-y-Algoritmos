//
// Created by jean on 17/10/22.
//

#ifndef TAREA_PROGRAMADA_LISTAHIJOS_HPP
#define TAREA_PROGRAMADA_LISTAHIJOS_HPP

#include <string>
#include "NodoListaHijos.hpp"

typedef class ListaHijos {
public:
    struct ContenedorSublista; // "forward-declaration"
    struct ContenedorPrincipal {
       // nodo =
      ContenedorPrincipal(ContenedorPrincipal* sgte, std::string etiqueta, ContenedorSublista* primerHijo) : sgtePrincipal(sgte)
        , primerHijo(primerHijo), etiqueta(etiqueta) {
//        this->nodo = new NodoLista(etiqueta);
      };

      ContenedorPrincipal* sgtePrincipal;
//      NodoLista* nodo;
      std::string etiqueta;
      ContenedorSublista* primerHijo;
      ContenedorSublista* ultimoHijo;
    };

    struct ContenedorSublista {
        ContenedorSublista(ContenedorPrincipal* nodo) : nodo(nodo) {};
        ContenedorSublista* sgte;
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
    void PonerRaiz(std::string etiqueta);


//    void AgregarHijo(int etiqueta, TipoNodo elemento);
    ContenedorPrincipal* AgregarHijo(ContenedorPrincipal* nodoPadre, std::string etiqueta);


//    void AgregarHijoMasDerecho(TipoNodo elemento);
    ContenedorPrincipal* AgregarHijoMasDerecho(ContenedorPrincipal* nodoPadre, std::string etiqueta);

//    void BorrarHoja(std::string etiqueta);
    void BorrarHoja(ContenedorPrincipal* nodo);

    ContenedorPrincipal* Raiz();

    ContenedorPrincipal* Padre(ContenedorPrincipal* nodoHijo);

    ContenedorPrincipal* HijoMasIzquierdo(ContenedorPrincipal* nodo);

    ContenedorPrincipal* HermanoDerecho(ContenedorPrincipal* nodo);

    std::string Etiqueta(ContenedorPrincipal* nodo);

    void ModificaEtiqueta(std::string etiqueta, ContenedorPrincipal* nodo);

    int NumNodos();
} Arbol;

#endif //TAREA_PROGRAMADA_LISTAHIJOS_HPP
