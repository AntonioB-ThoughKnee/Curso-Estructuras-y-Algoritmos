// #include "include/Arbol.cpp" NOT .cpp
//=====  
// #include "../include/HMIHDConContador.h"
// #include "../include/HMIHDConPtrPadreOptimizado.h"
#include "../include/HMIHDConPtrPadreyHI.h"

//carlos.Sanchezblanco@ucr.ac.cr
#include <vector>
#include <memory>
#include <iostream>

// Arbol* buscarEtiqueta(int etiqueta, Arbol* A)
// {
//   Arbol* tmp;
//   vector<Arbol*> auxiliar;
//   auxiliar.push_back(A->Raiz());
//   int i = 0;
//   while(i < auxiliar.size())
//   {
//     tmp = auxiliar[i];
//     i++;
//     if(tmp->Etiqueta(tmp) == etiqueta) { return tmp; }
//     tmp = tmp->HMI(tmp);
//     while(tmp != nullptr)
//     {
//       auxiliar.push_back(tmp);
//       tmp = tmp->HD(tmp);
//     }
//   }

//   return nullptr;

// }

int main()
{
struct Arbol::Nodo;

Arbol* iko = new Arbol();

iko->ponerRaiz(10)
  .agregarHijo(iko->Raiz(), 2);
iko->agregarHijo(iko->Raiz(), 3);

Arbol::Nodo* root = iko->Raiz();
  
Arbol::Nodo* level3 = iko->agregarHijo(iko->HMI(iko->Raiz()), 7);
iko->agregarHijo(level3, 6);
// iko->agregarHijo(level3, 4);
// iko->agregarHijo(level3, 5);
// iko->agregarHijo(level3, 8);

Arbol::Nodo* father = iko->Padre(level3);

iko->borrarHoja(iko->HMI(level3)); 
int c = iko->numNodos();

iko->agregarHijoMasDerecho(level3, 8);
iko->agregarHijoMasDerecho(level3, 9);
iko->borrarHoja( iko->HD( iko->HMI(level3) ) ); 
c = iko->numNodos();

// Arbol* test = buscarEtiqueta(7, iko);

iko->destruir();
root = iko->Raiz();

return 0;
}
