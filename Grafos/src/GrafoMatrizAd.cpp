#include "../include/GrafoMatrizAd.hpp"
#include "../include/ListaIndexadaPlantilla.hpp"
#include <map>

using namespace std;

GrafoMatrizAd::GrafoMatrizAd() {
	// this->vertices = new Lista<Vertice*>();
	this->numNodos = 0;
	for(int ii = 0; ii < this->M ; ii++){
		this->vertices[ii] = "nullptr";
	}
	
}

VerticeMatrizAd* GrafoMatrizAd::agregarVertice(string etiqueta){
	if(etiqueta.compare("nullptr") == 0) {
		cout << "NO se puede agregar un vértice con esa etiqueta " << endl;
		return nullptr;
	}
	VerticeMatrizAd* nuevoV = new VerticeMatrizAd(numNodos);
	this->relacion1a1.insert(pair<int, string>(numNodos, etiqueta));
	for(int ii = 0; ii < this->M ; ii++){
		this->matrizVertices[numNodos][ii] = -1;
		this->matrizVertices[ii][numNodos] = -1;
	}
	vertices[numNodos] = etiqueta;
	verticesActuales[numNodos] = nuevoV;
	numNodos++;
	return nuevoV; 

}

void GrafoMatrizAd::eliminarVertice(string etiqueta){
	// VerticeMatrizAd* nuevoV = vertices[0];
	

	 
}

void GrafoMatrizAd::modificarEtiqueta(VerticeMatrizAd* vertice, string etiqueta){
	this->vertices[vertice->numVertice] = etiqueta;
}

string GrafoMatrizAd::etiqueta(VerticeMatrizAd* vertice){
	return this->vertices[vertice->numVertice];
}

void GrafoMatrizAd::agregarArista(VerticeMatrizAd* vertice1, VerticeMatrizAd* vertice2, int peso){
	this->matrizVertices[vertice1->numVertice][vertice2->numVertice] = peso;
	this->matrizVertices[vertice2->numVertice][vertice1->numVertice] = peso;
}

void GrafoMatrizAd::eliminarArista(VerticeMatrizAd* vertice1, VerticeMatrizAd* vertice2){
	this->matrizVertices[vertice1->numVertice][vertice2->numVertice] = -1;
	this->matrizVertices[vertice2->numVertice][vertice1->numVertice] = -1;
}

void GrafoMatrizAd::modificarArtista(VerticeMatrizAd* vertice1, VerticeMatrizAd* vertice2, int peso){
	this->matrizVertices[vertice1->numVertice][vertice2->numVertice] = peso;
	this->matrizVertices[vertice2->numVertice][vertice1->numVertice] = peso;
}

int GrafoMatrizAd::peso(VerticeMatrizAd* vertice1, VerticeMatrizAd* vertice2){
	return this->matrizVertices[vertice2->numVertice][vertice1->numVertice];
}

VerticeMatrizAd* GrafoMatrizAd::primerVertice(){
	VerticeMatrizAd* tmp = this->verticesActuales[0];
	if(this->vertices[tmp->numVertice] == "nullptr"){
		return nullptr;
	}
	return tmp;
}

VerticeMatrizAd* GrafoMatrizAd::siguienteVertice(VerticeMatrizAd* vertice){	
	VerticeMatrizAd* tmp = this->verticesActuales[vertice->numVertice + 1];
	// if(this->vertices[tmp->numVertice] == "nullptr"){
	return tmp;
}

VerticeMatrizAd* GrafoMatrizAd::primerVerticeAdyacente(VerticeMatrizAd* vertice){
	VerticeMatrizAd* tmp;
	for(int ii = 0; ii < this->M ; ii++){
		if(this->matrizVertices[vertice->numVertice][ii] != -1){
			tmp = this->verticesActuales[ii];
			return tmp;
		}
	}
	return nullptr;
}

VerticeMatrizAd* GrafoMatrizAd::siguienteVerticeAdyacente(VerticeMatrizAd* vertice1, VerticeMatrizAd* vertice2){
	VerticeMatrizAd* tmp;
	if(this->matrizVertices[vertice1->numVertice][vertice2->numVertice] != -1 ){
		for(int ii = vertice2->numVertice+1; ii < this->M ; ii++){
			if(this->matrizVertices[vertice1->numVertice][ii] != -1){
				tmp = this->verticesActuales[ii];
				return tmp;
			}
		}
		
	}
	return nullptr;
}

int GrafoMatrizAd::numVertices(){
	return this->numNodos;
}


GrafoMatrizAd::~GrafoMatrizAd() {
	// this->vertices->iniciarCursor();
	// while (vertices->avanzarCursor()) {
	// 	delete this->vertices->obtenerCursor();
	// }
	// delete vertices;
}

