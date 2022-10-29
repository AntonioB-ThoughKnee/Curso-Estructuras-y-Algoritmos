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
int nivelMaximo;
public:
Algoritmos();
~Algoritmos();
//TODO: Programar este metodo
void inicializarArbol();
void menu();

void hermanoIzquierdo(Arbol::Nodo*);  // Por dentro imprime la etiqueta, no devuelve nada entonces.
void contieneEtiquetasRepetidas();  // Imprime por dentro el mensaje de verdadero o falso.
void profundidadNodo(Arbol::Nodo*);  // Imprime por dentro el numero.
void cantidadNivelesPreOrden();  // Imprime la cantidad de niveles por dentro.
int contarPorNiveles();
void listaEtiquetasNivel(int nivel);
void recorridoPreOrden();
void recorridoPorNiveles();
void cantidadNivelesPorNiveles();
void listarEtiquetasNivel(int nivelDeseado);
void listarPreOrden();
void listarPorNivel();
void contarNivelesR(Arbol::Nodo* nodo,int nivelActual);
void listarEtiquietasNivel(int nivelDeseado);
void listarEtiquietasNivelR(Arbol::Nodo* nodo, int nivelActual,int nivelDeseado);
void listarPreOrden();
void listarPreOrdenR(Arbol::Nodo* nodo);
void listarPorNiveles();
};

#endif