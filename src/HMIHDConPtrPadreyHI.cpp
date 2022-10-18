// #include "HMIHDConPtrPadreyHI.h"
//=====  
#include "../include/HMIHDConPtrPadreyHI.h"
#include <vector>

shared_ptr<HMIHDConPtrPadreyHI> HMIHDConPtrPadreyHI::raiz = nullptr;

HMIHDConPtrPadreyHI::HMIHDConPtrPadreyHI()
{
  this->hijo = nullptr;
  this->hermanoDerecho = nullptr;
  this->hermanoIzquierdo = nullptr;
  this->padre = nullptr;
}

HMIHDConPtrPadreyHI::HMIHDConPtrPadreyHI(int etiqueta)
{
  this->etiqueta = etiqueta;
  this->hijo = nullptr;
  this->hermanoDerecho = nullptr;
  this->hermanoIzquierdo = nullptr;
  this->padre = nullptr;
}

HMIHDConPtrPadreyHI::~HMIHDConPtrPadreyHI()
{
  // delete raiz;
  // this->hijo = nullptr;
  // this->hermanoDerecho = nullptr;
  // this->hermanoIzquierdo = nullptr;
  // this->padre = nullptr;
}

HMIHDConPtrPadreyHI& HMIHDConPtrPadreyHI::ponerRaiz(int etiqueta)
{
  shared_ptr<HMIHDConPtrPadreyHI> tmp = make_shared<HMIHDConPtrPadreyHI>(etiqueta);
  raiz = tmp;
  return *this;
}

shared_ptr<HMIHDConPtrPadreyHI> HMIHDConPtrPadreyHI::Raiz()
{
  return raiz;
}

shared_ptr<HMIHDConPtrPadreyHI> HMIHDConPtrPadreyHI::agregarHijo(shared_ptr<HMIHDConPtrPadreyHI> nodo, int etiqueta)
{
  shared_ptr<HMIHDConPtrPadreyHI> tmp = make_shared<HMIHDConPtrPadreyHI>(etiqueta);
  shared_ptr<HMIHDConPtrPadreyHI> tmpHijoOriginal = nodo->hijo;
  nodo->hijo = tmp;
  tmp->hermanoDerecho = tmpHijoOriginal;
  if(tmpHijoOriginal != nullptr)
  {
    tmpHijoOriginal->hermanoIzquierdo = tmp;
  }
  tmp->padre = nodo;
  
  return tmp;
}

shared_ptr<HMIHDConPtrPadreyHI> HMIHDConPtrPadreyHI::agregarHijoMasDerecho (shared_ptr<HMIHDConPtrPadreyHI> nodo, int etiqueta)
{
  shared_ptr<HMIHDConPtrPadreyHI> tmp = make_shared<HMIHDConPtrPadreyHI>(etiqueta);
  shared_ptr<HMIHDConPtrPadreyHI> tmpHijoMasDerecho = nodo->hijo;
  if(tmpHijoMasDerecho == nullptr)
  {
    nodo->hijo = tmp;
    tmp->padre = nodo;
    return tmp;
  }

  shared_ptr<HMIHDConPtrPadreyHI> tmpNull = tmpHijoMasDerecho->hermanoDerecho; // Esta variable sirve para mantener registrado el nodo anterior cuando se llega al nodo nulo
  while(tmpNull != nullptr)
  {
    tmpNull = tmpNull->hermanoDerecho;
    tmpHijoMasDerecho = tmpHijoMasDerecho->hermanoDerecho;
  }
  tmpHijoMasDerecho->hermanoDerecho = tmp;
  tmp->hermanoIzquierdo = tmpHijoMasDerecho;
  tmp->padre = nodo;

  return tmp;
}

void HMIHDConPtrPadreyHI::borrarHoja(shared_ptr<HMIHDConPtrPadreyHI> hoja)
{
  if(hoja->hermanoIzquierdo == nullptr) //Caso HMI se borra
  {
    hoja->padre->hijo = hoja->hermanoDerecho;
    hoja->padre = nullptr;
    if(hoja->hermanoDerecho != nullptr)
    {
      hoja->hermanoDerecho->hermanoIzquierdo = nullptr;
    } 
  }
  else
  {
    hoja->hermanoIzquierdo->hermanoDerecho == nullptr;
    hoja->padre = nullptr;
    hoja->hermanoDerecho = nullptr;
    hoja->hermanoIzquierdo = nullptr;
    if(hoja->hermanoDerecho != nullptr)
    {
      hoja->hermanoDerecho->hermanoIzquierdo = nullptr;
    } 
  }
}

shared_ptr<HMIHDConPtrPadreyHI> HMIHDConPtrPadreyHI::Padre(shared_ptr<HMIHDConPtrPadreyHI> nodo)
{
  return nodo->padre;
}

shared_ptr<HMIHDConPtrPadreyHI> HMIHDConPtrPadreyHI::HMI(shared_ptr<HMIHDConPtrPadreyHI> nodo)
{
  return nodo->hijo;
}

shared_ptr<HMIHDConPtrPadreyHI> HMIHDConPtrPadreyHI::HD(shared_ptr<HMIHDConPtrPadreyHI> nodo)
{
  return nodo->hermanoDerecho;
}

int HMIHDConPtrPadreyHI::Etiqueta(shared_ptr<HMIHDConPtrPadreyHI> nodo)
{
  return nodo->etiqueta;
}

HMIHDConPtrPadreyHI& HMIHDConPtrPadreyHI::modificarEtiqueta(shared_ptr<HMIHDConPtrPadreyHI> nodo, int etiqueta)
{
  nodo->etiqueta = etiqueta;
  return *this;
}

int HMIHDConPtrPadreyHI::numNodos()
{
  if(raiz == nullptr) { return 0; }
  vector<shared_ptr<HMIHDConPtrPadreyHI>> auxiliar; 
  shared_ptr<HMIHDConPtrPadreyHI> tmp = raiz;
  auxiliar.push_back(tmp);
  int i = 0;
  while(i < auxiliar.size())
  {
    tmp = auxiliar[i];
    i++;
    tmp = tmp->hijo;

    while(tmp != nullptr)
    {
      auxiliar.push_back(tmp);
      tmp = tmp->hermanoDerecho;
    }
  }
  return i;
}