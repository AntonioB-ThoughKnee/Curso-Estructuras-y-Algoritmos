#ifndef VERTICE_LA_H
#define VERTICE_LA_H

#include <string>
#include "../include/ListaIndexadaPlantilla.hpp"

typedef class VerticeListaAd{
public:
  std::string etiqueta;
	struct ContenedorAristas{
		ContenedorAristas(VerticeListaAd* vertice, int peso) :
			peso(peso), vertice(vertice){}
		int peso;
		VerticeListaAd* vertice;
	};
  ListaIndexada<ContenedorAristas*> adyacentes;

	VerticeListaAd();
	VerticeListaAd(std::string etiqueta);
	~VerticeListaAd();

} Vertice;




#endif /* VERTICE_LA_H */
