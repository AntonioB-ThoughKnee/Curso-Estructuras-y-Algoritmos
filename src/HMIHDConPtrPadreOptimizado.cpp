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

void HMIHDConPtrPadreOptimizado::destruir()
{
  vector<HMIHDConPtrPadreOptimizado*> auxiliar; 
  HMIHDConPtrPadreOptimizado*tmp = raiz;
  HMIHDConPtrPadreOptimizado*tmpSgte;
  auxiliar.push_back(tmp);
  int i = 0;
  while(i < auxiliar.size())
  {
    tmp = auxiliar[i];
    i++;
    tmpSgte = tmp->hijo;

    tmp->hijo = nullptr;
    tmp->hermano = nullptr;
    delete tmp;


    while(tmpSgte != nullptr)
    {
      auxiliar.push_back(tmpSgte);
      if( !(tmpSgte->tienePtrAlPadre) )
      {
        tmpSgte = tmpSgte->hermano;
      }else
      {
        tmpSgte = nullptr;
      }
    }
  }

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
  HMIHDConPtrPadreOptimizado* tmp = new HMIHDConPtrPadreOptimizado(etiqueta);
  raiz = move(tmp);
  return *this;
}

HMIHDConPtrPadreOptimizado*HMIHDConPtrPadreOptimizado::Raiz()
{
  HMIHDConPtrPadreOptimizado*tmp = raiz;
  return tmp;
}

HMIHDConPtrPadreOptimizado* HMIHDConPtrPadreOptimizado::agregarHijo(HMIHDConPtrPadreOptimizado* nodo, int etiqueta)
{
  HMIHDConPtrPadreOptimizado* tmp = new HMIHDConPtrPadreOptimizado(etiqueta);
  HMIHDConPtrPadreOptimizado*tmpHijoOriginal = nodo->hijo;
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
  HMIHDConPtrPadreOptimizado*tmpHijoMasDerecho = nodo->hijo;
  while(tmpHijoMasDerecho != nullptr && !(tmpHijoMasDerecho->tienePtrAlPadre)) //Avanzar hasta el hijo mas derecho de nodo
  {
    tmpHijoMasDerecho = tmpHijoMasDerecho->hermano;
  }

  if(tmpHijoMasDerecho != nullptr) //Caso en el que existen hijos de nodo
  {
    tmpHijoMasDerecho->hermano = tmp;
    tmpHijoMasDerecho->tienePtrAlPadre = false;
  }else //Caso en el que el hijo de nodo no existe
  {
    nodo->hijo = tmp;
  }
  tmp->hermano = nodo;
  tmp->tienePtrAlPadre = true;
  

  return tmp;
}

void HMIHDConPtrPadreOptimizado::borrarHoja(HMIHDConPtrPadreOptimizado* hoja)
{  
  vector<HMIHDConPtrPadreOptimizado*> auxiliar; // Utilizado para recorrer el árbol
  HMIHDConPtrPadreOptimizado*tmp = raiz;
  HMIHDConPtrPadreOptimizado*padre;
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
    delete tmp;
  } else
  {
    if((tmp->hermano->tienePtrAlPadre))//Verificando si hoja tiene puntero al padre y darle ese puntero a su hermano derecho
    {
      tmp->tienePtrAlPadre = true;
    }
    HMIHDConPtrPadreOptimizado* tmp2  = tmp->hermano;
    tmp->hermano = tmp->hermano->hermano;
    tmp2->hermano = nullptr;
    tmp2->hijo = nullptr;
    delete tmp2;
  }
}

HMIHDConPtrPadreOptimizado* HMIHDConPtrPadreOptimizado::Padre(HMIHDConPtrPadreOptimizado* nodo)
{
  if(nodo == raiz) { return nullptr; }

  HMIHDConPtrPadreOptimizado*tmp = nodo;
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

HMIHDConPtrPadreOptimizado& HMIHDConPtrPadreOptimizado::modificarEtiqueta(HMIHDConPtrPadreOptimizado*nodo, int etiqueta)
{
  nodo->etiqueta = etiqueta;
  return *this;
}

int HMIHDConPtrPadreOptimizado::numNodos()
{
  if(raiz == nullptr) { return 0; }
  vector<HMIHDConPtrPadreOptimizado*> auxiliar; 
  HMIHDConPtrPadreOptimizado*tmp = raiz;
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