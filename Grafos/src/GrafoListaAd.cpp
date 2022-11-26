#include "../include/GrafoListaAd.hpp"
#include "../include/ListaIndexadaPlantilla.hpp"

using namespace std;


/*
 * Esta función devuelve el indice en el que se encuentra la arista hacía vértice2 en la lista de adyacenia del vértice1, y en el proceso pasa el contenedor en el tercer argumento en el caso que se quiera modificar
 */
int obtenerIndiceEnAdyacentes(VerticeListaAd* vertice1, VerticeListaAd* vertice2, VerticeListaAd::ContenedorAristas*& tmpP){
	int indice = 1;
	VerticeListaAd* tmp = nullptr; // Procurar que todo este lo mas controlado posible
	while(tmp != vertice2){
		tmp = vertice1->adyacentes.recuperar(indice)->vertice;
		indice++;
	}
	indice--;
	tmpP = vertice1->adyacentes.recuperar(indice);

	return indice;
}

GrafoListaAd::GrafoListaAd() {
	// this->vertices = new Lista<Vertice*>();
	// this->tam = 0;
	this->vertices.iniciar();
	this->vertices.insertar(nullptr, 1);

}

VerticeListaAd* GrafoListaAd::agregarVertice(string etiqueta){
	// TODO: Agregar "numNodos"
	VerticeListaAd* nuevoV = new VerticeListaAd(etiqueta);
	this->vertices.insertar(nuevoV, 1);
	return nuevoV;

}

void GrafoListaAd::eliminarVertice(string etiqueta){
// TODO: Hacer algoritmo
	 
}

void GrafoListaAd::modificarEtiqueta(VerticeListaAd* vertice, string etiqueta){
	vertice->etiqueta = etiqueta;
}

string GrafoListaAd::etiqueta(VerticeListaAd* vertice){
	return vertice->etiqueta;
}

void GrafoListaAd::agregarArista(VerticeListaAd* vertice1, VerticeListaAd* vertice2, int peso){
	VerticeListaAd::ContenedorAristas* nuevaArista = new VerticeListaAd::ContenedorAristas(vertice2, peso);
	vertice1->adyacentes.insertar(nuevaArista, 1);

	VerticeListaAd::ContenedorAristas* nuevaArista2 = new VerticeListaAd::ContenedorAristas(vertice1, peso);
	vertice2->adyacentes.insertar(nuevaArista2, 1);
}

void GrafoListaAd::eliminarArista(VerticeListaAd* vertice1, VerticeListaAd* vertice2){
	VerticeListaAd::ContenedorAristas* tmp;

	vertice1->adyacentes.borrar(obtenerIndiceEnAdyacentes(vertice1, vertice2, tmp));
	delete tmp;

	vertice2->adyacentes.borrar(obtenerIndiceEnAdyacentes(vertice2, vertice1, tmp));
	delete tmp;
}

void GrafoListaAd::modificarArtista(VerticeListaAd* vertice1, VerticeListaAd* vertice2, int peso){
	VerticeListaAd::ContenedorAristas* tmp;

	obtenerIndiceEnAdyacentes(vertice1, vertice2, tmp);
	tmp->peso = peso;

	obtenerIndiceEnAdyacentes(vertice2, vertice1, tmp);
	tmp->peso = peso;
	
}

int GrafoListaAd::peso(VerticeListaAd* vertice1, VerticeListaAd* vertice2){
	VerticeListaAd::ContenedorAristas* tmp;

	obtenerIndiceEnAdyacentes(vertice1, vertice2, tmp);
	return tmp->peso;
}

VerticeListaAd* GrafoListaAd::primerVertice(){
	return vertices.recuperar(1);
}

VerticeListaAd* GrafoListaAd::siguienteVertice(VerticeListaAd* vertice){

	VerticeListaAd* tmp;
	int ii = 1;
	while(tmp != vertice){
		tmp = this->vertices.recuperar(ii);
		ii++;
	}
	tmp = this->vertices.recuperar(ii);
	return tmp;
}

VerticeListaAd* GrafoListaAd::primerVerticeAdyacente(VerticeListaAd* vertice){
	return vertice->adyacentes.recuperar(1)->vertice;
}

VerticeListaAd* GrafoListaAd::siguienteVerticeAdyacente(VerticeListaAd* vertice1, VerticeListaAd* vertice2){
	VerticeListaAd::ContenedorAristas* tmp;

	return vertice1->adyacentes
		.recuperar(obtenerIndiceEnAdyacentes(vertice1, vertice2, tmp)+1)->vertice;
}


GrafoListaAd::~GrafoListaAd() {
	// this->vertices->iniciarCursor();
	// while (vertices->avanzarCursor()) {
	// 	delete this->vertices->obtenerCursor();
	// }
	// delete vertices;
}

