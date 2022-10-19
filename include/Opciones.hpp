#ifndef OPCIONESHPP
#define OPCIONESHPP

#include "ListaIndexada.hpp"
#include "Cola.hpp"
//#include "ArregloSenaladorPadre.h"
//#include "HMIHDConPtrPadreOptimizado.h"
//#include "HMIHDConPtrPadreyHI.h"
//#include "ListaHijos.hpp"
#include "HMIHDConContador.h"

class Opciones{
private:
ListaIndexada* lista;
Cola* cola;
Arbol* arbol;
public:
Opciones();
~Opciones();
void menuLista();
void menuCola();
void manuArbol();
};

#endif