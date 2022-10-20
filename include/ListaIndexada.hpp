#ifndef LISTAINDEXADAHPP
#define LISTAINDEXADAHPP
/**
 * @brief Estructura de datos ListaIndexada
 * @remark Esta estructura es implementada por una lista simplemente enlazada
 * @remark La estructura cuenta con un puntero al ultimo y un contador de elementos
 * @param primero puntero al primer elemento de la lista 
 * @param ultimo puntero al ultimo elemento de la lista
 * @param contador cantidad de elementos en la lista
 * 
 */
class ListaIndexada
{
/**
 * @brief Clase que define el grupo de datos guardado en cada indice de la lista
 * @param dato numero guardado en esa caja de la lista 
 * @param siguiente puntero a la proxima caja de la lista
 * 
 */
class Caja
{
    friend class ListaIndexada;
    private:
    int dato;
    Caja* siguiente;
    public:
    /**
     * @brief Constructor de la clase caja
     * 
     * @param dato numero guardado en esa caja de la lista 
     */
    Caja(int dato);
    /**
     * @brief Destructor de la clase caja
     * 
     */
    ~Caja();
};

private:
    Caja* primero;
    Caja* ultimo;
    int contador;
public:
    /**
     * @brief Constructor de la lista
     * 
     * @remark Efecto: Crea una lista de tipo Lista Indexada y la guarda en el parámetro dado.
     * @remark Requiere: Objeto no inicializado de tipo Lista Indexada.
     * @remark Modifica: La lista.
     */
    ListaIndexada();
    /**
     * @brief Destructor de la lista
     * @remark Efecto: Destruye una lista de tipo lista_indexada.
     * @remark Requiere: Que la lista indexada ya haya sido creada anteriormente.
     * @remark Modifica: La lista indexada, ya que el operador básico se dedica a destruirla.
     * 
     */
    ~ListaIndexada();
    /**
     * @brief Metodo que inserta un elemento en una indice de la lista
     * 
     * @param dato numero por guardar en la lista
     * @param indice indice donde se desea insertar el numero
     * @remark Efecto: Inserta un nuevo elemento (enviado por parámetro)
     * en la posición especificada por parámetro.
     * @remark Requiere: Índice sea válido.(Por ejemplo: si la lista tiene 5 elementos, el indice 7 no es valido)
     * @remark Modifica: Se modifica a la lista indexada L.
     */
    void insertar(int dato,int indice);
    /**
     * @brief Metodo que borra un elemento de una indice de la lista
     * 
     * @param indice indice del elemento que se desea borrar
     * @remark Efecto: Elimina un elemento de una posición específica de la lista indexada.
     * @remark Requiere: Índice sea válido para la lista.
     * @remark Modifica: Modifica a la lista L, ya que el operador básico se dedica a borrar un elemento entonces el estado de la lista indexada cambia.
     */
    void borrar(int indice);
    /**
     * @brief Metodo que devuelve el numero de un indice en especifico
     * 
     * @param indice ndice del elemento que se desea recuperar
     * @return int numero recuperado
     * @remark Efecto: Retorna el elemento que se encuentra en la posición i, pasada por parámetro.
     * @remark Requiere: índice válido dentro del rango de la lista.
     * @remark Modifica: Este operador básico no realiza modificaciones sobre la lista indexada.
     */
    int recuperar(int indice);
    /**
     * @brief Metodo que modifica un dato de un indice en la lista
     * 
     * @param dato nuevo elemento por poner en el indice 
     * @param indice indice del elemento por modificar
     * @remark Efecto: Reemplaza el elemento que se encuentra en el índice i, por el elemento que se pasa por parámetro llamado e, en la lista indexada.
     * @remark Requiere: i= una posición válida.
     * @remark Modifica: L, ya que hace un reemplazo de un elemento.
     */
    void modificar(int dato,int indice);
    /**
     * @brief Metodo que devuelve la cantidad de elementos de la lista
     * 
     * @remark Efecto: Cuenta la cantidad de elementos que contiene la lista indexada L.
     * @remark Requiere: L = lista indexada inicializada
     * @remark Modifica: Este operador básico no realiza modificaciones.
     * 
     */
    int numElem();
};
#endif