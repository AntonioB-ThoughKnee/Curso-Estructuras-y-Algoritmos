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
        contenedorArreglo(int et, Nodo* padre, Nodo* nodo_id) : etiqueta(et), padre(padre), nodo_id(nodo_id) {};
        contenedorArreglo() {};
        // Nodo nulo es constructor vacio
        Nodo* nodo_id;
        int etiqueta;
        Nodo* padre;
    };


    std::vector<contenedorArreglo> arreglo;

    ArregloPadre() {};
    ~ArregloPadre() {};

    void Crear();

    void Destruir();

//    void PonerRaiz(TipoNodo elemento);
    void PonerRaiz(int etiqueta);


//    void AgregarHijo(int etiqueta, TipoNodo elemento);
    Nodo* AgregarHijo(Nodo* nodoPadre, int etiqueta);


//    void AgregarHijoMasDerecho(TipoNodo elemento);
    Nodo* AgregarHijoMasDerecho(Nodo* nodoPadre, int etiqueta);

//    void BorrarHoja(int etiqueta);
    void BorrarHoja(Nodo* nodo_id_externo);

    Nodo* Raiz();

    Nodo* Padre(Nodo* nodo_id_externo);

    Nodo* HMI(Nodo* nodo_id_externo);

    Nodo* HD(Nodo* nodo_id_hermano);

    int Etiqueta(Nodo* nodo_id_externo);

    void ModificaEtiqueta(Nodo* nodo_id_externo, int etiqueta);

    int NumNodos();

} Arbol;


#endif //TAREA_PROGRAMADA_ARREGLOSENALADORPADRE_H
