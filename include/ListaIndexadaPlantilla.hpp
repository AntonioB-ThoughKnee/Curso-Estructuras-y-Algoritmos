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
template<typename Elemento>
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
    Elemento dato;
    Caja* siguiente;
    public:
    /**
     * @brief Constructor de la clase caja
     * 
     * @param dato numero guardado en esa caja de la lista 
     */
    Caja(Elemento dato){
        // Se inicializan los atributos de la caja
        this->dato=dato;
        this->siguiente=nullptr;
    }
    /**
     * @brief Destructor de la clase caja
     * 
     */
    ~Caja(){
        // En caso de haber,
        // Se manda a liberar la memoria del siguiente elemento de la caja 
        if(this->siguiente!=nullptr){
            delete this->siguiente;
        }
    }
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
    void Iniciar(){
        // Se inicializan los atributos de la clase
        this->primero=nullptr;
        this->ultimo=nullptr;
        this->contador=0;
    }
    /**
     * @brief Destructor de la lista
     * @remark Efecto: Destruye una lista de tipo lista_indexada.
     * @remark Requiere: Que la lista indexada ya haya sido creada anteriormente.
     * @remark Modifica: La lista indexada, ya que el operador básico se dedica a destruirla.
     * 
     */
    void Destruir(){
        // Se libera la memoria utilizada
        delete this->primero;
    }
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
    void Insertar(Elemento dato,int indice){
        // Se crea una nueva caja con el numero por insertar
        Caja* caja=new Caja(dato);
        // Se crea un puntero para iterar por la lista
        Caja* actual=this->primero;
        // Se verifica si el insertado se hace al frente de la lista
        // En caso de serlo se inserta en la primera posicion y
        // El puntero al primer elemento apunta a la nueva caja
        if(indice==1){
            caja->siguiente=this->primero;
            this->primero=caja;
        }
        // En cualquier otro caso se inserta normalmente,recorriendo la lista
        // menos si la insercion es al final 
        else if(indice==this->contador && indice!=1){
            this->ultimo->siguiente=caja;
        }else{
        // Cuando la insercion es al final se usa el puntero al ultimo 
        // y se inserta directamente al final de la lista
            for (int i=1;i<indice-1;++i){
            actual=actual->siguiente;
            }
            caja->siguiente=actual->siguiente;
            actual->siguiente=caja;
        }
        // Se aumenta la cantidad de elementos 
        ++this->contador;
        // Se verifica si ha cambiado el ultimo 
        // En caso de haberlo hecho se modifica el puntero al ultimo
        if(this->contador==indice){
            this->ultimo=caja;
        }
    }
    /**
     * @brief Metodo que borra un elemento de una indice de la lista
     * 
     * @param indice indice del elemento que se desea borrar
     * @remark Efecto: Elimina un elemento de una posición específica de la lista indexada.
     * @remark Requiere: Índice sea válido para la lista.
     * @remark Modifica: Modifica a la lista L, ya que el operador básico se dedica a borrar un elemento entonces el estado de la lista indexada cambia.
     */
    void Borrar(int indice){
        // Se crea un puntero para iterar por la lista
        Caja* actual=this->primero;
        // Se verifica si el borrado se hace al frente de la lista
        if(indice==1){
        // En caso de serlo se borra la primera posicion y
        // El puntero al primer elemento apunta al antiguo segundo
            Caja* cajaBorrar=this->primero;
            this->primero=this->primero->siguiente;
            cajaBorrar->siguiente=nullptr;
            delete cajaBorrar;
        }else{
        // De no serlo se elimina el elemento normalmente
            for (int i=1;i<indice-1;++i){
            actual=actual->siguiente;
            }
            Caja* cajaBorrar=actual->siguiente;
            actual->siguiente=actual->siguiente->siguiente;
            cajaBorrar->siguiente=nullptr;
            delete cajaBorrar;
        }
        // Se verifica si ha cambiado el ultimo 
        // En caso de haberlo hecho se modifica el puntero al ultimo
        if(this->contador==indice){
            this->ultimo=actual;
        }
        // Se decrementa la cantidad de elementos de la lista
        --contador;
    }
    /**
     * @brief Metodo que devuelve el numero de un indice en especifico
     * 
     * @param indice ndice del elemento que se desea recuperar
     * @return int numero recuperado
     * @remark Efecto: Retorna el elemento que se encuentra en la posición i, pasada por parámetro.
     * @remark Requiere: índice válido dentro del rango de la lista.
     * @remark Modifica: Este operador básico no realiza modificaciones sobre la lista indexada.
     */
    Elemento Recuperar(int indice){
        // Se itera por la lista para llegar al indice deseado
        Caja* actual=this->primero;
        for (int i=1;i<indice;++i){
        actual=actual->siguiente;
        }
        // El dato en ese indice se devuelve
        return actual->dato;
    }
    /**
     * @brief Metodo que modifica un dato de un indice en la lista
     * 
     * @param dato nuevo elemento por poner en el indice 
     * @param indice indice del elemento por modificar
     * @remark Efecto: Reemplaza el elemento que se encuentra en el índice i, por el elemento que se pasa por parámetro llamado e, en la lista indexada.
     * @remark Requiere: i= una posición válida.
     * @remark Modifica: L, ya que hace un reemplazo de un elemento.
     */
    void Modificar(Elemento dato,int indice){
        // Se itera por la lista para llegar al indice deseado
        // y se modifica con el dato ingresado 
        Caja* actual=this->primero;
        for (int i=1;i<indice;++i){
        actual=actual->siguiente;
        }
        actual->dato=dato;
    }
    /**
     * @brief Metodo que devuelve la cantidad de elementos de la lista
     * 
     * @remark Efecto: Cuenta la cantidad de elementos que contiene la lista indexada L.
     * @remark Requiere: L = lista indexada inicializada
     * @remark Modifica: Este operador básico no realiza modificaciones.
     * 
     */
    int NumElem(){
        // Se devuelve la cantidad de datos en la lista
        return this->contador;
    }
};
#endif