//
// Created by Jean C on 10/19/2022.
//

#include "HMIHDConPtrPadreOptimizado.hpp"

#include <vector>


HMIHDConPtrPadreOptimizado::HMIHDConPtrPadreOptimizado()
{
}

void HMIHDConPtrPadreOptimizado::Destruir()
{
    vector<Nodo*> auxiliar;
    Nodo* tmp = raiz;
    Nodo* tmpSgte;
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

HMIHDConPtrPadreOptimizado& HMIHDConPtrPadreOptimizado::PonerRaiz(int etiqueta)
{
    Nodo*  tmp = new Nodo(etiqueta);
    raiz = move(tmp);
    return *this;
}

HMIHDConPtrPadreOptimizado::Nodo*  HMIHDConPtrPadreOptimizado::Raiz()
{
    Nodo* tmp = raiz;
    return tmp;
}

HMIHDConPtrPadreOptimizado::Nodo*  HMIHDConPtrPadreOptimizado::AgregarHijo(Nodo*  nodo, int etiqueta)
{
    Nodo*  tmp = new Nodo(etiqueta);
    Nodo* tmpHijoOriginal = nodo->hijo;
    nodo->hijo = tmp;
    tmp->hermano = tmpHijoOriginal;
    if(tmpHijoOriginal == nullptr)
    {
        tmp->hermano = nodo;
        tmp->tienePtrAlPadre = true;
    }

    return tmp;
}

HMIHDConPtrPadreOptimizado::Nodo*  HMIHDConPtrPadreOptimizado::AgregarHijoMasDerecho (Nodo*  nodo, int etiqueta)
{
    Nodo*  tmp = new Nodo(etiqueta);
    Nodo* tmpHijoMasDerecho = nodo->hijo;
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

void HMIHDConPtrPadreOptimizado::BorrarHoja(Nodo*  hoja)
{
    vector<Nodo* > auxiliar; // Utilizado para recorrer el árbol
    Nodo* tmp = raiz;
    Nodo* padre;
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
        Nodo*  tmp2  = tmp->hermano;
        tmp->hermano = tmp->hermano->hermano;
        tmp2->hermano = nullptr;
        tmp2->hijo = nullptr;
        delete tmp2;
    }
}

HMIHDConPtrPadreOptimizado::Nodo*  HMIHDConPtrPadreOptimizado::Padre(Nodo*  nodo)
{
    if(nodo == raiz) { return nullptr; }

    Nodo* tmp = nodo;
    while(tmp != nullptr && !(tmp->tienePtrAlPadre))
    {
        tmp = tmp->hermano;
    }
    return tmp->hermano;


}

HMIHDConPtrPadreOptimizado::Nodo*  HMIHDConPtrPadreOptimizado::HijoMasIzquierdo(
        HMIHDConPtrPadreOptimizado::Nodo *nodo) {
    return nodo->hijo;
}

HMIHDConPtrPadreOptimizado::Nodo*  HMIHDConPtrPadreOptimizado::HermanoDerecho(HMIHDConPtrPadreOptimizado::Nodo *nodo) {
    if(nodo->tienePtrAlPadre) {return nullptr; }
    return nodo->hermano;
}

int HMIHDConPtrPadreOptimizado::Etiqueta(Nodo*  nodo)
{
    return nodo->etiqueta;
}

HMIHDConPtrPadreOptimizado& HMIHDConPtrPadreOptimizado::ModificarEtiqueta(Nodo* nodo, int etiqueta)
{
    nodo->etiqueta = etiqueta;
    return *this;
}

int HMIHDConPtrPadreOptimizado::NumNodos()
{
    if(raiz == nullptr) { return 0; }
    vector<Nodo* > auxiliar;
    Nodo* tmp = raiz;
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