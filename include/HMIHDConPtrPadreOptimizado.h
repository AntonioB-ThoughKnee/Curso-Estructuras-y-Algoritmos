#pragma once
using namespace std;
#include <memory>

typedef class HMIHDConPtrPadreOptimizado //typedef usado para el main()
{
private:
  static shared_ptr<HMIHDConPtrPadreOptimizado> raiz; /**< Raíz del árbol */
  shared_ptr<HMIHDConPtrPadreOptimizado> hijo; /**< Hijo del nodo definido   */
  shared_ptr<HMIHDConPtrPadreOptimizado> hermano; /**<  hermano derecho del nodo definido  */
  bool tienePtrAlPadre; /**<  Booleano que define si el nodo apunta al padre o no */
  int etiqueta; /**< Etiqueta del modo definido */

public:

  /**
   * @brief Construir un árbol nuevo
   * 
   * @brief
   * @param
Requiere: Ãrbol no inicializado
   * @param
Efecto: Crea un Ã¡rbol vacÃ­o
   * @param
Modifica: La existencia del Ãrbol
   */
  HMIHDConPtrPadreOptimizado();

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
  HMIHDConPtrPadreOptimizado(int etiqueta);

  /**
   * @brief Destructor
   * @param
Requiere: La existencia del Ã¡rbol
   * @param
Efecto: Destruir un Ã¡rbol dejÃ¡ndolo inutilizable
   * @param
Modifica: Deja el Ã¡rbol inutilizable
   */
  void destruir();

   /**
    * @brief Destuye el objeto HMIHDConPtrPadreOptimizado
    * 
    */
  ~HMIHDConPtrPadreOptimizado();

  /**
   * @brief Coloca una raíz que no había en el árbol
   * 
   * @param etiqueta Etiqueta de la raíz
   * @return HMIHDConPtrPadreOptimizado& El nodo raíz agregado
   * 
   * @param
Requiere: Etiqueta para el nodo raÃ­z y Ã¡rbol vacio
   * @param
Efecto: Coloca un nodo raÃ­z en el Ã¡rbol
   * @param
Modifica: Agrega el nodo raÃ­z al Ã¡rbol
   */
  HMIHDConPtrPadreOptimizado& ponerRaiz(int etiqueta);

  /**
   * @brief Retornar la raíz del árbol
   * 
   * @return shared_ptr<HMIHDConPtrPadreOptimizado> Raíz del árbol
   * @param
Requiere: Ãrbol con raÃ­z definida
   * @param
Efecto: Retorna el nodo raÃ­z
   * @param
Modifica: Nada
   */
  shared_ptr<HMIHDConPtrPadreOptimizado> Raiz();

  /**
   * @brief Agregar un hijo en la posición más barata
   * 
   * @param nodo Nodo al que se le va a agregar un hijo
   * @param etiqueta Etiqueta del nodo nuevo
   * @return shared_ptr<HMIHDConPtrPadreOptimizado>  Puntero al nodo agregado
   * 
   * @param
Requiere: Nodo vÃ¡lido y etiqueta para el nodo hijo
   * @param
Efecto: AÃ±adir un hijo en la posiciÃ³n mÃ¡s barata al nodo dado y retorna el nodo aÃ±adido
   * @param
Modifica: Un nodo agregando un hijo
   */
  shared_ptr<HMIHDConPtrPadreOptimizado> agregarHijo(shared_ptr<HMIHDConPtrPadreOptimizado> nodo, int etiqueta);

  /**
   * @brief Agregar un hijo en la última posición de hermanos 
   * 
   * @param nodo Nodo al que se le va a agregar un hijo
   * @param etiqueta Etiqueta del nodo nuevo
   * @return shared_ptr<HMIHDConPtrPadreOptimizado> Puntero al nodo agregado
R  @param
Requiere: Nodo vÃ¡lido y etiqueta para el nodo hijo
   * @param
Efecto: AÃ±adir un hijo en la Ãºltima posiciÃ³n de los hijos del nodo dado, a la derecha
   * @param
Modifica: Un nodo agregando un hijo
   */
  shared_ptr<HMIHDConPtrPadreOptimizado> agregarHijoMasDerecho (shared_ptr<HMIHDConPtrPadreOptimizado> nodo, int etiqueta);

  /**
   * @brief Borra una hoja del árbol
   * 
   * @param hoja Nodo hoja por ser eliminado
   * @return shared_ptr<HMIHDConPtrPadreOptimizado> Nodo hoja eliminado
   * @param
Requiere: Nodo vÃ¡lido y que el nodo sea una hoja
   * @param
Efecto: Elimina un nodo hoja del Ã¡rbol y lo retorna
   * @param
Modifica: EliminaciÃ³n de un nodo
   */
  void borrarHoja(shared_ptr<HMIHDConPtrPadreOptimizado> hoja);

  /**
   * @brief Retorna el padre deun nodo dado
   * 
   * @param nodo Nodo al que se va a retornar su padre
   * @return shared_ptr<HMIHDConPtrPadreOptimizado>  Padre del nodo dado
   * @param
Requiere: Nodo vÃ¡lido y que no sea raÃ­z
   * @param
Efecto: Retorna el padre de un nodo dado
   * @param
Modifica: Nada
   */
  shared_ptr<HMIHDConPtrPadreOptimizado> Padre(shared_ptr<HMIHDConPtrPadreOptimizado> nodo);

  /**
   * @brief Retorna el hijo más izquierdo de un nodo dado
   * 
   * @param nodo Nodo al que se va a retornar su hijo más izquierdo
   * @return shared_ptr<HMIHDConPtrPadreOptimizado> Hijo más izquierdo del nodo dado
   * @param
Requiere: Nodo vÃ¡lido con al menos un hijo
   * @param
Efecto: Regresa el primer hijo (hijo mÃ¡s izquierdo)
   * @param
Modifica: Agrega un hijo a un nodo dado
   */
  shared_ptr<HMIHDConPtrPadreOptimizado> HMI(shared_ptr<HMIHDConPtrPadreOptimizado> nodo);

  /**
   * @brief Retorna el nodo hermano izquierdo de un nodo dado
   * 
   * @param nodo Nodo al que se va a retornar su hermano derecho
   * @return shared_ptr<HMIHDConPtrPadreOptimizado> Hermano derecho del nodo dado
   * @param
Requiere: Nodo vÃ¡lido y la existencia de nodos hermanos
   * @param
Efecto: Retorna el nodo hermano apuntado por el nodo dado (a la derecha)
   * @param
Modifica: Nada
   */
  shared_ptr<HMIHDConPtrPadreOptimizado> HD(shared_ptr<HMIHDConPtrPadreOptimizado> nodo);

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
  int Etiqueta(shared_ptr<HMIHDConPtrPadreOptimizado> nodo);

  /**
   * @brief Modifica la etiqueta de un nodo dado
   * 
   * @param nodo Nodo al que se le va a modificar  su etiqueta 
   * @param etiqueta Etiqueta nueva para el nodo dado 
   * @return HMIHDConPtrPadreOptimizado& Nodo al que se le agregó la etiqueta
   * @param
Requiere: Nodo vÃ¡lido
   * @param
Efecto: Modifica la etiqueta de el nodo
   * @param
Modifica: La etiqueta de un nodo
   */
  HMIHDConPtrPadreOptimizado& modificarEtiqueta(shared_ptr<HMIHDConPtrPadreOptimizado> nodo, int etiqueta);

  /**
   * @brief Regresa la cantidad de nodos 
   * 
   * @return int Cantidad de nodos en el árbol 
   * @param
Requiere: Ãrbol inicializado
   * @param
Efecto: Retorna la cantidad de nodos existentes en un Ã¡rbol
   * @param
Modifica: Nada
   */
  int numNodos();
} Arbol;
