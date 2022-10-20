//
// Created by Jean C on 10/19/2022.
//

#include "../include/HMIHDConPtrPadreyHI.hpp"
// #include "HMIHDConPtrPadreyHI.h"
//=====
#include <vector>


HMIHDConPtrPadreyHI::HMIHDConPtrPadreyHI()
{
}

void HMIHDConPtrPadreyHI::Destruir()
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
        tmp->padre = nullptr;
        tmp->hermanoDerecho = nullptr;
        tmp->hermanoIzquierdo = nullptr;

        delete tmp;


        while(tmpSgte != nullptr)
        {
            auxiliar.push_back(tmpSgte);
            tmpSgte = tmpSgte->hermanoDerecho;
        }
    }
}

HMIHDConPtrPadreyHI::~HMIHDConPtrPadreyHI()
{
    // delete raiz;
    // this->hijo = nullptr;
    // this->hermanoDerecho = nullptr;
    // this->hermanoIzquierdo = nullptr;
    // this->padre = nullptr;
}

HMIHDConPtrPadreyHI& HMIHDConPtrPadreyHI::PonerRaiz(int etiqueta)
{
    Nodo* tmp = new Nodo(etiqueta);
    raiz = tmp;
    return *this;
}

HMIHDConPtrPadreyHI::Nodo* HMIHDConPtrPadreyHI::Raiz()
{
    return raiz;
}

HMIHDConPtrPadreyHI::Nodo* HMIHDConPtrPadreyHI::AgregarHijo(Nodo* nodo, int etiqueta)
{
    Nodo* tmp = new Nodo(etiqueta);
    Nodo* tmpHijoOriginal = nodo->hijo;
    nodo->hijo = tmp;
    tmp->hermanoDerecho = tmpHijoOriginal;
    if(tmpHijoOriginal != nullptr)
    {
        tmpHijoOriginal->hermanoIzquierdo = tmp;
    }
    tmp->padre = nodo;

    return tmp;
}

HMIHDConPtrPadreyHI::Nodo* HMIHDConPtrPadreyHI::AgregarHijoMasDerecho (Nodo* nodo, int etiqueta)
{
    Nodo* tmp = new Nodo(etiqueta);
    Nodo* tmpHijoMasDerecho = nodo->hijo;
    if(tmpHijoMasDerecho == nullptr)
    {
        nodo->hijo = tmp;
        tmp->padre = nodo;
        return tmp;
    }

    Nodo* tmpNull = tmpHijoMasDerecho->hermanoDerecho; // Esta variable sirve para mantener registrado el nodo anterior cuando se llega al nodo nulo
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

void HMIHDConPtrPadreyHI::BorrarHoja(Nodo* hoja)
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
        hoja->hermanoIzquierdo->hermanoDerecho = hoja-> hermanoDerecho;
        if(hoja->hermanoDerecho != nullptr)
        {
            hoja->hermanoDerecho->hermanoIzquierdo = hoja->hermanoIzquierdo;
        }
        hoja->padre = nullptr;
        hoja->hermanoDerecho = nullptr;
        hoja->hermanoIzquierdo = nullptr;

        delete hoja;

    }
}

HMIHDConPtrPadreyHI::Nodo* HMIHDConPtrPadreyHI::Padre(Nodo* nodo)
{
    return nodo->padre;
}

HMIHDConPtrPadreyHI::Nodo* HMIHDConPtrPadreyHI::HijoMasIzquierdo(HMIHDConPtrPadreyHI::Nodo *nodo) {
    return nodo->hijo;
}

HMIHDConPtrPadreyHI::Nodo* HMIHDConPtrPadreyHI::HermanoDerecho(HMIHDConPtrPadreyHI::Nodo *nodo) {
    return nodo->hermanoDerecho;
}

int HMIHDConPtrPadreyHI::Etiqueta(Nodo* nodo)
{
    return nodo->etiqueta;
}

HMIHDConPtrPadreyHI& HMIHDConPtrPadreyHI::ModificarEtiqueta(Nodo* nodo, int etiqueta)
{
    nodo->etiqueta = etiqueta;
    return *this;
}

int HMIHDConPtrPadreyHI::NumNodos()
{
    if(raiz == nullptr) { return 0; }
    vector<Nodo*> auxiliar;
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
            tmp = tmp->hermanoDerecho;
        }
    }
    return i;
}