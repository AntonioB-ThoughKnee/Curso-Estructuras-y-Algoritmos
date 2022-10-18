// #include "include/Arbol.cpp" NOT .cpp
//=====  
#include "../include/HMIHDConContador.h"
// #include "../include/HMIHDConPtrPadreOptimizado.h"
// #include "../include/HMIHDConPtrPadreyHI.h"

//carlos.Sanchezblanco@ucr.ac.cr
#include <vector>
#include <memory>
#include <iostream>

shared_ptr<Arbol> buscarEtiqueta(int etiqueta, shared_ptr<Arbol> A)
{
  shared_ptr<Arbol> tmp;
  vector<shared_ptr<Arbol>> auxiliar;
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
shared_ptr<Arbol> iko = make_shared<Arbol>();

iko->ponerRaiz(10)
  .agregarHijo(iko->Raiz(), 2)
  ->agregarHijo(iko->Raiz(), 3);
shared_ptr<Arbol> root = iko->Raiz();
  
shared_ptr<Arbol> level3 = 
  iko->agregarHijo(iko->HMI(iko->Raiz()), 4)
    ->agregarHijo(iko->HMI(iko->Raiz()), 5)
    ->agregarHijoMasDerecho(iko->Raiz(), 6)
    ->agregarHijoMasDerecho(iko->Raiz(), 7);
    
iko->agregarHijo(level3, 8);

shared_ptr<Arbol> father = iko->Padre(level3);

iko->borrarHoja(iko->HMI(level3)); //Falta que funcione correctamente el borrar hoja
int c = iko->numNodos();

shared_ptr<Arbol> test = buscarEtiqueta(7, iko);

return 0;
}
