#ifndef ALGORITMOSHPP
#define ALGORITMOSHPP

#include "ListaIndexadaPlantilla.hpp"
#include "ColaPlantilla.hpp"
// #include "ArregloPadre.hpp"
// #include "HMIHDConPtrPadreOptimizado.hpp"
// #include "HMIHDConPtrPadreyHI.hpp"
// #include "ListaHijos.hpp"
#include "HMIHDConContador.hpp"
// template < template <Arbol::Nodo*> class ListaIndexada >
class Algoritmos{
private:
Arbol* arbol;
public:
Algoritmos();
~Algoritmos();
//TODO: Programar este metodo
void inicializarArbol();
void menu();

void hermanoIzquierdo(Arbol::Nodo* nodo);  // Por dentro imprime la etiqueta, no devuelve nada entonces.
void contieneEtiquetasRepetidas();  // Imprime por dentro el mensaje de verdadero o falso.
void profundidadNodo(Arbol::Nodo* nodoBuscar);  // Imprime por dentro el numero.
void cantidadNivelesPreOrden();  // Imprime la cantidad de niveles por dentro.

int contarPorNiveles();
void listaEtiquetasNivel(int nivel);
void recorridoPreOrden();
void recorridoPorNiveles();

// ===========================================
// METODO PARA CONTIENE ETIQUETAS REPETIDAS
// bool BuscarRepetidaEnLista(int etiqueta, ListaIndexada<Arbol::Nodo*>* L);

// ===============================================================
// METODO PARA PROFUNDIDAD NODO
void ListarPreOrdenRProfundidad(Arbol::Nodo* nodo, int nivel,
  Arbol::Nodo* nodoBuscar, int* nivelRet, bool* encontrado);

// ==========================================================
// METODO PARA CANTIDAD DE NIVELES PRE ORDEN
void ListarPreOrdenR(Arbol::Nodo* nodo, int nivel, int* nivelRet);



};

#endif