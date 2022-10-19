// #include "include/Arbol.cpp" NOT .cpp
//=====  
// #include "../include/HMIHDConContador.h"
#include "../include/HMIHDConPtrPadreOptimizado.h"
// #include "../include/HMIHDConPtrPadreyHI.h"

//carlos.Sanchezblanco@ucr.ac.cr
#include <vector>
#include <memory>
#include <iostream>

Arbol* buscarEtiqueta(int etiqueta, Arbol* A)
{
  Arbol* tmp;
  vector<Arbol*> auxiliar;
  auxiliar.push_back(A->Raiz());
  int i = 0;
  while(i < auxiliar.size())
  {
    tmp = auxiliar[i];
    i++;
    if(tmp->Etiqueta(tmp) == etiqueta) { return tmp; }
    tmp = tmp->HMI(tmp);
    while(tmp != nullptr)
    {
      auxiliar.push_back(tmp);
      tmp = tmp->HD(tmp);
    }
  }

  return nullptr;

}

int main()
{

// cout << "Bienhallado sea \n Quec desea hacer?" << endl;
// int accion;
// cin >> accion;
// switch(accion)
// {
//   case 1:
//   //TODO
//   cout << "Elija una opcion " << endl;
//   //print(opciones de ED1)
//   cin >> accion;
//   while(accion != 0)
//   {
//     //Función de acciones de ED1 que recibe como parámetro "acción" y hace cosas según la adicción
//     cin >> accion;
//   }
//   break;

//   case 2:
//   //TODO
//   break;

//   case 3:
//   //TODO
//   break;

//   default:
//   cout << "Debe elegir una opción valida" << endl;
//   break;
// }

Arbol* iko = new Arbol();

iko->ponerRaiz(10)
  .agregarHijo(iko->Raiz(), 2)
  ->agregarHijo(iko->Raiz(), 3);

Arbol* root = iko->Raiz();
  
Arbol* level3 = 
  iko->agregarHijo(iko->HMI(iko->Raiz()), 4)
    ->agregarHijo(iko->HMI(iko->R aiz()), 5)
    ->agregarHijoMasDerecho(iko->Raiz(), 6)
    ->agregarHijoMasDerecho(iko->Raiz(), 7);
    
iko->agregarHijo(level3, 8);

Arbol* father = iko->Padre(level3);

iko->borrarHoja(iko->HMI(level3)); 
int c = iko->numNodos();

iko->agregarHijoMasDerecho(level3, 9);
iko->borrarHoja( iko->HD( iko->HMI(level3) ) ); 
c = iko->numNodos();

Arbol* test = buscarEtiqueta(7, iko);

iko->destruir();
root = iko->Raiz();

return 0;
}
