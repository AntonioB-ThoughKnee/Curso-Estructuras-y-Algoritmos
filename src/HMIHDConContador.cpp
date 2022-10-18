// #include "HMIHDConContador.h"
//=====  
#include "../include/HMIHDConContador.h"

#include <vector>

shared_ptr<HMIHDConContador> HMIHDConContador::raiz = nullptr;
  int HMIHDConContador::contador = 0;

HMIHDConContador::HMIHDConContador()
{
  this->hijo = nullptr;
  this->hermano = nullptr;
}

HMIHDConContador::HMIHDConContador(int etiqueta)
{
  this->etiqueta = etiqueta;
  this->hijo = nullptr;
  this->hermano = nullptr;
}

HMIHDConContador::~HMIHDConContador()
{
  // delete raiz;
  // delete this->hijo;
  // delete this->hermano;
}

HMIHDConContador& HMIHDConContador::ponerRaiz(int etiqueta)
{
  shared_ptr<HMIHDConContador> tmp = make_shared<HMIHDConContador>(etiqueta);
  raiz = tmp;
  contador++;
  return *this;
}

shared_ptr<HMIHDConContador> HMIHDConContador::Raiz()
{
  return raiz;
}

shared_ptr<HMIHDConContador> HMIHDConContador::agregarHijo(shared_ptr<HMIHDConContador> nodo, int etiqueta)
{
  shared_ptr<HMIHDConContador> tmp = make_shared<HMIHDConContador>(etiqueta);
  shared_ptr<HMIHDConContador> tmpHijoOriginal = nodo->hijo;
  nodo->hijo = tmp;
  tmp->hermano = tmpHijoOriginal;
  contador++;
  
  return tmp;
}

shared_ptr<HMIHDConContador> HMIHDConContador::agregarHijoMasDerecho (shared_ptr<HMIHDConContador> nodo, int etiqueta)
{
  contador++;
  shared_ptr<HMIHDConContador> tmp = make_shared<HMIHDConContador>(etiqueta);
  shared_ptr<HMIHDConContador> tmpHijoMasDerecho = nodo->hijo;
  if(tmpHijoMasDerecho == nullptr)
  {
    nodo->hijo = tmp;
    return tmp;
  }

  shared_ptr<HMIHDConContador> tmpNull = tmpHijoMasDerecho->hermano; // Esta variable sirve para mantener registrado el nodo anterior cuando se llega al nodo nulo
  while(tmpNull != nullptr)
  {
    tmpNull = tmpNull->hermano;
    tmpHijoMasDerecho = tmpHijoMasDerecho->hermano;
  }
  tmpHijoMasDerecho->hermano = tmp;

  return tmp;
}

void HMIHDConContador::borrarHoja(shared_ptr<HMIHDConContador> hoja)
{
  vector<shared_ptr<HMIHDConContador>> auxiliar; // Utilizado para recorrer el árbol
  shared_ptr<HMIHDConContador> tmp = raiz;
  shared_ptr<HMIHDConContador> padre;
  bool hojaEsHMI = false;
  auxiliar.push_back(tmp);
  int i = 0;
  while(i < auxiliar.size()) // Recorrido del árbol por niveles
  {
    tmp = auxiliar[i];
    i ++;
    if(tmp->hermano == hoja) { break; } // Caso en el quela hoja sea hermano de alguien
    padre = tmp;
    tmp = tmp->hijo;
    if(tmp == hoja) { hojaEsHMI = true; break; } // Caso en el que la hoja es HMI

    while(tmp != nullptr)
    {
      auxiliar.push_back(tmp);
      tmp = tmp->hermano;
    }
  }

  if(hojaEsHMI)
  {
    padre->hijo = tmp->hermano;
    tmp->hermano = nullptr;
  } else
  {
    tmp->hermano = tmp->hermano->hermano;
    tmp->hermano = tmp;
    tmp->hermano = nullptr;
  }
  contador--;
}

shared_ptr<HMIHDConContador> HMIHDConContador::Padre(shared_ptr<HMIHDConContador> nodo)
{
  if(nodo == raiz) { return nullptr; }
  vector<shared_ptr<HMIHDConContador>> auxiliar; // Utilizado para almacenar tanto tmp como el padre de tmp
  shared_ptr<HMIHDConContador> tmp = raiz;
  shared_ptr<HMIHDConContador> padre;
  auxiliar.push_back(tmp);
  int i = 0;
  while(i < auxiliar.size())
  {
    //===========================  Sacamos un elemento del vector y sumamos 2 al iterador, esto porque se utiliza como offset para los nodos por los que se hace el recorrido, luego esta el offset para los padres guardandolos en el mismo vector
    tmp = auxiliar[i];
    i += 2;
    if(tmp == nodo) { return auxiliar[i-3]; }
    padre = tmp;
    tmp = tmp->hijo;
    //=====  

    while(tmp != nullptr)
    {
      auxiliar.push_back(padre);
      auxiliar.push_back(tmp);
      tmp = tmp->hermano;
    }
  }
  return nullptr;
}

shared_ptr<HMIHDConContador> HMIHDConContador::HMI(shared_ptr<HMIHDConContador> nodo)
{
  return nodo->hijo;
}

shared_ptr<HMIHDConContador> HMIHDConContador::HD(shared_ptr<HMIHDConContador> nodo)
{
  return nodo->hermano;
}

int HMIHDConContador::Etiqueta(shared_ptr<HMIHDConContador> nodo)
{
  return nodo->etiqueta;
}

HMIHDConContador& HMIHDConContador::modificarEtiqueta(shared_ptr<HMIHDConContador> nodo, int etiqueta)
{
  nodo->etiqueta = etiqueta;
  return *this;
}

int HMIHDConContador::numNodos()
{
  return contador;
}