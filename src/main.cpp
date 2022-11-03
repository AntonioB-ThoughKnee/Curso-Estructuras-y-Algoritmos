// Creado entre todos los integrantes.

#include <iostream>

#include "../include/Menu.hpp"
// TODO: include arbol aqui
int main(){
  Menu* menu = new Menu();
  menu->MenuPrincipal();
  delete menu;
  return 0;
}
