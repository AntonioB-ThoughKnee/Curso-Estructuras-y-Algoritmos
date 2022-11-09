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
#include "Test.hpp"

class Menu {
public:
  Opciones* opciones;
  Algoritmos* algoritmos;
  Test* test;
  Arbol* arbol;
  Menu() {
    this->arbol = new Arbol();
    this->algoritmos = new Algoritmos(this->arbol);
    this->opciones = new Opciones(this->arbol);
    this->test = new Test();
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
    if(this->test!=nullptr){
      delete this->test;
      this->test=nullptr;
    }
  }
  void MenuPrincipal();
};

#endif
