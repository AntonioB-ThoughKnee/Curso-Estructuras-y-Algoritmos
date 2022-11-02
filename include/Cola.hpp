#ifndef COLAHPP
#define COLAHPP
/**
 * @brief Estructura de datos Cola
 * @remark Esta estructura es implementada por un arreglo circular
 * @remark Específicamente esta cola admite un limite de 10 elementos
 * @param inicio variable que guarda la posicion del primer dato de la cola
 * @param final variable que guarda la posicion del ultimo dato de la cola
 * @param capacidad cantidad maxima de datos en la cola
 * @param cola puntero al arreglo circular
 * @param contador cantidad de datos en la cola
 */
class Cola{

private:
int inicio;
int final;
int capacidad;
int* cola;
int contador;

public:
/**
 * @brief Metodo constructor de la clase
 * @remark Efecto: Inicializa la cola como una cola vacía.
 * @remark Requiere: Que la cola no esté inicializada.
 * @remark Modifica: La cola.
 */
Cola();
/**
 * @brief Metodo destructor de la clase
 * @remark Efecto: Hace que la cola quede inutilizable.
 * @remark Requiere: Que la cola no este destruida.
 * @remark Modifica: La cola.
 * 
 */
~Cola();

void Iniciar();
void Destruir();
/**
 * @brief Metodo para agregar un elemento a la cola
 * 
 * @param elemento elemento que se desea incluir a la cola
 * @remark Efecto: Agrega un elemento en la parte de atrás de cola.
 * @remark Requiere: Que la cola esté inicializada y que no se haya excedido la capacidad maxima de la misma.
 * @remark Modifica: El contenido de la cola.
 */

void Encolar(int elemento);
/**
 * @brief Metodo para agregar un elemento a la cola
 * 
 * @return int elemento que se saco de la cola
 * @remark Efecto: Elimina el elemento que se encuentra delante de la cola y lo devuelve.
 * @remark Requiere: Que la cola esté inicializada y no vacía.
 * @remark Modifica: El contenido de la cola.
 */
int Desencolar();
/**
 * @brief Metodo que devuelve la cantidad de elementos en la cola
 * 
 * @return int cantidad de elementos en la cola 
 * @remark Efecto: Devuelve un entero con el número de elementos presente en la cola
 * @remark Requiere: Que la cola esté inicializada.
 * @remark Modifica: No produce modificaciones en la estructura.
 */
int numElem();
};
#endif