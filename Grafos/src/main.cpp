#include <iostream>
#include "../include/ListaIndexadaPlantilla.hpp"
#include "../include/SeleccionDeGrafo.hpp"
#include "../include/Algoritmos.hpp"
#include "../include/pruebas.hpp"
#include "../include/Menu.hpp"
#include <map>

using namespace Algoritmos;
using namespace std;

int main(){ 
	Menu* menu= new Menu;
	menu->Run();
	delete  menu;
	return 0;

}