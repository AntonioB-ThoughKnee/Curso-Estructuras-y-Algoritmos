#include <iostream>
#include <string.h>

#include "../include/Algoritmos.hpp"


using namespace std;

Algoritmos::Algoritmos(){

}
Algoritmos::~Algoritmos(){
}

//===========================   Algoritmos 9, 10 y 11
Arbol::Nodo* Algoritmos::BuscarEtiqueta(int etiqueta, Arbol* A)
{
  Arbol::Nodo* tmp;
  ListaIndexada<Arbol::Nodo*> auxiliar;
  auxiliar.insertar(A->Raiz(), auxiliar.numElem()+1);
  int i = 1;
  //Se hace recorrido por niveles y se usa un if para encontrar el nodo buscado
  while(i <= auxiliar.numElem())
  {
    tmp = auxiliar.recuperar(i);
    i++;
    if(A->Etiqueta(tmp) == etiqueta) { return tmp; } 
    tmp = A->HijoMasIzquierdo(tmp);
    while(tmp != nullptr)
    {
      auxiliar.insertar(tmp, auxiliar.numElem()+1);
      tmp = A->HermanoDerecho(tmp);
    }
  }
  return nullptr;
}

//FIXME ArregloPadre no funciona con este algoritmo
void  Algoritmos::EliminarSubarbol(Arbol::Nodo* nodo, Arbol* A){
  ListaIndexada<Arbol::Nodo*> auxiliar;
  int iAuxiliar = 1;
  Arbol::Nodo* tmp = nodo;
  auxiliar.insertar(tmp, auxiliar.numElem()+1);

  //Se hace recorrido por niveles para guardar el subárbol de "nodo"
  for(int ii = 0; ii <  auxiliar.numElem() ; ii++){
    tmp = auxiliar.recuperar(iAuxiliar);
    iAuxiliar++;
    tmp = A->HijoMasIzquierdo(tmp);
    while(tmp != nullptr){
      auxiliar.insertar(tmp, auxiliar.numElem()+1);
      tmp = A->HermanoDerecho(tmp);
    }
  }
  //Se borra en orden inverso los nodos guardados porque son hojas
  for(int ii = auxiliar.numElem(); ii > 0 ; ii--){
    tmp = auxiliar.recuperar(ii);
    A->BorrarHoja(tmp);
  }
}

Arbol* Algoritmos::HacerArbol(int nodosPorHijo, ListaIndexada<int> lista){
  Arbol* nuevoArbol = new Arbol();
  ListaIndexada<Arbol::Nodo*> auxiliar;
  int iLista = 1; 
  int iAuxiliar = 1;
  nuevoArbol->PonerRaiz(lista.recuperar(iLista));
  iLista++; //Se suma 1 porque ya se añadió la raíz
  Arbol::Nodo* tmp = nuevoArbol->Raiz(); 

  //Se pasa por toda la lista dada
  while(iLista < lista.numElem() ){
    //Agregando nodos correspondientes segun "nodosPorHijo" a tmp
    for(int ii = 0; ii < nodosPorHijo ; ii++){
      nuevoArbol->AgregarHijoMasDerecho(tmp, lista.recuperar(iLista));
      iLista++;
    }
    //===========================  Guardando los nodos agregados para agregarles mas tarde los nodos correspondientes
    Arbol::Nodo* hijoDeTmp = nuevoArbol->HijoMasIzquierdo(tmp);
    while(hijoDeTmp != nullptr){
      auxiliar.insertar(hijoDeTmp, auxiliar.numElem()+1);
      hijoDeTmp = nuevoArbol->HermanoDerecho(hijoDeTmp);
    }
    //=====  

    //Sacando de auxiliar los nodos guardados para seguir agregando nodos
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
    for(int ii = 1; ii <= 7 ; ii++){ // Se puede cambiar el número de elementos en la lista para hacer un árbol siempre y cuando cumpla con el requisito del algoritmo
      lista.insertar(ii, ii);
    }
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