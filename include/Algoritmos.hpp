#ifndef ALGORITMOSHPP
#define ALGORITMOSHPP

#include "ListaIndexada.hpp"
#include "Cola.hpp"
//#include "ArregloSenaladorPadre.hpp"
//#include "HMIHDConPtrPadreOptimizado.hpp"
//#include "HMIHDConPtrPadreyHI.hpp"
//#include "ListaHijos.hpp"
#include "HMIHDConContador.hpp"

class Algoritmos{
private:
Arbol* arbol;
public:
Algoritmos();
~Algoritmos();
//TODO: Programar este metodo
void inicializarArbol();
void menu();
int contarPorNiveles();
void listaEtiquetasNivel(int nivel);
void recorridoPreOrden();
void recorridoPorNiveles();
};

#endif