#include <iostream>
#include <string.h>
#include <vector> //FIXME Reemplazar por lista

#include "../include/Algoritmos.hpp"


using namespace std;

Algoritmos::Algoritmos(){

}
Algoritmos::~Algoritmos(){
    if (this->arbol!=nullptr){
        delete this->arbol;
    }
}

//===========================   Algoritmos 9, 10 y 11
Arbol::Nodo* Algoritmos::BuscarEtiqueta(int etiqueta, Arbol* A)
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

void  Algoritmos::EliminarSubarbol(Arbol::Nodo* hijos, Arbol* A)
{
  ListaIndexada<Arbol::Nodo*> auxiliar;
  int iAuxiliar = 1;
  Arbol::Nodo* tmp = hijos;
  auxiliar.insertar(tmp, auxiliar.numElem()+1);
  for(int ii = 0; ii <  auxiliar.numElem() ; ii++){
    tmp = auxiliar.recuperar(iAuxiliar);
    iAuxiliar++;
    tmp = A->HijoMasIzquierdo(tmp);
    while(tmp != nullptr){
      auxiliar.insertar(tmp, auxiliar.numElem()+1);
      tmp = A->HermanoDerecho(tmp);
    }
  }

  for(int ii = auxiliar.numElem(); ii > 0 ; ii--){
    tmp = auxiliar.recuperar(ii);
    A->BorrarHoja(tmp);
  }
}

Arbol* Algoritmos::HacerArbol(int nodos, ListaIndexada<int> lista){
  Arbol* nuevoArbol = new Arbol();
  ListaIndexada<Arbol::Nodo*> auxiliar;
  int iLista = 1; // Empieza en 1 porque ya se añade la raíz 
  int iAuxiliar = 1;
  nuevoArbol->PonerRaiz(lista.recuperar(iLista));
      iLista++;
  Arbol::Nodo* tmp = nuevoArbol->Raiz();

  while(iLista < lista.numElem() ){
    for(int ii = 0; ii < nodos ; ii++){
      nuevoArbol->AgregarHijoMasDerecho(tmp, lista.recuperar(iLista));
      iLista++;
    }
    Arbol::Nodo* hijoDeTmp = nuevoArbol->HijoMasIzquierdo(tmp);
    while(hijoDeTmp != nullptr){
      auxiliar.insertar(hijoDeTmp, auxiliar.numElem()+1);
      hijoDeTmp = nuevoArbol->HermanoDerecho(hijoDeTmp);
    }
    tmp = auxiliar.recuperar(iAuxiliar);
    iAuxiliar++;
  }
  return nuevoArbol;
}

//=====   

void Algoritmos::menu(){
    int accion=1;
    cout<<"Bienvenido al programa que prueba Algoritmos!"<<endl;
    Arbol::Nodo* nodo;

    //===========================  Configurando tests
    {
    Arbol* arbol=new Arbol();

    //===========================  Defining arbol
    arbol->PonerRaiz(1);
    Arbol::Nodo* root = arbol->Raiz();
    Arbol::Nodo* nodo2 = arbol->AgregarHijo(root, 2);
    arbol->AgregarHijoMasDerecho(root, 3);
    Arbol::Nodo* nodo4 = arbol->AgregarHijoMasDerecho(root, 4);
    //=====  
    ListaIndexada<int> lista;
    lista.insertar(1, 1);
    lista.insertar(2, 2);
    lista.insertar(3, 3);
    lista.insertar(4, 4);
    lista.insertar(5, 5);
    lista.insertar(6, 6);
    lista.insertar(7, 7);

    arbol = HacerArbol(2, lista);
    EliminarSubarbol(BuscarEtiqueta(3, arbol), arbol);
    }
    //=====   

        //TODO: HACER FUNCIONAR ESTE MENU CON LAS OPCIONES DEL ARBOL
    while (accion != 0){
        cout<<"Seleccione el algoritmo que desea probar: "<<endl;
        // TODO: Terminar de agregar las opciones
        string opciones = "\n9-Buscar Etiqueta\n10-Eliminar Subarbol \n11-Construir arbol completo";
        cout<<opciones<<endl;
        cin >> accion;
        switch(accion){
            case 1:
                cout << "404" << endl;
                // cout<<"El arbol tiene "<<this->contarPorNiveles()<<" niveles"<<endl;
            break;
            case 2:
                cout << "404" << endl;
                // int nivel;
                // cout<<"Seleccione el nivel: "<<endl;
                // cin>>nivel;
                // this->listaEtiquetasNivel(nivel);
            break;
            case 3:
                cout << "404" << endl;
                // this->recorridoPreOrden();
            break;
            case 4:
                cout << "404" << endl;
                // this->recorridoPorNiveles();
            break;
            case 9: // buscar Etiqueta
                cout << "A cual nodo desea buscar? " << endl;     
                cin >> accion;   
                nodo = BuscarEtiqueta(accion, arbol);
                if(nodo == nullptr){
                    cout << "No existe nodo con esa etiqueta " << endl;
                } else {
                    cout << "Si existe nodo con esa etiqueta " << endl;
                }
            break;
            case 11: // Construir arbol

            break;
            default:
                accion=0;
            break;
        }
    }
}