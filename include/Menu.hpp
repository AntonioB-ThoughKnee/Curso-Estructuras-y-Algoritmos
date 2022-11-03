// Creado entre todos los integrantes.
#ifndef MENUHPP
#define MENUHPP

#include "ListaIndexadaPlantilla.hpp"
#include "ColaPlantilla.hpp"
// #include "ArregloPadre.hpp"
// #include "HMIHDConPtrPadreOptimizado.hpp"
// #include "HMIHDConPtrPadreyHI.hpp"
// #include "ListaHijos.hpp"
#include "HMIHDConContador.hpp"

#include "Algoritmos.hpp"
#include "Opciones.hpp"

class Menu {
public:
  Opciones* opciones;
  Algoritmos* algoritmos;
  Arbol* arbol;
  Menu() {
    this->arbol = new Arbol();
    this->algoritmos = new Algoritmos(this->arbol);
    this->opciones = new Opciones(this->arbol);
  }
  ~Menu() {
    if(this->opciones!=nullptr){
      delete this->opciones;
      this->opciones=nullptr;
    }
    if(this->algoritmos!=nullptr){
        delete this->algoritmos;
        this->algoritmos=nullptr;
    }
    if(this->arbol!=nullptr){
        delete this->arbol;
        this->arbol=nullptr;
    }
  }
  void MenuPrincipal();
};

#endif
