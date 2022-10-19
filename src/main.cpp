#include <iostream>

#include "../include/Opciones.hpp"

using namespace std;
int main(){
  Opciones opciones;
  cout << "Bienvenid@!\n Qué estructura desea probar ?" << endl;
  int accion=0;
  while (!accion){
    cout << "1- Lista 2-Cola 3-Arbol 4-Salir" << endl;
    cin >> accion;
    switch(accion){
      case 1:
      opciones.menuLista();
      break;
      case 2:
      opciones.menuCola();
      break;
      case 3:
      //opciones.menuArbol();
      break;
      case 4:
      break;
      default:
      cout << "Debe elegir una opción valida" << endl;
      accion=0;
      break;
    }
    return 0;
}
