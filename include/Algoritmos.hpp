#ifndef ALGORITMOSHPP
#define ALGORITMOSHPP

#include "ListaIndexadaPlantilla.hpp"
#include "ColaPlantilla.hpp"
// #include "ArregloPadre.hpp"
// #include "HMIHDConPtrPadreOptimizado.hpp"
// #include "HMIHDConPtrPadreyHI.hpp"
// #include "ListaHijos.hpp"
#include "HMIHDConContador.hpp"


/**
 * @brief Struct de pares
 * @param nodo puntero a nodo de los arbole
 * se utiliza para iterar entre ellos.
 * @param nivel entero indicando el nivel del nodo. 
 */
struct Pares
{
   Arbol::Nodo* nodo;
   int nivel;
   Pares(){
      this->nodo=nullptr;
      this->nivel=0;
   }
   Pares(Arbol::Nodo* nodo,int nivel){
      this->nodo=nodo;
      this->nivel=nivel;
   }
};

/**
 * @brief Clase controladora del menu de algoritmos.
 * La clase contiene todos los algoritmos y un menu 
 * que los llama.
 * @param arbol puntero al arbol utilizado para probar los 
 * algoritmos.
 * @param nivelMaximo nivel maximo del arbol, variable global 
 * usada en el algoritmo contarNiveles.
 */
class Algoritmos{
private:
Arbol* arbol;
int nivelMaximo;
public:
Algoritmos();
~Algoritmos();
void inicializarArbol();
void menu();

Algoritmos(Arbol* arbol);
/**
 * @brief Busca e imprime la etiqueta del hermano izquierdo de un nodo dado
 * 
 * @param nodo Nodo al que se va a buscar su hermano
 * 
 * @param Requiere: Nodo válido que contenga hermano izquierdo, que el árbol no contenga
 * etiquetas repetidas. 
 * @param Efecto: Imprime la etiqueta del hermano izquierdo de un nodo dado
 * @param Modifica: Nada
 */
void hermanoIzquierdo(Arbol::Nodo* nodo);  // Por dentro imprime la etiqueta, no devuelve nada entonces.

/**
 * @brief Verifica si el árbol contiene etiquetas 
 * repetidas e imprime verdadero o falso según el caso
 * 
* @param Requiere: Árbol válido e inicializado. 
* @param Efecto: Imprime si el árbol contiene etiquetas repetidas o no.
* @param Modifica:  No modifica el árbol.
 */
void contieneEtiquetasRepetidas();  // Imprime por dentro el mensaje de verdadero o falso.

/**
 * @brief Calcula la profundidad en la que está localizado un nodo 
 * e imprime la profundidad
 * 
 * @param nodoBuscar Nodo al que se va a buscar su profundidad
 * 
 * @param Requiere: Arbol válido e inicializado, nodo válido y perteneciente al
 * árbol. Árbol no contenga etiquetas repetidas.
 * @param Efecto: Imprime la profundidad del nodo dado en el árbol
 * @param Modifica: No modifica el árbol.
 */
void profundidadNodo(Arbol::Nodo* nodoBuscar);  // Imprime por dentro el numero.

/**
 * @brief  Calcula e imprime la cantidad de niveles del árbol en PreOrden
 * 
 * @param Requiere: Árbol válido e inicializado.
 * @param Efecto: Imprimir la cantidad de niveles del árbol
 * @param Modifica: No modifica el árbol.
 */
void cantidadNivelesPreOrden();  // Imprime la cantidad de niveles por dentro.

int contarPorNiveles(); // No definido. BORRAR si no es importante

/**
 * @brief  Calcula e imprime la cantidad de niveles del  árbol
 * haciendo un recorrido por Niveles.
 * 
 * @param Requiere: Arbol inicializado, variable nivelMax pasado como variables globales
 * @param Efecto: Imprimir la cantidad de niveles del árbol
 * @param Modifica: Nada
 */
void cantidadNivelesPorNiveles();

void listarPorNivel();// No definido. BORRAR si no es importante

void contarNivelesR(Arbol::Nodo* nodo,int nivelActual); // No definido. BORRAR si no es importante

/**
 * @brief Imprime las etiquetas de los nodos que se hallan 
 * en un nivel dado del árbol
 * 
 * @param nivel Nivel el cual se desea saber las etiquetas 
 * 
 * @param Requiere: Arbol inicializado pasado como variable global, nivelDeseado
 tiene que ser un nivel valido en el arbol
 * @param Efecto: Imprimir las etiquetas de los nodos en un nivel dado del árbol
 * @param Modifica: Nada
 */
void listarEtiquetasNivel(int nivelDeseado);

/**
 * @brief Función auxiliar de la función "listarEtiquetasNivel"
 * 
 * @param nodo Nodo actual
 * @param nivelActual Nivel actual
 * @param nivelDeseado Nivel el cual se desea conocer las etiquetas
 */
void listarEtiquetasNivelR(Arbol::Nodo* nodo, int nivelActual,int nivelDeseado);

/**
 * @brief Imprime las etiquetas del árbol en un recorrido por Pre Orden
 * 
 * @param Requiere: Arbol inicializado pasado como variable global
 * @param Efecto: Imprimir las etiquetas de los nodos de un arbol
 haceindo un recorrido por Pre Orden
 * @param Modifica: Nada
 */
void listarPreOrden();

/**
 * @brief Función auxiliar de la función "listarPreOrden"
 * 
 * @param nodo Nodo actual
 * 
 */
void listarPreOrdenR(Arbol::Nodo* nodo);

/**
 * @brief Imprime las etiquetas del árbol en un recorrido por Niveles
 * 
 * @param Requiere: Arbol inicializado pasado como variable global
 * @param Efecto: Imprimir las etiquetas de los nodos en un recorrido por Niveles
 * @param Modifica: Nada
 */
void listarPorNiveles();

/**
* @brief Busca una  etiqueta en un árbol dado y regresa el nodo que tenga esa etiqueta si existe ese nodo
* 
* @param etiqueta Valor contenido por algún nodo o ninguno
* @param A Arbol por el cual se realiza la búsqueda
* @return Arbol::Nodo*  Nodo que contiene la etiqueta o nodo nulo
* 
* @param Requiere: Etiqueta valida y Arbol inicializado con al menos raíz definida
* @param Efecto: Retorna un nodo que contenga la etiqueta dada o nodo nulo
* @param Modifica: Nada
*/
Arbol::Nodo* BuscarEtiqueta(int etiqueta, Arbol* A);

/**
* @brief Crea un arbol completo con una lista indexada y un numero de nodos por hijo
* 
* @param hijos Cantidad de nodos hijos que tendrá cada nodo
* @param lista Lista indexada que contiene el recorrido de un árbol por niveles
* @return Arbol* Arbol creado a base de los parámetros
* 
* @param Requiere: Cantidad de hijos y lista indexada que debe ser de tamaño "(k**i-1) / (k-1)", donde "k" = hijos por nodo e "i" = nivel de profundidad del arbol
* @param Efecto: Retorna un árbol completo con los elementos de la lista indexada
* @param Modifica: Nada
*/
Arbol* HacerArbol(int hijos, ListaIndexada<int> lista);

/**
* @brief Elimina un nodo dado y el subarbol que contiene el nodo de un árbol dado
* 
* @param nodo Nodo ssubarbol que será eliminado
* @param A Arbol al que se aplicará la eliminación del subárbol
* 
* @param Requiere: Nodo válido diferente a la raíz y Arbol inicializado 
* @param Efecto: Eliminar subárbol contenido en un nodo dado a un árbol dado
* @param Modifica: Un árbol eliminando un subárbol del mismo
*/
void EliminarSubarbol(Arbol::Nodo* nodo, Arbol* A);
// ===========================================
// METODO PARA CONTIENE ETIQUETAS REPETIDAS
// bool BuscarRepetidaEnLista(int etiqueta, ListaIndexada<Arbol::Nodo*>* L);

// ===============================================================
// METODO PARA PROFUNDIDAD NODO
void ListarPreOrdenRProfundidad(Arbol::Nodo* nodo, int nivel,
  Arbol::Nodo* nodoBuscar, int* nivelRet, bool* encontrado);

// ==========================================================
// METODO PARA CANTIDAD DE NIVELES PRE ORDEN
void ListarPreOrdenR(Arbol::Nodo* nodo, int nivel, int* nivelRet);

};

#endif