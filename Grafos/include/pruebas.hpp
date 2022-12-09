#ifndef PRUEBASHPP
#define PRUEBASHPP  
#include "../include/Algoritmos.hpp"
#include "../include/SeleccionDeGrafo.hpp"
#include "time.h"
#include <bits/stdc++.h>
#include <map>
using namespace Algoritmos;
class Pruebas {
  public:
    Grafo* grafo1;
    Grafo* grafo2;
    Grafo* grafo3;
    Grafo* grafo4;
    Pruebas();
    ~Pruebas();
    void test();
};
#endif