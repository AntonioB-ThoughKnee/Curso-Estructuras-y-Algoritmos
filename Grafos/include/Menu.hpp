#include "../include/Algoritmos.hpp"
#include "../include/SeleccionDeGrafo.hpp"
#include <iostream>
#include <map>

#ifndef MENUHPP
#define MENUHPP

class Menu
{
private:
    Grafo* grafo;
    std::map<std::string,Vertice*> idVertice;
public:
    Menu();
    ~Menu();
    void Run();
    void menuOperadores();
    void menuAlgoritmos();
    void menuCrear();
    void menuDestruir();
    void menuAgregarVertice(std::string etiqueta);
    void menuEliminarVertice(std::string etiqueta);
    void menuEtiqueta(int vertice);
    void menuAgregarArista(std::string etV1, std::string etV2, int peso);
    void menuEliminarArista(std::string etV1, std::string etV2);
    void menuModificarPeso(std::string etV1, std::string etV2, int peso);
    void menuPeso(std::string etV1, std::string etV2);
    void menuPrimerVertice();
    void menuSiguienteVertice(std::string etV);
    void menuPrimerVerticeAdyacente(std::string etiqueta);
    void menuSiguienteVerticeAdyacente(std::string etV1, std::string etV2);
    void menuNumVertices();
    void menuDijkstra(std::string etInicial);
    void menuFloyd();
    void menuNDijkstra();
    void menuPrim();
    void menuKruskal();
    void menuHamilton();
    void menuColoreo();
    void menuHamiltonBERA();
};

#endif