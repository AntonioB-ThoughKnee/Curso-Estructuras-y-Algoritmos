#include <iostream>

#include "../include/Algoritmos.hpp"
#include "../include/Opciones.hpp"

int main(){
  Arbol* arbol = new Arbol();

  Opciones opciones(arbol);
  Algoritmos algoritmos;
  int accion = -1;
  while (accion != 0){
    cout<<"1- Probar Operadores 2-Probar Algoritmos: "<<endl;
    cin >> accion;
    switch(accion){
      case 1:
        opciones.menuGeneral();
      break;
      case 2:
        algoritmos.menu();
      break;
      default:
          accion=0;
      break;
    }
  return 0;
}
