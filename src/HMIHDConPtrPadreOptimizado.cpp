// #include "HMIHDConPtrPadreOptimizado.h"
//=====  
#include "../include/HMIHDConPtrPadreOptimizado.h"

#include <vector>

shared_ptr<HMIHDConPtrPadreOptimizado>  HMIHDConPtrPadreOptimizado::raiz = nullptr;

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
  // delete this;
  // delete raiz;
  // delete this->hijo;
  // delete this->hermano;
}

HMIHDConPtrPadreOptimizado& HMIHDConPtrPadreOptimizado::ponerRaiz(int etiqueta)
{
  shared_ptr<HMIHDConPtrPadreOptimizado>  tmp = make_unique<HMIHDConPtrPadreOptimizado>(etiqueta);
  raiz = move(tmp);
  return *this;
}

shared_ptr<HMIHDConPtrPadreOptimizado> HMIHDConPtrPadreOptimizado::Raiz()
{
  shared_ptr<HMIHDConPtrPadreOptimizado> tmp = raiz;
  return tmp;
}

shared_ptr<HMIHDConPtrPadreOptimizado>  HMIHDConPtrPadreOptimizado::agregarHijo(shared_ptr<HMIHDConPtrPadreOptimizado>  nodo, int etiqueta)
{
  shared_ptr<HMIHDConPtrPadreOptimizado>  tmp = make_unique<HMIHDConPtrPadreOptimizado>(etiqueta);
  shared_ptr<HMIHDConPtrPadreOptimizado> tmpHijoOriginal = nodo->hijo;
  nodo->hijo = tmp;
  tmp->hermano = tmpHijoOriginal;
  if(tmpHijoOriginal == nullptr)
  {
    tmp->hermano = nodo;
    tmp->tienePtrAlPadre = true;
  }
  
  return tmp;
}

shared_ptr<HMIHDConPtrPadreOptimizado>  HMIHDConPtrPadreOptimizado::agregarHijoMasDerecho (shared_ptr<HMIHDConPtrPadreOptimizado>  nodo, int etiqueta)
{
  shared_ptr<HMIHDConPtrPadreOptimizado>  tmp = make_unique<HMIHDConPtrPadreOptimizado>(etiqueta);
  shared_ptr<HMIHDConPtrPadreOptimizado> tmpHijoMasDerecho = nodo->hijo;
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

void HMIHDConPtrPadreOptimizado::borrarHoja(shared_ptr<HMIHDConPtrPadreOptimizado>  hoja)
{
  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=  ARREGLAR  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
  
  vector<shared_ptr<HMIHDConPtrPadreOptimizado>> auxiliar; // Utilizado para recorrer el árbol
  shared_ptr<HMIHDConPtrPadreOptimizado> tmp = raiz;
  shared_ptr<HMIHDConPtrPadreOptimizado> padre;
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
      if( !(tmp->tienePtrAlPadre) )
      {
        tmp = tmp->hermano;
      }else
      {
        tmp = nullptr;
      }
    }
  }

  if(hojaEsHMI)
  {
    if(!(tmp->tienePtrAlPadre))
    {
      padre->hijo = tmp->hermano;
    } else
    {
      padre->hijo = nullptr;
    }
    tmp->hermano = nullptr;
  } else
  {
    tmp->hermano = tmp->hermano->hermano;
    tmp->hermano = tmp;
    tmp->hermano = nullptr;
  }

  // return tmp;void
}

shared_ptr<HMIHDConPtrPadreOptimizado>  HMIHDConPtrPadreOptimizado::Padre(shared_ptr<HMIHDConPtrPadreOptimizado>  nodo)
{
  if(nodo == raiz) { return nullptr; }

  shared_ptr<HMIHDConPtrPadreOptimizado> tmp = nodo;
  while(tmp != nullptr && !(tmp->tienePtrAlPadre))
  {
    tmp = tmp->hermano;
  }
  return tmp->hermano;


}

shared_ptr<HMIHDConPtrPadreOptimizado>  HMIHDConPtrPadreOptimizado::HMI(shared_ptr<HMIHDConPtrPadreOptimizado>  nodo)
{
  return nodo->hijo;
}

shared_ptr<HMIHDConPtrPadreOptimizado>  HMIHDConPtrPadreOptimizado::HD(shared_ptr<HMIHDConPtrPadreOptimizado>  nodo)
{
  if(nodo->tienePtrAlPadre) {return nullptr; }
  return nodo->hermano;
}

int HMIHDConPtrPadreOptimizado::Etiqueta(shared_ptr<HMIHDConPtrPadreOptimizado>  nodo)
{
  return nodo->etiqueta;
}

HMIHDConPtrPadreOptimizado& HMIHDConPtrPadreOptimizado::modificarEtiqueta(shared_ptr<HMIHDConPtrPadreOptimizado> nodo, int etiqueta)
{
  nodo->etiqueta = etiqueta;
  return *this;
}

int HMIHDConPtrPadreOptimizado::numNodos()
{
  if(raiz == nullptr) { return 0; }
  vector<shared_ptr<HMIHDConPtrPadreOptimizado>> auxiliar; 
  shared_ptr<HMIHDConPtrPadreOptimizado> tmp = raiz;
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