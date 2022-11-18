#include "../include/GrafoListaAd.hpp"
using namespace std;

GrafoListaAd::GrafoListaAd() {
	// this->vertices = new Lista<Vertice*>();
	// this->tam = 0;
}

VerticeListaAd* GrafoListaAd::agregarVertice(string etiqueta){
	VerticeListaAd* nuevoV = new VerticeListaAd(etiqueta);
	this->vertices.push_back(nuevoV);
	return nuevoV;

}
void GrafoListaAd::eliminarVertice(string etiqueta){
	// VerticeListaAd* nuevoV = vertices[0];

	 
}
void GrafoListaAd::modificarEtiqueta(VerticeListaAd* vertice, string etiqueta){
	vertice->etiqueta = etiqueta;
}
string GrafoListaAd::etiqueta(VerticeListaAd* vertice){
	return vertice->etiqueta;
}
void GrafoListaAd::agregarArista(VerticeListaAd* vertice1, VerticeListaAd* vertice2, int peso){
	VerticeListaAd::ContenedorAristas* nuevaArista = new VerticeListaAd::ContenedorAristas(vertice2, peso);
	vertice1->adyacentes.push_back((nuevaArista));

	VerticeListaAd::ContenedorAristas* nuevaArista2 = new VerticeListaAd::ContenedorAristas(vertice1, peso);
	vertice2->adyacentes.push_back((nuevaArista2));
}
void GrafoListaAd::eliminarArista(VerticeListaAd* vertice1, VerticeListaAd* vertice2){
	VerticeListaAd* tmp;
	vector<VerticeListaAd::ContenedorAristas*>::iterator it = vertice1->adyacentes.begin();
	while(tmp != vertice2){
		tmp = (*it)->vertice;
		// vertice1->adyacentes[it]->vertice;
		it++;
	}
	vertice1->adyacentes.erase(it);
	delete tmp;

	it = vertice2->adyacentes.begin();
	tmp = nullptr;
	while(tmp != vertice1){
		tmp = (*it)->vertice;
		// vertice1->adyacentes[it]->vertice;
		it++;
	}
	vertice1->adyacentes.erase(it);
	delete tmp;
}
void GrafoListaAd::modificarArtista(VerticeListaAd* vertice1, VerticeListaAd* vertice2, int peso){
	VerticeListaAd* tmp;
	vector<VerticeListaAd::ContenedorAristas*>::iterator it = vertice1->adyacentes.begin();
	while(tmp != vertice2){
		tmp = (*it)->vertice;
		it++;
	}
	(*it)->peso = peso;

	it = vertice2->adyacentes.begin();
	tmp = nullptr;
	while(tmp != vertice1){
		tmp = (*it)->vertice;
		it++;
	}
	(*it)->peso = peso;
}
int GrafoListaAd::peso(VerticeListaAd* vertice1, VerticeListaAd* vertice2){
	VerticeListaAd* tmp;
	vector<VerticeListaAd::ContenedorAristas*>::iterator it = vertice1->adyacentes.begin();
	while(tmp != vertice2){
		tmp = (*it)->vertice;
		it++;
	}
	return (*it)->peso;

}
VerticeListaAd* GrafoListaAd::primerVertice(){
	return vertices[0];
}
VerticeListaAd* GrafoListaAd::siguienteVertice(VerticeListaAd* vertice){
	VerticeListaAd* tmp;
	vector<VerticeListaAd*>::iterator it = this->vertices.begin();
	while(tmp != vertice){
		tmp = (*it);
		it++;
	}
	it++;
	return (*it);
}
VerticeListaAd* GrafoListaAd::primerVerticeAdyacente(VerticeListaAd* vertice){
	return vertice->adyacentes[0]->vertice;
	}
VerticeListaAd* GrafoListaAd::siguienteVerticeAdyacente(VerticeListaAd* vertice1, VerticeListaAd* vertice2){
	
	VerticeListaAd* tmp;
	vector<VerticeListaAd::ContenedorAristas*>::iterator it = vertice1->adyacentes.begin();
	while(tmp != vertice2){
		tmp = (*it)->vertice;
		it++;
	}
	it++;
	return (*it)->vertice;
}


GrafoListaAd::~GrafoListaAd() {
	// this->vertices->iniciarCursor();
	// while (vertices->avanzarCursor()) {
	// 	delete this->vertices->obtenerCursor();
	// }
	// delete vertices;
}

