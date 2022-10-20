#include <iostream>
//#include "../include/ListaHijos.hpp"
//#include "../include/ListaHijos.hpp"
//#include "../include/HMIHDConContador.hpp"
#include "../include/HMIHDConPtrPadreOptimizado.hpp"
//#include "../include/HMIHDConPtrPadreyHI.hpp"
int main() {
    std::cout << "Hello, World" << std::endl;
    Arbol arr;
    arr.Crear();
    // Visto desde aqui afuera el arreglo con senalador al padre empieza con indice 1
    arr.PonerRaiz(1);
    auto nodo2 = arr.AgregarHijo(arr.Raiz(), 2);
    auto nodo3 = arr.AgregarHijo(arr.Raiz(), 3);
    auto nodo4 = arr.AgregarHijoMasDerecho(arr.Raiz(), 4);
    auto nodo5 = arr.AgregarHijo(nodo3, 5);
    auto nodo6 = arr.AgregarHijoMasDerecho(nodo3, 6);
    auto nodo7 = arr.AgregarHijoMasDerecho(nodo4, 7);
    auto nodo8 = arr.AgregarHijoMasDerecho(nodo2, 8);
    auto nodo9 = arr.AgregarHijoMasDerecho(nodo8, 9);
    auto nodo10 = arr.AgregarHijoMasDerecho(nodo8, 10);
    auto nodo11 = arr.AgregarHijoMasDerecho(nodo7, 11);
    auto nodo12 = arr.AgregarHijoMasDerecho(nodo7, 12);
    auto nodo13 = arr.AgregarHijoMasDerecho(nodo12, 13);
    int etiquetaN10 = arr.Etiqueta(nodo9);
    auto raiz = arr.Raiz();

    auto hermDerDel10 = arr.HermanoDerecho(nodo10);
    auto hermDerDel11 = arr.HermanoDerecho(nodo11);

    arr.Destruir();
    return 0;
}
