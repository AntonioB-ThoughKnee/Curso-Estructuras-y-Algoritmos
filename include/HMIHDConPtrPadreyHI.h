#pragma once
using namespace std;
#include <memory>

typedef class HMIHDConPtrPadreyHI //typedef usado para el main()
{
private:

  static shared_ptr<HMIHDConPtrPadreyHI> raiz; /**< Raíz del árbol */
  shared_ptr<HMIHDConPtrPadreyHI> hijo; /**< Hijo del nodo definido   */
  shared_ptr<HMIHDConPtrPadreyHI> hermanoDerecho; /**< Hijo derecho del nodo definido  */
  shared_ptr<HMIHDConPtrPadreyHI> hermanoIzquierdo; /**< Hijo izquierdo del nodo definido  */
  shared_ptr<HMIHDConPtrPadreyHI> padre; /**<  Padre del nodo definido  */
  int etiqueta; /**< Etiqueta del modo definido */

public:

  /**
   * @brief Construir un árbol nuevo
   * 
Requiere: Ãrbol no inicializado
Efecto: Crea un Ã¡rbol vacÃ­o
Modifica: La existencia del Ãrbol
   */
  HMIHDConPtrPadreyHI();

  /**
   * @brief Construir un árbol nuevo
   * 
   * @param etiqueta Construir árbol nuevo con etiqueta
Requiere: Ãrbol no inicializado
Efecto: Crea un Ã¡rbol vacÃ­o
Modifica: La existencia del Ãrbol
   */
  HMIHDConPtrPadreyHI(int etiqueta);

  /**
   * @brief Destructor
Requiere: La existencia del Ã¡rbol
Efecto: Destruir un Ã¡rbol dejÃ¡ndolo inutilizable
Modifica: Deja el Ã¡rbol inutilizable
   */
  ~HMIHDConPtrPadreyHI();

  /**
   * @brief Coloca una raíz que no había en el árbol
   * 
   * @param etiqueta Etiqueta de la raíz
   * @return HMIHDConPtrPadreyHI& El nodo raíz agregado
   * ParÃ¡metros: Etiqueta
Requiere: Etiqueta para el nodo raÃ­z y Ã¡rbol va
Efecto: Coloca un nodo raÃ­z en el Ã¡rbol
Modifica: Agrega el nodo raÃ­z al Ã¡rbol
   */
  HMIHDConPtrPadreyHI& ponerRaiz(int etiqueta);

  /**
   * @brief Retornar la raíz del árbol
   * 
   * @return shared_ptr<HMIHDConPtrPadreyHI> Raíz del árbol
Requiere: Ãrbol con raÃ­z definida
Efecto: Retorna el nodo raÃ­z
Modifica: Nada
   */
  shared_ptr<HMIHDConPtrPadreyHI> Raiz();

  /**
   * @brief Agregar un hijo en la posición más barata
   * 
   * @param nodo Nodo al que se le va a agregar un hijo
   * @param etiqueta Etiqueta del nodo nuevo
   * @return shared_ptr<HMIHDConPtrPadreyHI>  Puntero al nodo agregado
   * 
Requiere: Nodo vÃ¡lido y etiqueta para el nodo hijo
Efecto: AÃ±adir un hijo en la posiciÃ³n mÃ¡s barata al nodo dado y retorna el nodo aÃ±adido
Modifica: Un nodo agregando un hijo
   */
  shared_ptr<HMIHDConPtrPadreyHI> agregarHijo(shared_ptr<HMIHDConPtrPadreyHI> nodo, int etiqueta);

  /**
   * @brief Agregar un hijo en la última posición de hermanos 
   * 
   * @param nodo Nodo al que se le va a agregar un hijo
   * @param etiqueta Etiqueta del nodo nuevo
   * @return shared_ptr<HMIHDConPtrPadreyHI> Puntero al nodo agregado
RRequiere: Nodo vÃ¡lido y etiqueta para el nodo hijo
fecto: AÃ±adir un hijo en la Ãºltima posiciÃ³n de los hijos del nodo dado, a la derecha,
retorna el nodo aÃ±adido
Modifica: Un nodo agregando un hijo
   */
  shared_ptr<HMIHDConPtrPadreyHI> agregarHijoMasDerecho (shared_ptr<HMIHDConPtrPadreyHI> nodo, int etiqueta);

  /**
   * @brief Borra una hoja del árbol
   * 
   * @param hoja Nodo hoja por ser eliminado
   * @return shared_ptr<HMIHDConPtrPadreyHI> Nodo hoja eliminado
Requiere: Nodo vÃ¡lido y que el nodo sea una hoja
Efecto: Elimina un nodo hoja del Ã¡rbol y lo retorna
Modifica: EliminaciÃ³n de un nodo
   */
   void borrarHoja(shared_ptr<HMIHDConPtrPadreyHI> hoja);

  /**
   * @brief Retorna el padre deun nodo dado
   * 
   * @param nodo Nodo al que se va a retornar su padre
   * @return shared_ptr<HMIHDConPtrPadreyHI>  Padre del nodo dado
Requiere: Nodo vÃ¡lido y que no sea raÃ­z
Efecto: Retorna el padre de un nodo dado
Modifica: Nada
   */
  shared_ptr<HMIHDConPtrPadreyHI> Padre(shared_ptr<HMIHDConPtrPadreyHI> nodo);

  /**
   * @brief Retorna el hijo más izquierdo de un nodo dado
   * 
   * @param nodo Nodo al que se va a retornar su hijo más izquierdo
   * @return shared_ptr<HMIHDConPtrPadreyHI> Hijo más izquierdo del nodo dado
Requiere: Nodo vÃ¡lido con al menos un hijo
Efecto: Regresa el primer hijo (hijo mÃ¡s izquierdo)
Modifica: Agrega un hijo a un nodo dado
   */
  shared_ptr<HMIHDConPtrPadreyHI> HMI(shared_ptr<HMIHDConPtrPadreyHI> nodo);

  /**
   * @brief Retorna el nodo hermano izquierdo de un nodo dado
   * 
   * @param nodo Nodo al que se va a retornar su hermano derecho
   * @return shared_ptr<HMIHDConPtrPadreyHI> Hermano derecho del nodo dado
Requiere: Nodo vÃ¡lido y la existencia de nodos hermanos
Efecto: Retorna el nodo hermano apuntado por el nodo dado (a la derecha)
Modifica: Nada
   */
  shared_ptr<HMIHDConPtrPadreyHI> HD(shared_ptr<HMIHDConPtrPadreyHI> nodo);

  /**
   * @brief Retorna la etiqueta de un nodo dado
   * 
   * @param nodo Nodo al que se va a retornar su  etiqueta 
   * @return int Etiqueta del nodo dado
Requiere: Nodo vÃ¡lido
Efecto: Retorna la etiqueta contenida en el nodo
Modifica: Nada
   */
  int Etiqueta(shared_ptr<HMIHDConPtrPadreyHI> nodo);

  /**
   * @brief Modifica la etiqueta de un nodo dado
   * 
   * @param nodo Nodo al que se le va a modificar  su etiqueta 
   * @param etiqueta Etiqueta nueva para el nodo dado 
   * @return HMIHDConPtrPadreyHI& Nodo al que se le agregó la etiqueta
Requiere: Nodo vÃ¡lido
Efecto: Modifica la etiqueta de el nodo
Modifica: La etiqueta de un nodo
   */
  HMIHDConPtrPadreyHI& modificarEtiqueta(shared_ptr<HMIHDConPtrPadreyHI> nodo, int etiqueta);

  /**
   * @brief Regresa la cantidad de nodos 
   * 
   * @return int Cantidad de nodos en el árbol 
Requiere: Ãrbol inicializado
Efecto: Retorna la cantidad de nodos existentes en un Ã¡rbol
Modifica: Na
   */
  int numNodos();
} Arbol;
