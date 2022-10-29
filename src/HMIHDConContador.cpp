//
// Created by Jean C on 10/19/2022.
//

#include "../include/HMIHDConContador.hpp"

#include <vector>

void HMIHDConContador::Crear()
{
    raiz = nullptr;
    contador = 0;
}

void HMIHDConContador::Destruir()
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
            tmpSgte = tmpSgte->hermano;
        }
    }
    contador = 0;
}

HMIHDConContador::~HMIHDConContador()
{
    // delete raiz;
    // delete this->hijo;
    // delete this->hermano;
}

HMIHDConContador& HMIHDConContador::PonerRaiz(int etiqueta)
{
    Nodo* tmp = new Nodo(etiqueta);
    raiz = tmp;
    contador++;
    return *this;
}

HMIHDConContador::Nodo* HMIHDConContador::Raiz()
{
    return raiz;
}

HMIHDConContador::Nodo* HMIHDConContador::AgregarHijo(Nodo* nodo, int etiqueta)
{
    Nodo* tmp = new Nodo(etiqueta);
    Nodo* tmpHijoOriginal = nodo->hijo;
    nodo->hijo = tmp;
    tmp->hermano = tmpHijoOriginal;
    contador++;

    return tmp;
}

HMIHDConContador::Nodo* HMIHDConContador::AgregarHijoMasDerecho (Nodo* nodo, int etiqueta)
{
    contador++;
    Nodo* tmp = new Nodo(etiqueta);
    Nodo* tmpHijoMasDerecho = nodo->hijo;
    if(tmpHijoMasDerecho == nullptr)
    {
        nodo->hijo = tmp;
        return tmp;
    }

    Nodo* tmpNull = tmpHijoMasDerecho->hermano; // Esta variable sirve para mantener registrado el nodo anterior cuando se llega al nodo nulo
    while(tmpNull != nullptr)
    {
        tmpNull = tmpNull->hermano;
        tmpHijoMasDerecho = tmpHijoMasDerecho->hermano;
    }
    tmpHijoMasDerecho->hermano = tmp;

    return tmp;
}

void HMIHDConContador::BorrarHoja(Nodo* hoja)
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
            tmp = tmp->hermano;
        }
    }

    if(hojaEsHMI)
    {
        padre->hijo = tmp->hermano;
        tmp->hermano = nullptr;
    } else
    {
        padre = tmp->hermano;
        tmp->hermano = tmp->hermano->hermano;
        tmp = padre;
    }
    delete tmp;
    contador--;
}

HMIHDConContador::Nodo* HMIHDConContador::Padre(Nodo* nodo)
{
    if(nodo == raiz) { return nullptr; }
    vector<Nodo* > auxiliar; // Utilizado para almacenar tanto tmp como el padre de tmp
    Nodo* tmp = raiz;
    Nodo* padre;
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

HMIHDConContador::Nodo* HMIHDConContador::HijoMasIzquierdo(Nodo* nodo)
{
    return nodo->hijo;
}

HMIHDConContador::Nodo* HMIHDConContador::HermanoDerecho(HMIHDConContador::Nodo *nodo) {
    return nodo->hermano;
}

int HMIHDConContador::Etiqueta(Nodo* nodo)
{
    return nodo->etiqueta;
}

HMIHDConContador& HMIHDConContador::ModificarEtiqueta(Nodo* nodo, int etiqueta)
{
    nodo->etiqueta = etiqueta;
    return *this;
}

int HMIHDConContador::NumNodos()
{
    return contador;
}