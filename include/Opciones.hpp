#ifndef OPCIONESHPP
#define OPCIONESHPP

#include "ListaIndexada.hpp"
#include "Cola.hpp"
//#include "ArregloSenaladorPadre.h"
//#include "HMIHDConPtrPadreOptimizado.h"
//#include "HMIHDConPtrPadreyHI.h"
//#include "ListaHijos.hpp"
#include "HMIHDConContador.h"
/**
 * @brief Clase controladora del programa de pruebas 
 * @param lista puntero a la lista por crear
 * @param cola puntero a la cola por crear
 * @param arbol puntero al arbol por crear
 * 
 */
class Opciones{
private:
ListaIndexada* lista;
Cola* cola;
Arbol* arbol;
public:
/**
 * @brief Constructor de la clase
 * 
 */
Opciones();
/**
 * @brief Destructor de la clase
 * 
 */
~Opciones();
/**
 * @brief Metodo que muestra el menu controlador de la lista
 * 
 */
void menuLista();
/**
 * @brief Metodo que muestra el menu controlador de la cola
 * 
 */
void menuCola();
/**
 * @brief Metodo que muestra el menu controlador del arbol
 * 
 */
void menuArbol();
};

#endif