#include <iostream>
#include "../include/Opciones.hpp"
#define Arbol
#define Nodo
using namespace std;

Opciones::Opciones(){
// Se inicializan los punteros a las estructuras por probar
    this->lista = nullptr;
    this->cola = nullptr;
    this->arbol = nullptr;
}
Opciones::~Opciones(){
// En caso de ser necesario se libera la memoria
    if(this->lista!=nullptr){
        delete this->lista;
        this->lista=nullptr;
    }
    if(this->cola!=nullptr){
        delete this->cola;
        this->cola=nullptr;
    }
    if(this->arbol!=nullptr){
        delete this->arbol;
        this->arbol=nullptr;
    }
}
void Opciones::menuLista(){
// Se inicializa la lista
    this->lista=new ListaIndexada();
    cout << "Una lista ha sido creada" << endl;
    int accion=0;
// Se despliega un menu para controlar la lista
    while (!accion){
        cout << "Digite una opcion: 1-Insertar 2-Borrar 3-Recuperar 4-Modificar 5- NumElem 6-Destruir (salir)" << endl;
        cin >> accion;
        switch(accion){
            case 1:
                int indiceAgregar;
                int elementoAgregar;
                cout << "Digite un indice: " << endl;
                cin >> indiceAgregar;
                cout << "Digite el valor que desea agregar: " << endl;
                cin >> elementoAgregar;
                this->lista->insertar(elementoAgregar,indiceAgregar);
                accion=0;
            break;
            case 2:
                int indiceBorrar;
                cout << "Digite un indice: " << endl;
                cin >> indiceBorrar;
                this->lista->borrar(indiceBorrar);
                accion=0;
            break;
            case 3:
                int indiceRecuperar;
                cout << "Digite un indice: " << endl;
                cin >> indiceRecuperar;
                cout << "El elemento recuperado es: " << this->lista->recuperar(indiceRecuperar) << endl;
                accion=0;
            break;
            case 4:
                int indiceModificar;
                int elementoModificar;
                cout << "Digite un indice: " << endl;
                cin >> indiceModificar;
                cout << "Digite el nuevo valor: " << endl;
                cin >> elementoModificar;
                this->lista->modificar(elementoModificar,indiceModificar);
                accion=0;
            break;
            case 5:
                cout << "La cantidad de elementos es: " << this->lista->numElem() << endl;
                accion=0;
            break;
            case 6:
                delete this->lista;
                this->lista=nullptr;
                cout << "La lista ha sido destruida" << endl;
            break;
            default:
                cout << "Debe elegir una opción valida" << endl;
                accion=0;
            break;
        }
    }
}
void Opciones::menuCola(){
// Se inicializa la cola
    this->cola=new Cola();
    cout << "Una cola ha sido creada" << endl;
    int accion=0;
// Se despliega un menu para controlar la cola
    while (!accion){
        cout << "Digite una opcion: 1-Encolar 2-Desencolar 3-NumElem 4-Destruir (salir)" << endl;
        cin >> accion;
        switch(accion){
            case 1:
                int elementoEncolar;
                cout << "Digite el valor que desea agregar: " << endl;
                cin >> elementoEncolar;
                this->cola->Encolar(elementoEncolar);
                accion=0;
            break;
            case 2:
                cout << "El elemento recuperado es: " << this->cola->Desencolar() << endl;
                accion=0;
            break;
            case 3:
                cout << "La cantidad de elementos es: " << this->cola->numElem() << endl;
                accion=0;
            break;
            case 4:
                delete this->cola;
                this->cola=nullptr;
                cout << "La cola ha sido destruida" << endl;
            break;
            default:
                cout << "Debe elegir una opción valida" << endl;
                accion=0;
            break;
        }
    }
}

void Opciones::menuArbol(){
// Se inicializa la cola
    Arbol* A=new Arbol();
    cout << "Una Arbol ha sido creado" << endl;
    int accion=0;
// Se despliega un menu para controlar la Arbol
    while (!accion){
        cout << "Digite una opcion: 1-  Poner Raíz 2-Agregar Hijo 3-Agregar Hijo más derecho 4- Buscar etiqueta 5- borrar hoja 6- destruir árbol" << endl;
                int el;
        cin >> accion;
        switch(accion){
            case 1:
                int el;
                cout << "Digite el valor que desea agregar como raiz: " << endl;
                cin >> el;
                A-> PonerRaiz(el);
                accion=0;
            break;
            case 2:
                if(A->Raiz() == nullptr){
                    cout << " Debe poner al menos una raíz " << endl;
                    break;
                }
                int el;
                cout << "Digite el valor que desea agregar: " << endl;
                cin >> el;
                A->Agregar(A->Raiz, el);
                accion=0;
            break;
            case 3:
                if(A->Raiz() == nullptr){
                    cout << " Debe poner al menos una raíz " << endl;
                    break;
                }
                int el;
                cout << "Digite el valor que desea agregar: " << endl;
                cin >> el;
                A->AgregarHijoMasDerecho(A->Raiz,el);
                accion=0;
            break;
            case 4:
                if(A->Raiz() == nullptr){
                    cout << " Debe poner al menos una raíz " << endl;
                    break;
                }

                int el;
                cout << "Digite el valor que desea buscar: " << endl;
                cin >> el;
                Nodo* tmp = buscarEtiqueta(el, A);
                cout << "Que desea hacer con está etiqueta? " << endl;
                cout << "Digite una opcion: 1-Agregar Hijo 2-Agregar Hijo más derecho 3- Borrar 4-Padre 5-modificar etiqueta" << endl;
                switch(accion){
                    case 1:
                        int el;
                        cout << "Digite el valor que desea agregar: " << endl;
                        cin >> el;
                        A->Agregar(tmp, el);
                        accion=0;
                    break;
                    case 2:
                        int el;
                        cout << "Digite el valor que desea agregar: " << endl;
                        cin >> el;
                        A->AgregarHijoMasDerecho(tmp, el);
                        accion=0;
                    break;
                    case 3:
                        A->BorrarHoja(tmp);
                        cout << "El nodo seleccionado fue eliminado " << endl;
                    break;
                    case 4:
                        ;
                        cout << "La etiqueta del padre del nodo seleccionado es " + A->Padre(tmp)->etiqueta << endl;
                    break;
                    case 5:
                        cout << "Digitel que etiqueta poner " << endl;
                        cin >> el;
                        A->ModificarEtiqueta(tmp, el)
                        cout << "La etiqueta fue modificada" << endl;
                    break;

                accion=0;
            break;
            case 5:
                if(A->Raiz() == nullptr){
                    cout << " Debe poner al menos una raíz " << endl;
                    break;
                }
                A->BorrarHoja(buscarEtiqueta(el, A));
                cout << "la etiqueta fue eliminada " << endl;
            break;
            case 6:
                A->Destruir();
                A=nullptr;
                cout << "El A ha sido destruido" << endl;
            break;
            default:
                cout << "Debe elegir una opción valida" << endl;
                accion=0;
            break;
        }
    }
}

Nodo* buscarEtiqueta(int etiqueta, Arbol* A)
{
  Nodo* tmp;
  vector<Nodo*> auxiliar;
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