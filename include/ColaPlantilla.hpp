// Creado por Alejandro Jiménez

#ifndef COLAPLANTILLAHPP
#define COLAPLANTILLAHPP
#include <iostream>
using namespace std;
template <typename Elemento>

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
Elemento* cola;
int contador;

public:
/**
 * @brief Metodo constructor de la clase
 * @remark Efecto: Inicializa la cola como una cola vacía.
 * @remark Requiere: Que la cola no esté inicializada.
 * @remark Modifica: La cola.
 */
void Iniciar(){
    // Se inicializan los atributos de la clase
    this->inicio=0;
    this->final=-1;
    this->capacidad=10;
    this->cola= new Elemento[100];
    this->contador=0;
}
/**
 * @brief Metodo destructor de la clase
 * @remark Efecto: Hace que la cola quede inutilizable.
 * @remark Requiere: Que la cola no este destruida.
 * @remark Modifica: La cola.
 * 
 */
void Destruir(){
    // Se dejan en cero todos los atributos de la clase y se libera la memoria utilizada
    this->inicio=0;
    this->final=0;
    this->capacidad=100;
    this->contador=0;
    // for (int i = 0; i < 100; i++) {
    //   if (this->cola[i]) {
    //     delete this->cola[i];
    //   } 
    // }
    // delete this->cola;
}


/**
 * @brief Metodo para agregar un elemento a la cola
 * 
 * @param elemento elemento que se desea incluir a la cola
 * @remark Efecto: Agrega un elemento en la parte de atrás de cola.
 * @remark Requiere: Que la cola esté inicializada y que no se haya excedido la capacidad maxima de la misma.
 * @remark Modifica: El contenido de la cola.
 */
void Encolar(Elemento elemento){
    // Se verifica si la cola tiene espacio, de no ser asi no se puede encolar
    if(this->contador==this->capacidad){
        cout << "La cola esta llena"<<endl;
    }else{
    // En caso de tener espacio se modifica el final y se incluye el nuevo 
    // valor
        this->final=(this->final+1)%this->capacidad;
        this->cola[this->final]=elemento;
        ++this->contador;
    }
}

/**
 * @brief Metodo para agregar un elemento a la cola
 * 
 * @return int elemento que se saco de la cola
 * @remark Efecto: Elimina el elemento que se encuentra delante de la cola y lo devuelve.
 * @remark Requiere: Que la cola esté inicializada y no vacía.
 * @remark Modifica: El contenido de la cola.
 */
Elemento Desencolar(){
    // Se verifica si la cola esta vacia, de ser asi no se puede desencolar de ella
    if(this->contador==0){
        cout << "La cola esta vacía" << endl;
        return nullptr;
    }else{
    // Si no lo está, se modifica el inicio y se devuelve el primer valor agregado
        Elemento elemDevolver=cola[this->inicio];
        this->inicio=(this->inicio+1)%this->capacidad;
        --this->contador;
        return elemDevolver;
    }
    
}
/**
 * @brief Metodo que devuelve la cantidad de elementos en la cola
 * 
 * @return int cantidad de elementos en la cola 
 * @remark Efecto: Devuelve un entero con el número de elementos presente en la cola
 * @remark Requiere: Que la cola esté inicializada.
 * @remark Modifica: No produce modificaciones en la estructura.
 */
int NumElem(){
    return this->contador;
}

};
#endif