

#include "../include/Menu.hpp"
#include <iostream>
using namespace std;
void Menu::MenuPrincipal() {

  int accion = -1;
  while (accion != 0){
    cout<<"1- Probar Operadores 2-Probar Algoritmos 3-Test: "<<endl;
    cin >> accion;
    switch(accion){
      case 1:
        this->opciones->menuGeneral();
      break;
      case 2:
        this->algoritmos->menu();
      break;
      case 3:
        this->test->CrearArboles();
        this->test->Correr();
        cout<<"Los arboles fueron creados"<<endl;
      break;
      default:
          accion=0;
      break;
    }
  }
}
