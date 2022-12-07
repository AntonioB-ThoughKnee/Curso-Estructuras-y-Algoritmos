#ifndef GRAFO_MA_H_
#define GRAFO_MA_H_
#include <iostream>
#include <string>
#include <map>
#include "../include/ListaIndexadaPlantilla.hpp"
#include "../include/VerticeMatrizAd.hpp"

typedef class GrafoMatrizAd{
public:
	static int const M = 10;
	int matrizVertices[M][M];
	std::string vertices[M]; 
	VerticeMatrizAd* verticesActuales[M]; 
  std::map<int, std::string> relacion1a1; //Relación para traducir entre la matriz de adyacencia y las etiquetas
	int numNodos;

	GrafoMatrizAd();
	~GrafoMatrizAd();
	VerticeMatrizAd* agregarVertice(std::string etiqueta);
	void eliminarVertice(std::string etiqueta);
	void modificarEtiqueta(VerticeMatrizAd* vertice, std::string etiqueta);
	std::string etiqueta(VerticeMatrizAd* vertice);
	void agregarArista(VerticeMatrizAd* vertice1, VerticeMatrizAd* vertice2, int peso);
	void eliminarArista(VerticeMatrizAd* vertice1, VerticeMatrizAd* vertice2);
	void modificarArtista(VerticeMatrizAd* vertice1, VerticeMatrizAd* vertice2, int peso);
	int peso(VerticeMatrizAd* vertice1, VerticeMatrizAd* vertice2);
	VerticeMatrizAd* primerVertice();
	VerticeMatrizAd* siguienteVertice(VerticeMatrizAd* vertice);
	VerticeMatrizAd* primerVerticeAdyacente(VerticeMatrizAd* vertice);
	VerticeMatrizAd* siguienteVerticeAdyacente(VerticeMatrizAd* vertice1, VerticeMatrizAd* vertice2);
	int numVertices();

} Grafo;


#endif /* GRAFO_MA_H_ */
