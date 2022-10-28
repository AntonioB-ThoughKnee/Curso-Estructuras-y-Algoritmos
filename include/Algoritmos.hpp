#ifndef ALGORITMOSHPP
#define ALGORITMOSHPP

#include "ListaIndexadaPlantilla.hpp"
#include "Cola.hpp"
//#include "ArregloSenaladorPadre.hpp"
//#include "HMIHDConPtrPadreOptimizado.hpp"
//#include "HMIHDConPtrPadreyHI.hpp"
//#include "ListaHijos.hpp"
#include "HMIHDConContador.hpp"
#include "ListaIndexadaPlantilla.hpp"

class Algoritmos{
private:
Arbol* arbol;
int nivelMaximo;
public:
Algoritmos();
~Algoritmos();
//TODO: Programar este metodo
void inicializarArbol();
void menu();

void hermanoIzquierdo(Arbol::Nodo*);  // Por dentro imprime la etiqueta, no devuelve nada entonces.
void contieneEtiquetasRepetidas();  // Imprime por dentro el mensaje de verdadero o falso.
void profundidadNodo(Arbol::Nodo*);  // Imprime por dentro el numero.
void cantidadNivelesPreOrden();  // Imprime la cantidad de niveles por dentro.
int contarPorNiveles();
void listaEtiquetasNivel(int nivel);
void recorridoPreOrden();
void recorridoPorNiveles();
void cantidadNivelesPorNiveles();
void listarEtiquetasNivel(int nivelDeseado);
void listarPreOrden();
void listarPorNivel();
void contarNivelesR(Arbol::Nodo* nodo,int nivelActual);
void listarEtiquietasNivel(int nivelDeseado);
void listarEtiquietasNivelR(Arbol::Nodo* nodo, int nivelActual,int nivelDeseado);
void listarPreOrden();
void listarPreOrdenR(Arbol::Nodo* nodo);
void listarPorNiveles();
/**
* @brief Busca una  etiqueta en un árbol dado y regresa el nodo que tenga esa etiqueta si existe ese nodo
* 
* @param etiqueta Valor contenido por algún nodo o ninguno
* @param A Arbol por el cual se realiza la búsqueda
* @return Arbol::Nodo* Nodo que contiene la etiqueta o nodo nulo
* 
   * @param
Requiere: Etiqueta valida y Arbol inicializado con al menos raíz definida
   * @param
Efecto: Retorna un nodo que contenga la etiqueta dada o nodo nulo
   * @param
Modifica: Nada
*/
Arbol::Nodo* BuscarEtiqueta(int etiqueta, Arbol* A);

/**
* @brief / Crea un arbol completo con una lista indexada y un numero de nodos por hijo
* 
* @param hijos Cantidad de nodos hijos que tendrá cada nodo
* @param lista Lista indexada que contiene el recorrido de un árbol por niveles
* @return Arbol* Arbol creado a base de los parámetros
* 
   * @param
Requiere: Cantidad de hijos y lista indexada que debe ser de tamaño "(k**i-1) / (k-1)", donde "k" = hijos por nodo e "i" = nivel de profundidad del arbol
   * @param
Efecto: Retorna un árbol completo con los elementos de la lista indexada
   * @param
Modifica: Nada
*/
Arbol* HacerArbol(int hijos, ListaIndexada<int> lista);

/**
* @brief Elimina un nodo dado y el subarbol que contiene el nodo de un árbol dado
//  * 
* @param nodo Nodo ssubarbol que será eliminado
* @param A Arbol al que se aplicará la eliminación del subárbol
* 
   * @param
Requiere: Nodo válido y Arbol inicializado con al menos raíz definida
   * @param
Efecto: Eliminar subárbol contenido en un nodo dado a un árbol dado
   * @param
Modifica: Un árbol eliminando un subárbol del mismo
*/
void EliminarSubarbol(Arbol::Nodo* nodo, Arbol* A);
};

#endif