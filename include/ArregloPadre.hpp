//
// Created by jean on 14/10/22.
//

#ifndef TAREA_PROGRAMADA_ARREGLOSENALADORPADRE_H
#define TAREA_PROGRAMADA_ARREGLOSENALADORPADRE_H

#include <vector>
#include <string>

//template <typename TipoNodo>
typedef class ArregloPadre {
public:
    struct Nodo{
        Nodo(int et) : indice(et){};
        int indice;
    };
    struct contenedorArreglo {
//        TipoNodo* nodo;
<<<<<<< HEAD:include/ArregloPadre.hpp
        contenedorArreglo(int et, int padre, int nodo_id) : etiqueta(et), padre(padre), nodo_id(nodo_id) {};
        contenedorArreglo() {};
        // Nodo nulo es constructor vacio
        // Nodo_id va a tener la pos del arreglo empezando en 0, pero por fuera, cuando manden nodo_id tengo que restarle
        // 1 porque para el usuario, el arreglo va a empezar en 1.
        int nodo_id;
        int etiqueta;
        int padre;
=======
        contenedorArreglo(int et, Nodo* padre, Nodo* nodo_id) : etiqueta(et), padre(padre), nodo_id(nodo_id) {};
        contenedorArreglo() {};
        // Nodo nulo es constructor vacio
        Nodo* nodo_id;
        int etiqueta;
        Nodo* padre;
>>>>>>> 380c073555ead46279bcd5cc16d9dd988299bfaf:include/ArregloSenaladorPadre.h
    };


    std::vector<contenedorArreglo> arreglo;

    ArregloPadre() {};
    ~ArregloPadre() {};

    void Crear();

    void Destruir();

//    void PonerRaiz(TipoNodo elemento);
    void PonerRaiz(int etiqueta);


//    void AgregarHijo(int etiqueta, TipoNodo elemento);
<<<<<<< HEAD:include/ArregloPadre.hpp
    int AgregarHijo(int nodoPadre, int etiqueta);


//    void AgregarHijoMasDerecho(TipoNodo elemento);
    int AgregarHijoMasDerecho(int nodoPadre, int etiqueta);
=======
    Nodo* AgregarHijo(Nodo* nodoPadre, int etiqueta);


//    void AgregarHijoMasDerecho(TipoNodo elemento);
    Nodo* AgregarHijoMasDerecho(Nodo* nodoPadre, int etiqueta);
>>>>>>> 380c073555ead46279bcd5cc16d9dd988299bfaf:include/ArregloSenaladorPadre.h

//    void BorrarHoja(int etiqueta);
    void BorrarHoja(Nodo* nodo_id_externo);

    Nodo* Raiz();

    Nodo* Padre(Nodo* nodo_id_externo);

    Nodo* HMI(Nodo* nodo_id_externo);

    Nodo* HD(Nodo* nodo_id_hermano);

<<<<<<< HEAD:include/ArregloPadre.hpp
    int Etiqueta(int nodo_id_externo);

    void ModificaEtiqueta(int etiqueta, int nodo_id_externo);
=======
    int Etiqueta(Nodo* nodo_id_externo);

    void ModificaEtiqueta(Nodo* nodo_id_externo, int etiqueta);
>>>>>>> 380c073555ead46279bcd5cc16d9dd988299bfaf:include/ArregloSenaladorPadre.h

    int NumNodos();

} Arbol;


#endif //TAREA_PROGRAMADA_ARREGLOSENALADORPADRE_H
