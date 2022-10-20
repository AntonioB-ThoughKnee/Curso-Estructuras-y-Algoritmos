//
// Created by Jean C on 10/19/2022.
//

#ifndef UNTITLED_HMIHDCONCONTADOR_HPP
#define UNTITLED_HMIHDCONCONTADOR_HPP

#pragma once
using namespace std;
#include <memory>

typedef class HMIHDConContador //typedef usado para el main()
{
public:
    struct Nodo
    {
        Nodo()
                : hijo(nullptr), hermano(nullptr){};
        Nodo(int etiqueta)
                : hijo(nullptr), hermano(nullptr), etiqueta(etiqueta){};
        Nodo* hijo; /**< Hijo del nodo definido   */
        Nodo* hermano; /**<  hermano derecho del nodo definido  */
        int etiqueta; /**< Etiqueta del nodo definido */
    };
    Nodo* raiz; /**< Raíz del árbol */
    int contador; /**< Cantidad de nodos del árbol  */


    /**
     * @brief Construir un árbol nuevo
     *
     * @param
  Requiere: Ãrbol no inicializado
     * @param
  Efecto: Crea un Ã¡rbol vacÃ­o
     * @param
  Modifica: La existencia del Ãrbol
     */
    void Crear();
    HMIHDConContador() {};

    /**
     * @brief Construir un árbol nuevo
     *
     * @param etiqueta Construir árbol nuevo con etiqueta
     * @param
  Requiere: Ãrbol no inicializado
     * @param
  Efecto: Crea un Ã¡rbol vacÃ­o
     * @param
  Modifica: La existencia del Ãrbol
     */
    HMIHDConContador(int etiqueta);

    /**
     * @brief Destructor
     * @param
  Requiere: La existencia del Ã¡rbol
     * @param
  Efecto: Destruir un Ã¡rbol dejÃ¡ndolo inutilizable
     * @param
  Modifica: Deja el Ã¡rbol inutilizable
     */
    void Destruir();

    /**
     * @brief Destuye el objeto HMIHDConContador
     *
     */
    ~HMIHDConContador();

    /**
     * @brief Coloca una raíz que no había en el árbol
     *
     * @param etiqueta Etiqueta de la raíz
     * @return HMIHDConContador& El nodo raíz agregado
     * ParÃ¡metros: Etiqueta
     * @param
  Requiere: Etiqueta para el nodo raÃ­z y Ã¡rbol vacio
     * @param
  Efecto: Coloca un nodo raÃ­z en el Ã¡rbol
     * @param
  Modifica: Agrega el nodo raÃ­z al Ã¡rbol
     */
    HMIHDConContador& PonerRaiz(int etiqueta);

    /**
     * @brief Retornar la raíz del árbol
     *
     * @return HMIHDConContador*Raíz del árbol
     * @param
  Requiere: Ãrbol con raÃ­z definida
     * @param
  Efecto: Retorna el nodo raÃ­z
     * @param
  Modifica: Nada
     */
    Nodo* Raiz();

    /**
     * @brief Agregar un hijo en la posición más barata
     *
     * @param nodo Nodo al que se le va a agregar un hijo
     * @param etiqueta Etiqueta del nodo nuevo
     * @return Nodo*  Puntero al nodo agregado
     *
     * @param
  Requiere: Nodo vÃ¡lido y etiqueta para el nodo hijo
     * @param
  Efecto: AÃ±adir un hijo en la posiciÃ³n mÃ¡s barata al nodo dado y retorna el nodo aÃ±adido
     * @param
  Modifica: Un nodo agregando un hijo
     */
    Nodo* AgregarHijo(Nodo* nodo, int etiqueta);

    /**
     * @brief Agregar un hijo en la última posición de hermanos
     *
     * @param nodo Nodo al que se le va a agregar un hijo
     * @param etiqueta Etiqueta del nodo nuevo
     * @return Nodo* Puntero al nodo agregado
    @param
  Requiere: Nodo vÃ¡lido y etiqueta para el nodo hijo
    @param
  Efecto: AÃ±adir un hijo en la Ãºltima posiciÃ³n de los hijos del nodo dado, a la derecha,
  retorna eR  nodo aÃ±adido
     * @param
  Modifica: Un nodo agregando un hijo
     */
    Nodo* AgregarHijoMasDerecho (Nodo* nodo, int etiqueta);

    /**
     * @brief Borra una hoja del árbol
     *
     * @param hoja Nodo hoja por ser eliminado
     * @return Nodo* Nodo hoja eliminado
     * @param
  Requiere: Nodo vÃ¡lido y que el nodo sea una hoja
     * @param
  Efecto: Elimina un nodo hoja del Ã¡rbol y lo retorna
     * @param
  Modifica: EliminaciÃ³n de un nodo
     */
    void BorrarHoja(Nodo* hoja);

    /**
     * @brief Retorna el padre deun nodo dado
     *
     * @param nodo Nodo al que se va a retornar su padre
     * @return Nodo*  Padre del nodo dado
     * @param
  Requiere: Nodo vÃ¡lido y que no sea raÃ­z
     * @param
  Efecto: Retorna el padre de un nodo dado
     * @param
  Modifica: Nada
     */
    Nodo* Padre(Nodo* nodo);

    /**
     * @brief Retorna el hijo más izquierdo de un nodo dado
     *
     * @param nodo Nodo al que se va a retornar su hijo más izquierdo
     * @return Nodo* Hijo más izquierdo del nodo dado
     * @param
  Requiere: Nodo vÃ¡lido con al menos un hijo
     * @param
  Efecto: Regresa el primer hijo (hijo mÃ¡s izquierdo)
     * @param
  Modifica: Agrega un hijo a un nodo dado
     */
    Nodo* HijoMasIzquierdo(Nodo* nodo);

    /**
     * @brief Retorna el nodo hermano izquierdo de un nodo dado
     *
     * @param nodo Nodo al que se va a retornar su hermano derecho
     * @return Nodo* Hermano derecho del nodo dado
     * @param
  Requiere: Nodo vÃ¡lido y la existencia de nodos hermanos
     * @param
  Efecto: Retorna el nodo hermano apuntado por el nodo dado (a la derecha)
     * @param
  Modifica: Nada
     */
    Nodo* HermanoDerecho(Nodo* nodo);

    /**
     * @brief Retorna la etiqueta de un nodo dado
     *
     * @param nodo Nodo al que se va a retornar su  etiqueta
     * @return int Etiqueta del nodo dado
     * @param
  Requiere: Nodo vÃ¡lido
     * @param
  Efecto: Retorna la etiqueta contenida en el nodo
     * @param
  Modifica: Nada
     */
    int Etiqueta(Nodo* nodo);

    /**
     * @brief Modifica la etiqueta de un nodo dado
     *
     * @param nodo Nodo al que se le va a modificar  su etiqueta
     * @param etiqueta Etiqueta nueva para el nodo dado
     * @return HMIHDConContador& Nodo al que se le agregó la etiqueta
     * @param
  Requiere: Nodo vÃ¡lido
     * @param
  Efecto: Modifica la etiqueta de el nodo
     * @param
  Modifica: La etiqueta de un nodo
     */
    HMIHDConContador& ModificarEtiqueta(Nodo* nodo, int etiqueta);

    /**
     * @brief Regresa la cantidad de nodos
     *
     * @return int Cantidad de nodos en el árbol
     * @param
  Requiere: Ãrbol inicializado
     * @param
  Efecto: Retorna la cantidad de nodos existentes en un Ã¡rbol
     * @param
  Modifica: Na
     */
    int NumNodos();
} Arbol;



#endif //UNTITLED_HMIHDCONCONTADOR_HPP
