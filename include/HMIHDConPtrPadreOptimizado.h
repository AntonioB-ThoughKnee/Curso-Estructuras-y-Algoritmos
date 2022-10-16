#pragma once
using namespace std;

typedef class HMIHDConPtrPadreOptimizado //typedef usado para el main()
{
private:
  static HMIHDConPtrPadreOptimizado* raiz; /**< Raíz del árbol */
  HMIHDConPtrPadreOptimizado* hijo; /**< Hijo del nodo definido   */
  HMIHDConPtrPadreOptimizado* hermano; /**<  hermano derecho del nodo definido  */
  bool tienePtrAlPadre; /**<  Booleano que define si el nodo apunta al padre o no */
  int etiqueta; /**< Etiqueta del modo definido */

public:

  /**
   * @brief Construir un árbol nuevo
   * 
Requiere: Ãrbol no inicializado
Efecto: Crea un Ã¡rbol vacÃ­o
Modifica: La existencia del Ãrbol
   */
  HMIHDConPtrPadreOptimizado();

  /**
   * @brief Construir un árbol nuevo
   * 
   * @param etiqueta Construir árbol nuevo con etiqueta
Requiere: Ãrbol no inicializado
Efecto: Crea un Ã¡rbol vacÃ­o
Modifica: La existencia del Ãrbol
   */
  HMIHDConPtrPadreOptimizado(int etiqueta);

  /**
   * @brief Destructor
Requiere: La existencia del Ã¡rbol
Efecto: Destruir un Ã¡rbol dejÃ¡ndolo inutilizable
Modifica: Deja el Ã¡rbol inutilizable
   */
  ~HMIHDConPtrPadreOptimizado();

  /**
   * @brief Coloca una raíz que no había en el árbol
   * 
   * @param etiqueta Etiqueta de la raíz
   * @return HMIHDConPtrPadreOptimizado& El nodo raíz agregado
   * ParÃ¡metros: Etiqueta
Requiere: Etiqueta para el nodo raÃ­z y Ã¡rbol va
Efecto: Coloca un nodo raÃ­z en el Ã¡rbol
Modifica: Agrega el nodo raÃ­z al Ã¡rbol
   */
  HMIHDConPtrPadreOptimizado& ponerRaiz(int etiqueta);

  /**
   * @brief Retornar la raíz del árbol
   * 
   * @return HMIHDConPtrPadreOptimizado* Raíz del árbol
Requiere: Ãrbol con raÃ­z definida
Efecto: Retorna el nodo raÃ­z
Modifica: Nada
   */
  HMIHDConPtrPadreOptimizado* Raiz();

  /**
   * @brief Agregar un hijo en la posición más barata
   * 
   * @param nodo Nodo al que se le va a agregar un hijo
   * @param etiqueta Etiqueta del nodo nuevo
   * @return HMIHDConPtrPadreOptimizado*  Puntero al nodo agregado
   * 
Requiere: Nodo vÃ¡lido y etiqueta para el nodo hijo
Efecto: AÃ±adir un hijo en la posiciÃ³n mÃ¡s barata al nodo dado y retorna el nodo aÃ±adido
Modifica: Un nodo agregando un hijo
   */
  HMIHDConPtrPadreOptimizado* agregarHijo(HMIHDConPtrPadreOptimizado* nodo, int etiqueta);

  /**
   * @brief Agregar un hijo en la última posición de hermanos 
   * 
   * @param nodo Nodo al que se le va a agregar un hijo
   * @param etiqueta Etiqueta del nodo nuevo
   * @return HMIHDConPtrPadreOptimizado* Puntero al nodo agregado
RRequiere: Nodo vÃ¡lido y etiqueta para el nodo hijo
fecto: AÃ±adir un hijo en la Ãºltima posiciÃ³n de los hijos del nodo dado, a la derecha,
retorna el nodo aÃ±adido
Modifica: Un nodo agregando un hijo
   */
  HMIHDConPtrPadreOptimizado* agregarHijoMasDerecho (HMIHDConPtrPadreOptimizado* nodo, int etiqueta);

  /**
   * @brief Borra una hoja del árbol
   * 
   * @param hoja Nodo hoja por ser eliminado
   * @return HMIHDConPtrPadreOptimizado* Nodo hoja eliminado
Requiere: Nodo vÃ¡lido y que el nodo sea una hoja
Efecto: Elimina un nodo hoja del Ã¡rbol y lo retorna
Modifica: EliminaciÃ³n de un nodo
   */
  HMIHDConPtrPadreOptimizado* borrarHoja(HMIHDConPtrPadreOptimizado* hoja);

  /**
   * @brief Retorna el padre deun nodo dado
   * 
   * @param nodo Nodo al que se va a retornar su padre
   * @return HMIHDConPtrPadreOptimizado*  Padre del nodo dado
Requiere: Nodo vÃ¡lido y que no sea raÃ­z
Efecto: Retorna el padre de un nodo dado
Modifica: Nada
   */
  HMIHDConPtrPadreOptimizado* Padre(HMIHDConPtrPadreOptimizado* nodo);

  /**
   * @brief Retorna el hijo más izquierdo de un nodo dado
   * 
   * @param nodo Nodo al que se va a retornar su hijo más izquierdo
   * @return HMIHDConPtrPadreOptimizado* Hijo más izquierdo del nodo dado
Requiere: Nodo vÃ¡lido con al menos un hijo
Efecto: Regresa el primer hijo (hijo mÃ¡s izquierdo)
Modifica: Agrega un hijo a un nodo dado
   */
  HMIHDConPtrPadreOptimizado* HMI(HMIHDConPtrPadreOptimizado* nodo);

  /**
   * @brief Retorna el nodo hermano izquierdo de un nodo dado
   * 
   * @param nodo Nodo al que se va a retornar su hermano derecho
   * @return HMIHDConPtrPadreOptimizado* Hermano derecho del nodo dado
Requiere: Nodo vÃ¡lido y la existencia de nodos hermanos
Efecto: Retorna el nodo hermano apuntado por el nodo dado (a la derecha)
Modifica: Nada
   */
  HMIHDConPtrPadreOptimizado* HD(HMIHDConPtrPadreOptimizado* nodo);

  /**
   * @brief Retorna la etiqueta de un nodo dado
   * 
   * @param nodo Nodo al que se va a retornar su  etiqueta 
   * @return int Etiqueta del nodo dado
Requiere: Nodo vÃ¡lido
Efecto: Retorna la etiqueta contenida en el nodo
Modifica: Nada
   */
  int Etiqueta(HMIHDConPtrPadreOptimizado* nodo);

  /**
   * @brief Modifica la etiqueta de un nodo dado
   * 
   * @param nodo Nodo al que se le va a modificar  su etiqueta 
   * @param etiqueta Etiqueta nueva para el nodo dado 
   * @return HMIHDConPtrPadreOptimizado& Nodo al que se le agregó la etiqueta
Requiere: Nodo vÃ¡lido
Efecto: Modifica la etiqueta de el nodo
Modifica: La etiqueta de un nodo
   */
  HMIHDConPtrPadreOptimizado& modificarEtiqueta(HMIHDConPtrPadreOptimizado* nodo, int etiqueta);

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
