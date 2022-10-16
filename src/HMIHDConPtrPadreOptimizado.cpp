// #include "HMIHDConPtrPadreOptimizado.h"
//=====  
#include "../include/HMIHDConPtrPadreOptimizado.h"

#include <vector>

HMIHDConPtrPadreOptimizado* HMIHDConPtrPadreOptimizado::raiz = nullptr;

HMIHDConPtrPadreOptimizado::HMIHDConPtrPadreOptimizado()
{
  this->hijo = nullptr;
  this->hermano = nullptr;
  this->tienePtrAlPadre = false;
}

HMIHDConPtrPadreOptimizado::HMIHDConPtrPadreOptimizado(int etiqueta)
{
  this->etiqueta = etiqueta;
  this->hijo = nullptr;
  this->hermano = nullptr;
  this->tienePtrAlPadre = false;
}

HMIHDConPtrPadreOptimizado::~HMIHDConPtrPadreOptimizado()
{
  delete raiz;
  delete this->hijo;
  delete this->hermano;
}

HMIHDConPtrPadreOptimizado& HMIHDConPtrPadreOptimizado::ponerRaiz(int etiqueta)
{
  HMIHDConPtrPadreOptimizado* tmp = new HMIHDConPtrPadreOptimizado(etiqueta);
  raiz = tmp;
  return *this;
}

HMIHDConPtrPadreOptimizado* HMIHDConPtrPadreOptimizado::Raiz()
{
  return raiz;
}

HMIHDConPtrPadreOptimizado* HMIHDConPtrPadreOptimizado::agregarHijo(HMIHDConPtrPadreOptimizado* nodo, int etiqueta)
{
  HMIHDConPtrPadreOptimizado* tmp = new HMIHDConPtrPadreOptimizado(etiqueta);
  HMIHDConPtrPadreOptimizado* tmpHijoOriginal = nodo->hijo;
  nodo->hijo = tmp;
  tmp->hermano = tmpHijoOriginal;
  if(tmpHijoOriginal == nullptr)
  {
    tmp->hermano = nodo;
    tmp->tienePtrAlPadre = true;
  }
  
  return tmp;
}

HMIHDConPtrPadreOptimizado* HMIHDConPtrPadreOptimizado::agregarHijoMasDerecho (HMIHDConPtrPadreOptimizado* nodo, int etiqueta)
{
  HMIHDConPtrPadreOptimizado* tmp = new HMIHDConPtrPadreOptimizado(etiqueta);
  HMIHDConPtrPadreOptimizado* tmpHijoMasDerecho = nodo->hijo;
  while(tmpHijoMasDerecho != nullptr && !(tmpHijoMasDerecho->tienePtrAlPadre))
  {
    tmpHijoMasDerecho = tmpHijoMasDerecho->hermano;
  }

  if(tmpHijoMasDerecho != nullptr)
  {
    tmpHijoMasDerecho->hermano = tmp;
    tmpHijoMasDerecho->tienePtrAlPadre = false;
  }else
  {
    nodo->hijo = tmp;
  }
  tmp->hermano = nodo;
  tmp->tienePtrAlPadre = true;
  

  return tmp;
}

HMIHDConPtrPadreOptimizado* HMIHDConPtrPadreOptimizado::borrarHoja(HMIHDConPtrPadreOptimizado* hoja)
{
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=  ARREGLAR  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
  HMIHDConPtrPadreOptimizado* tmp = hoja;
  hoja->hermano = nullptr;
  hoja->hijo = nullptr;
  delete hoja;
  return tmp;
}

HMIHDConPtrPadreOptimizado* HMIHDConPtrPadreOptimizado::Padre(HMIHDConPtrPadreOptimizado* nodo)
{
  if(nodo == raiz) { return nullptr; }

  HMIHDConPtrPadreOptimizado* tmp = nodo;
  while(tmp != nullptr && !(tmp->tienePtrAlPadre))
  {
    tmp = tmp->hermano;
  }
  return tmp->hermano;


}

HMIHDConPtrPadreOptimizado* HMIHDConPtrPadreOptimizado::HMI(HMIHDConPtrPadreOptimizado* nodo)
{
  return nodo->hijo;
}

HMIHDConPtrPadreOptimizado* HMIHDConPtrPadreOptimizado::HD(HMIHDConPtrPadreOptimizado* nodo)
{
  if(nodo->tienePtrAlPadre) {return nullptr; }
  return nodo->hermano;
}

int HMIHDConPtrPadreOptimizado::Etiqueta(HMIHDConPtrPadreOptimizado* nodo)
{
  return nodo->etiqueta;
}

HMIHDConPtrPadreOptimizado& HMIHDConPtrPadreOptimizado::modificarEtiqueta(HMIHDConPtrPadreOptimizado* nodo, int etiqueta)
{
  nodo->etiqueta = etiqueta;
  return *this;
}

int HMIHDConPtrPadreOptimizado::numNodos()
{
  if(raiz == nullptr) { return 0; }
  vector<HMIHDConPtrPadreOptimizado*> auxiliar; 
  HMIHDConPtrPadreOptimizado* tmp = raiz;
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
      if( !(tmp->tienePtrAlPadre) )
      {
        tmp = tmp->hermano;
      }else
      {
        tmp = nullptr;
      }
    }
  }
  return i;
}