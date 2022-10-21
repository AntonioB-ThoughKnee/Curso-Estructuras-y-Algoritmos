#include <iostream>
#include <vector>

#include "../include/ListaIndexada.hpp"
#include "../include/Cola.hpp"
// #include "../include/ArregloPadre.hpp"
#include "../include/HMIHDConPtrPadreOptimizado.hpp"
// #include "../include/HMIHDConPtrPadreyHI.hpp"
// #include "../include/ListaHijos.hpp"
// #include "../include/HMIHDConContador.hpp"

using namespace std;

Arbol::Nodo* buscarEtiqueta(int etiqueta, Arbol* A)
{
  Arbol::Nodo* tmp;
  vector<Arbol::Nodo*> auxiliar;
  auxiliar.push_back(A->Raiz());
  int i = 0;
  while(i < auxiliar.size())
  {
    tmp = auxiliar[i];
    i++;
    if(A->Etiqueta(tmp) == etiqueta) { return tmp; }
    tmp = A->HijoMasIzquierdo(tmp);
    while(tmp != nullptr)
    {
      auxiliar.push_back(tmp);
      tmp = A->HermanoDerecho(tmp);
    }
  }

  return nullptr;

}

int main(){
  Arbol* arbol = new Arbol();
  Arbol::Nodo* nodo;

  // Se inicializa un arbol
  cout << "Un arbol ha sido creado" << endl;
  cout << "Bienvenid@!\n Qué estructura desea probar ?" << endl;
  int accion=1;
  bool raizDefinida = false;

  //===========================  Creando arbol predefinido
    // 1
    // |_2
    // | |_5
    // | |_6
    // |_3
    // |_4
    // | |_7

  arbol->PonerRaiz(1);
  Arbol::Nodo* root = arbol->Raiz();
  Arbol::Nodo* nodo2 = arbol->AgregarHijo(root, 2);
  arbol->AgregarHijoMasDerecho(root, 3);
  Arbol::Nodo* nodo4 = arbol->AgregarHijoMasDerecho(root, 4);

  arbol->AgregarHijo(nodo2, 6);
  arbol->AgregarHijo(nodo2, 5);
  arbol->AgregarHijo(nodo4, 7);
  raizDefinida = true;
  
  nodo = buscarEtiqueta(7, arbol);  
  nodo = buscarEtiqueta(5, arbol);  
  nodo = buscarEtiqueta(6, arbol);  
  nodo = buscarEtiqueta(1, arbol); 
  nodo = buscarEtiqueta(6, arbol); 

  nodo = arbol-> Padre(nodo);  
  nodo = arbol-> Padre( arbol->HijoMasIzquierdo(nodo4) );  
  nodo = arbol-> Padre(nodo2);  
  nodo = arbol-> Padre(root);
  //=====  

  // Se despliega un menu para controlar el arbol
  while (accion != 0){
    cout << "\nDigite una opcion: \n1-PonerRaíz  \n2-AgregarHijo \n3-AgregarHijoMásDerecho \n4-BorrarHoja  \n5-Imprimir raíz \n6-Imprimir padre de un nodo\n7-Imprimir hijoMásIzquierdo \n8-Imprimir hermano Derecho \n9-Modificar etiqueta \n10-NumNodos\n 0-Salir" << endl;
    cin >> accion;
    switch(accion){
      case 1:
        if(raizDefinida) {
          cout << "Ya hay una raiz en el árbol " << endl; 
          break;
        }
        int numeroEtiqueta;
        cout << "Digite el numero de la etiqueta: " << endl;
        cin >> numeroEtiqueta;
        arbol->PonerRaiz(numeroEtiqueta);
        raizDefinida = true;
      break;
      case 2:
        cout << "A cual nodo desea agregar un hijo? " << endl;     
        cin >> accion;   
        nodo = buscarEtiqueta(accion, arbol);
        cout << "Digite el numero de la etiqueta que desea agregar " << endl;
        cin >> accion; 
        arbol->AgregarHijo(nodo, accion);
      break;
      case 3:
        cout << "A cual nodo desea agregar un hijo mas derecho? " << endl;     
        cin >> accion;   
        nodo = buscarEtiqueta(accion, arbol);
        cout << "Digite la etiqueta que desea agregar " << endl;
        cin >> accion; 
        arbol->AgregarHijoMasDerecho(nodo, accion);
      break;
      case 4:
        cout << "Digite la etiqueta del nodo hoja desea borrar" << endl;     
        cin >> accion;   
        nodo = buscarEtiqueta(accion, arbol);
        arbol->BorrarHoja(nodo);
      break;
      case 5:
        cout << "La raíz del árbol es: " << arbol->Etiqueta( arbol->Raiz() ) << endl;
      break;
      case 6:
        cout << "Digite la etiqueta del nodo que desea conocer el padre " << endl;
        cin >> accion;
        nodo = buscarEtiqueta(accion, arbol);
        cout << "El padre del nodo " << accion << " es: " << arbol->Etiqueta( arbol-> Padre(nodo) ) << endl;
      break;
      case 7:
        cout << "Digite la etiqueta del nodo que desea conocer el  hijo más izquierdo " << endl;
        cin >> accion;
        nodo = buscarEtiqueta(accion, arbol);
        cout << "El hijo más izquierdo del nodo " << accion << " es: " << arbol->Etiqueta( arbol-> HijoMasIzquierdo(nodo) ) << endl;
      break;
      case 8:
        cout << "Digite la etiqueta del nodo que desea conocer el hermano derecho " << endl;
        cin >> accion;
        nodo = buscarEtiqueta(accion, arbol);
        cout << "El hermano derecho del nodo " << accion << " es: " << arbol->Etiqueta( arbol-> HermanoDerecho(nodo) ) << endl;
      break;
      case 9:
        cout << "Digite la etiqueta del nodo que desea conocer el modificar " << endl;
        cin >> accion;
        nodo = buscarEtiqueta(accion, arbol);
        cout << "Digite la nueva etiqueta" << endl;
        cin >> accion;
        arbol->ModificarEtiqueta(nodo, accion);
      break;
      case 10:
        cout << "La cantidad de nodos en el árbol es: " << arbol->NumNodos() << endl;
      break;
      case 11:
        cout << "Digite la etiqueta del nodo que desea conocer si existe" << endl;
        cin >> accion;
        nodo = buscarEtiqueta(accion, arbol);
        if(nodo != nullptr) { cout << "La etiqueta existe en el árbol " << endl; }
        else { cout << "La etiqueta no existe en el árbol " << endl; }

      break;
      // default:
      //     cout << "Debe elegir una opción valida" << endl;
      //     accion=0;
      // break;
    }
  }
  arbol->Destruir();
  delete arbol;

  // Opciones opciones;
  // cout << "Bienvenid@!\n Qué estructura desea probar ?" << endl;
  // int accion=0;
  // while (!accion){
  //   cout << "1- Lista 2-Cola 3-Arbol 4-Salir" << endl;
  //   cin >> accion;
  //   switch(accion){
  //     case 1:
  //     opciones.menuLista();
  //     break;
  //     case 2:
  //     opciones.menuCola();
  //     break;
  //     case 3:
  //     opciones.menuArbol();
  //     break;
  //     default:
  //     cout << "Debe elegir una opción valida" << endl;
  //     accion=0;
  //     break;
  //   }
  //   return 0;
  // }
}