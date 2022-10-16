// #include "HMIHDConContador.h"
//=====  
#include "../include/HMIHDConContador.h"

#include <vector>

HMIHDConContador* HMIHDConContador::raiz = nullptr;
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
  delete raiz;
  delete this->hijo;
  delete this->hermano;
}

HMIHDConContador& HMIHDConContador::ponerRaiz(int etiqueta)
{
  HMIHDConContador* tmp = new HMIHDConContador(etiqueta);
  raiz = tmp;
  contador++;
  return *this;
}

HMIHDConContador* HMIHDConContador::Raiz()
{
  return raiz;
}

HMIHDConContador* HMIHDConContador::agregarHijo(HMIHDConContador* nodo, int etiqueta)
{
  HMIHDConContador* tmp = new HMIHDConContador(etiqueta);
  HMIHDConContador* tmpHijoOriginal = nodo->hijo;
  nodo->hijo = tmp;
  tmp->hermano = tmpHijoOriginal;
  contador++;
  
  return tmp;
}

HMIHDConContador* HMIHDConContador::agregarHijoMasDerecho (HMIHDConContador* nodo, int etiqueta)
{
  contador++;
  HMIHDConContador* tmp = new HMIHDConContador(etiqueta);
  HMIHDConContador* tmpHijoMasDerecho = nodo->hijo;
  if(tmpHijoMasDerecho == nullptr)
  {
    nodo->hijo = tmp;
    return tmp;
  }

  HMIHDConContador* tmpNull = tmpHijoMasDerecho->hermano; // Esta variable sirve para mantener registrado el nodo anterior cuando se llega al nodo nulo
  while(tmpNull != nullptr)
  {
    tmpNull = tmpNull->hermano;
    tmpHijoMasDerecho = tmpHijoMasDerecho->hermano;
  }
  tmpHijoMasDerecho->hermano = tmp;

  return tmp;
}

HMIHDConContador* HMIHDConContador::borrarHoja(HMIHDConContador* hoja)
{
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=  ARREGLAR  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
  HMIHDConContador* tmp = hoja;
  hoja->hermano = nullptr;
  hoja->hijo = nullptr;
  delete hoja;
  contador--;
  return tmp;
}

HMIHDConContador* HMIHDConContador::Padre(HMIHDConContador* nodo)
{
  if(nodo == raiz) { return nullptr; }
  vector<HMIHDConContador*> auxiliar; // Utilizado para almacenar tanto tmp como el padre de tmp
  HMIHDConContador* tmp = raiz;
  HMIHDConContador* padre;
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

HMIHDConContador* HMIHDConContador::HMI(HMIHDConContador* nodo)
{
  return nodo->hijo;
}

HMIHDConContador* HMIHDConContador::HD(HMIHDConContador* nodo)
{
  return nodo->hermano;
}

int HMIHDConContador::Etiqueta(HMIHDConContador* nodo)
{
  return nodo->etiqueta;
}

HMIHDConContador& HMIHDConContador::modificarEtiqueta(HMIHDConContador* nodo, int etiqueta)
{
  nodo->etiqueta = etiqueta;
  return *this;
}

int HMIHDConContador::numNodos()
{
  return contador;
}