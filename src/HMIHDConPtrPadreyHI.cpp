// #include "HMIHDConPtrPadreyHI.h"
//=====  
#include "../include/HMIHDConPtrPadreyHI.h"
#include <vector>

HMIHDConPtrPadreyHI* HMIHDConPtrPadreyHI::raiz = nullptr;

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
  delete raiz;
  this->hijo = nullptr;
  this->hermanoDerecho = nullptr;
  this->hermanoIzquierdo = nullptr;
  this->padre = nullptr;
}

HMIHDConPtrPadreyHI& HMIHDConPtrPadreyHI::ponerRaiz(int etiqueta)
{
  HMIHDConPtrPadreyHI* tmp = new HMIHDConPtrPadreyHI(etiqueta);
  raiz = tmp;
  return *this;
}

HMIHDConPtrPadreyHI* HMIHDConPtrPadreyHI::Raiz()
{
  return raiz;
}

HMIHDConPtrPadreyHI* HMIHDConPtrPadreyHI::agregarHijo(HMIHDConPtrPadreyHI* nodo, int etiqueta)
{
  HMIHDConPtrPadreyHI* tmp = new HMIHDConPtrPadreyHI(etiqueta);
  HMIHDConPtrPadreyHI* tmpHijoOriginal = nodo->hijo;
  nodo->hijo = tmp;
  tmp->hermanoDerecho = tmpHijoOriginal;
  if(tmpHijoOriginal != nullptr)
  {
    tmpHijoOriginal->hermanoIzquierdo = tmp;
  }
  tmp->padre = nodo;
  
  return tmp;
}

HMIHDConPtrPadreyHI* HMIHDConPtrPadreyHI::agregarHijoMasDerecho (HMIHDConPtrPadreyHI* nodo, int etiqueta)
{
  HMIHDConPtrPadreyHI* tmp = new HMIHDConPtrPadreyHI(etiqueta);
  HMIHDConPtrPadreyHI* tmpHijoMasDerecho = nodo->hijo;
  if(tmpHijoMasDerecho == nullptr)
  {
    nodo->hijo = tmp;
    tmp->padre = nodo;
    return tmp;
  }

  HMIHDConPtrPadreyHI* tmpNull = tmpHijoMasDerecho->hermanoDerecho; // Esta variable sirve para mantener registrado el nodo anterior cuando se llega al nodo nulo
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

HMIHDConPtrPadreyHI* HMIHDConPtrPadreyHI::borrarHoja(HMIHDConPtrPadreyHI* hoja)
{
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=  ARREGLAR  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
  HMIHDConPtrPadreyHI* tmp = hoja;
  hoja->hermanoDerecho = nullptr;
  hoja->hijo = nullptr;
  delete hoja;
  return tmp;
}

HMIHDConPtrPadreyHI* HMIHDConPtrPadreyHI::Padre(HMIHDConPtrPadreyHI* nodo)
{
  return nodo->padre;
}

HMIHDConPtrPadreyHI* HMIHDConPtrPadreyHI::HMI(HMIHDConPtrPadreyHI* nodo)
{
  return nodo->hijo;
}

HMIHDConPtrPadreyHI* HMIHDConPtrPadreyHI::HD(HMIHDConPtrPadreyHI* nodo)
{
  return nodo->hermanoDerecho;
}

int HMIHDConPtrPadreyHI::Etiqueta(HMIHDConPtrPadreyHI* nodo)
{
  return nodo->etiqueta;
}

HMIHDConPtrPadreyHI& HMIHDConPtrPadreyHI::modificarEtiqueta(HMIHDConPtrPadreyHI* nodo, int etiqueta)
{
  nodo->etiqueta = etiqueta;
  return *this;
}

int HMIHDConPtrPadreyHI::numNodos()
{
  if(raiz == nullptr) { return 0; }
  vector<HMIHDConPtrPadreyHI*> auxiliar; 
  HMIHDConPtrPadreyHI* tmp = raiz;
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