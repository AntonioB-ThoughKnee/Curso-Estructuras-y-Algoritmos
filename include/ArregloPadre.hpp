//
// Created by jean on 14/10/22.
//

#ifndef TAREA_PROGRAMADA_ARREGLOSENALADORPADRE_H
#define TAREA_PROGRAMADA_ARREGLOSENALADORPADRE_H

#include <vector>
#include <string>
// #include "Nodo.h"

typedef class ArregloPadre {
public:
    // struct Nodo {
    //     Nodo(int nodo_id) : nodo(nodo_id) {};
    //     int nodo;
    // };
    typedef struct contenedorArreglo {
//        TipoNodo* nodo;
        contenedorArreglo(int et, contenedorArreglo* padre, int nodo_id) : etiqueta(et), nodo_id(nodo_id) {
            this->padre = padre;
        };
        // contenedorArreglo() {};
        // Nodo nulo es constructor vacio
        // Nodo_id va a tener la pos del arreglo empezando en 0, pero por fuera, cuando manden nodo_id tengo que restarle
        // 1 porque para el usuario, el arreglo va a empezar en 1.
        int nodo_id;
        int etiqueta;
        contenedorArreglo* padre;
    } Nodo;


    std::vector<contenedorArreglo*> arreglo;

    ArregloPadre() {};
    ~ArregloPadre() {};

    void Crear();

    void Destruir();

//    void PonerRaiz(TipoNodo elemento);
    void PonerRaiz(int etiqueta);


//    void AgregarHijo(int etiqueta, TipoNodo elemento);
    ArregloPadre::contenedorArreglo* AgregarHijo(contenedorArreglo* nodoPadre,int etiqueta);


//    void AgregarHijoMasDerecho(TipoNodo elemento);
    ArregloPadre::contenedorArreglo* AgregarHijoMasDerecho(contenedorArreglo* nodoPadre, int etiqueta);

//    void BorrarHoja(std::string etiqueta);
    void BorrarHoja(ArregloPadre::contenedorArreglo* nodo_id_externo);

    ArregloPadre::contenedorArreglo* Raiz();

    ArregloPadre::contenedorArreglo* Padre(ArregloPadre::contenedorArreglo* nodo_id_externo);

    ArregloPadre::contenedorArreglo* HijoMasIzquierdo(ArregloPadre::contenedorArreglo* nodo_id_externo);

    ArregloPadre::contenedorArreglo* HermanoDerecho(ArregloPadre::contenedorArreglo* nodo_id_hermano);

    int Etiqueta(ArregloPadre::contenedorArreglo* nodo_id_externo);

    void ModificarEtiqueta(ArregloPadre::contenedorArreglo* nodo_id_externo, int etiqueta);

    int NumNodos();

} Arbol;


#endif //TAREA_PROGRAMADA_ARREGLOSENALADORPADRE_H
