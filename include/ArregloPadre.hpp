//
// Created by jean on 14/10/22.
//

#ifndef TAREA_PROGRAMADA_ARREGLOSENALADORPADRE_H
#define TAREA_PROGRAMADA_ARREGLOSENALADORPADRE_H

#include <vector>
#include <string>

//template <typename TipoNodo>
typedef class ArregloPadre {
    struct contenedorArreglo {
//        TipoNodo* nodo;
        contenedorArreglo(int et, int padre, int nodo_id) : etiqueta(et), padre(padre), nodo_id(nodo_id) {};
        contenedorArreglo() {};
        // Nodo nulo es constructor vacio
        // Nodo_id va a tener la pos del arreglo empezando en 0, pero por fuera, cuando manden nodo_id tengo que restarle
        // 1 porque para el usuario, el arreglo va a empezar en 1.
        int nodo_id;
        int etiqueta;
        int padre;
    };
public:
    std::vector<contenedorArreglo> arreglo;

    ArregloPadre() {};
    ~ArregloPadre() {};

    void Crear();

    void Destruir();

//    void PonerRaiz(TipoNodo elemento);
    void PonerRaiz(int etiqueta);


//    void AgregarHijo(int etiqueta, TipoNodo elemento);
    int AgregarHijo(int nodoPadre, int etiqueta);


//    void AgregarHijoMasDerecho(TipoNodo elemento);
    int AgregarHijoMasDerecho(int nodoPadre, int etiqueta);

//    void BorrarHoja(std::string etiqueta);
    void BorrarHoja(int nodo_id_externo);

    int Raiz();

    int Padre(int nodo_id_externo);

    int HijoMasIzquierdo(int nodo_id_externo);

    int HermanoDerecho(int nodo_id_hermano);

    int Etiqueta(int nodo_id_externo);

    void ModificaEtiqueta(int etiqueta, int nodo_id_externo);

    int NumNodos();

} Arbol;


#endif //TAREA_PROGRAMADA_ARREGLOSENALADORPADRE_H
