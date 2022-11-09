#include "ListaIndexadaPlantilla.hpp"
#include "ColaPlantilla.hpp"
// #include "ArregloPadre.hpp"
// #include "HMIHDConPtrPadreOptimizado.hpp"
// #include "HMIHDConPtrPadreyHI.hpp"
// #include "ListaHijos.hpp"
#include "HMIHDConContador.hpp"
#include "Algoritmos.hpp"

class Test {
    private:
    
        Arbol* arbolAnchoPeq;
        Arbol* arbolAnchoMed;
        Arbol* arbolAnchoGrande;

        Arbol* arbolLargoPeq;
        Arbol* arbolLargoMed;
        Arbol* arbolLargoGrande;

        Arbol* arbolComunPeq;
        Arbol* arbolComunMed;
        Arbol* arbolComunGrande;

        int npeq;
        int nmed;
        int ngran;
    public:
        Test();
        ~Test();
        void Correr();
        void CrearArboles();
};