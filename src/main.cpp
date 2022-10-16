// #include "include/Arbol.cpp" NOT .cpp
//=====  
// #include "../include/HMIHDConContador.h"
// #include "../include/HMIHDConPtrPadreOptimizado.h"
//carlos.Sanchezblanco@ucr.ac.cr
#include "../include/HMIHDConPtrPadreyHI.h"
#include <vector>

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
Arbol* iko = new Arbol();

iko->ponerRaiz(10)
  .agregarHijo(iko->Raiz(), 2)
  ->agregarHijo(iko->Raiz(), 3);
Arbol* root = iko->Raiz();
  
Arbol* level3 = 
  iko->agregarHijo(iko->HMI(iko->Raiz()), 4)
    ->agregarHijo(iko->HMI(iko->Raiz()), 5)
    ->agregarHijoMasDerecho(iko->Raiz(), 6)
    ->agregarHijoMasDerecho(iko->Raiz(), 7);
    
iko->agregarHijo(level3, 8);

Arbol* father = iko->Padre(level3);

//iko->borrarHoja(root); Falta que funcione correctamente el borrar hoja
int c = iko->numNodos();

Arbol* test = buscarEtiqueta(7, iko);

return 0;
}
