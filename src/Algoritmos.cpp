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

void  Algoritmos::EliminarSubarbol(Arbol::Nodo* nodo, Arbol* A){
  Arbol::Nodo* tmp = A->HijoMasIzquierdo(nodo); //Hijo de nodo
  Arbol::Nodo* tmpHermanoDerecho; // Hermano derecho del hijo de nodo, existe porque se necesita guardar antes de que se elimine tmp al salir de la llamada recursiva en el while loop
  while(tmp != nullptr){
    tmpHermanoDerecho = A->HermanoDerecho(tmp);
    EliminarSubarbol(tmp, A);
    tmp = tmpHermanoDerecho;
  } 

  //Si se llegó al final del subárbol, se elimina la hoja y se crea un efecto dominó hacía arriba
  if(tmp == nullptr){
    A->BorrarHoja(nodo);
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
    //===========================  Configurando variables para el programa
    Arbol* arbol=new Arbol();
    ListaIndexada<int> lista;
    Arbol::Nodo* nodo;
    //=====  

    //===========================  Testeando el árbol

      //===========================  Bug el parámetro "nodo" pasado al operador básico AgregarHijo es modificado 
      arbol->PonerRaiz(1);
      nodo = arbol->Raiz();
      arbol->AgregarHijo(nodo, 2);// FIXME después de ejecutar está línea, "nodo" empieza a tener valores inválidos
      arbol->AgregarHijo(arbol->Raiz(), 3);
      //=====  

    for(int ii = 1; ii <= 13 ; ii++){ // Se puede cambiar el número de elementos en la lista para hacer un árbol siempre y cuando cumpla con el requisito del algoritmo
      lista.insertar(ii, ii);
    }
    arbol = HacerArbol(3, lista);
    EliminarSubarbol(BuscarEtiqueta(3, arbol), arbol);
    nodo = BuscarEtiqueta(12, arbol);
    nodo = arbol->Padre(nodo);
    //=====  

    while (accion != 0){
        cout<<"Seleccione el algoritmo que desea probar: "<<endl;
        string opciones = "\n9-Buscar Etiqueta\n10-Eliminar Subarbol \n11-Construir arbol completo";
        cout<<opciones<<endl;
        cin >> accion;
        
        //===========================  Limpiando "lista"
        int ii = 1;
        while(lista.numElem() > 0 ){
          lista.borrar(ii);
        }
        //=====  
        switch(accion){
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
            case 10: //  Borrar sub árbol
              cout << "Cuál nodo desea borrar?\nDigite la etiqueta del nodo " << endl;
              cin >> accion;
              nodo = BuscarEtiqueta(accion, arbol);
              if(nodo == nullptr){
                cout << "No existe nodo con esa etiqueta " << endl;
              } else {
                EliminarSubarbol(BuscarEtiqueta(accion, arbol), arbol);
                cout << "Nodo eliminado" << endl;
              }
            break;
            case 11: // Construir arbol
              cout << "Se creará una lista con los números del 1 hasta el número que digite, y estos números formarán parte del nuevo árbol" << endl;
              cout << "La lista creada debe cumplir un tamaño igual a \n(k**i-1) / (k-1)\nDonde 'k' = hijos por nodo e 'i' = nivel de profundidad del arbol " << endl;
              cin >> accion;

              for(int ii = 1; ii <= accion ; ii++){ //bg
                lista.insertar(ii, ii);
              }

              cout << "Ingrese la cantidad de hijos por nodo " << endl;
              cin >> accion;
              arbol = HacerArbol(accion, lista);
            break;
            default:
                accion=0;
            break;
        }
    }
}