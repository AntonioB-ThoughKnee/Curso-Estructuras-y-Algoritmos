#ifndef REL1A1HPP
#define REL1A1HPP

#include "SeleccionDeGrafo.hpp"
#include <map>

class Relacion1A1
{
    private:
        int numero;
        std::map<Vertice*,int>* izqADer;
        std::map<int,Vertice*>* derAizq;
    public:
        Relacion1A1();
        ~Relacion1A1();
        void insertar(Vertice* izq,int der);
        Vertice* getIzquierda(int& der);
        int getDerecha(Vertice*& izq);
};

#endif