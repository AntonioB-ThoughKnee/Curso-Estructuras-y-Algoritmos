#ifndef GRAFO_LA_H_
#define GRAFO_LA_H_
#include <iostream>
#include <string>
#include "../include/ListaIndexadaPlantilla.hpp"
#include "VerticeListaAd.hpp"
typedef class GrafoListaAd{
public:
	ListaIndexada<VerticeListaAd*> vertices;
	int numV;

	GrafoListaAd();
	~GrafoListaAd();
	VerticeListaAd* agregarVertice(std::string etiqueta);
	/**
	 * @brief Requiere vértice aislado
	 * 
	 * @param etiqueta 
	 */
	void eliminarVertice(std::string etiqueta);
	void modificarEtiqueta(VerticeListaAd* vertice, std::string etiqueta);
	std::string etiqueta(VerticeListaAd* vertice);
	void agregarArista(VerticeListaAd* vertice1, VerticeListaAd* vertice2, int peso);
	void eliminarArista(VerticeListaAd* vertice1, VerticeListaAd* vertice2);
	void modificarArtista(VerticeListaAd* vertice1, VerticeListaAd* vertice2, int peso);
	int peso(VerticeListaAd* vertice1, VerticeListaAd* vertice2);
	VerticeListaAd* primerVertice();
	VerticeListaAd* siguienteVertice(VerticeListaAd* vertice);
	VerticeListaAd* primerVerticeAdyacente(VerticeListaAd* vertice);
	VerticeListaAd* siguienteVerticeAdyacente(VerticeListaAd* vertice1, VerticeListaAd* vertice2);
	int numVertices();

} Grafo;


#endif /* GRAFO_LA_H_ */
