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

void GrafoMatrizAd::iniciar(){
	;
	if(this->numNodos != 0){
		this->numNodos = 0;
		for(int ii = 0; ii < this->M ; ii++){
			this->vertices[ii] = "nullptr";
		}
	}
}

VerticeMatrizAd* GrafoMatrizAd::agregarVertice(string etiqueta){
	if(etiqueta.compare("nullptr") == 0) {
		cout << "NO se puede agregar un vértice con esa etiqueta " << endl;
		return nullptr;
	}
	int numN = this->numNodos;
	VerticeMatrizAd* nuevoV = new VerticeMatrizAd(numN);
	this->relacion1a1.insert(pair<int, string>(numN, etiqueta));
	for(int ii = 0; ii < this->M ; ii++){
		this->matrizVertices[numN][ii] = -1;
		this->matrizVertices[ii][numN] = -1;
	}
	vertices[numN] = etiqueta;
	verticesActuales[numN] = nuevoV;
	this->numNodos++;
	return nuevoV; 

}

void GrafoMatrizAd::eliminarVertice(string etiqueta){
	int indiceEliminado;
	VerticeMatrizAd* tmp;

	bool subirValores = false;
	bool moverValores = false;
	bool valorEncontrado = false;

	//Borrando de los arreglos
	relacion1a1.clear();
	for(int ii = 0; ii < this->M ; ii++){
		if((this->vertices[ii] == etiqueta || valorEncontrado) && ii < this->M-1){
			if(!valorEncontrado) indiceEliminado = ii;
			valorEncontrado = true;
			
			this->vertices[ii] = this->vertices[ii+1]; 
			tmp = this->verticesActuales[ii+1];
			this->verticesActuales[ii] = this->verticesActuales[ii+1];
			if(tmp != nullptr){
				tmp->numVertice = tmp->numVertice-1;
				this->relacion1a1.insert(pair<int, string>(tmp->numVertice, this->vertices[ii]));
			}
		}
		else if(valorEncontrado && ii == this->M-1){
			this->vertices[ii] = "nullptr";
			this->verticesActuales[ii] = nullptr;
		}
	}
	delete tmp;

	//Borrando de la matriz de adyacencia
	for(int ii = 0; ii < this->M  ; ii++){
		if(ii == indiceEliminado) subirValores = true;
		for(int iii = 0; iii < this->M  ; iii++){
			if(iii == indiceEliminado) moverValores = true;

			if(moverValores && !subirValores && iii < this->M-1){
				this->matrizVertices[ii][iii] = matrizVertices[ii][iii+1];
			}
			else if(moverValores && subirValores && iii < this->M-1 && ii < this->M-1){
				this->matrizVertices[ii][iii] = matrizVertices[ii][iii+1];
				this->matrizVertices[ii][iii] = matrizVertices[ii+1][iii];
			}
			else if(subirValores && iii < this->M-1){
				this->matrizVertices[ii][iii] = matrizVertices[ii+1][iii];
			}
			if(iii == this->M-1) this->matrizVertices[ii][iii] = -1;
			if(ii == this->M-1) this->matrizVertices[ii][iii] = -1;
		}
		moverValores = false;
	}

	this->numNodos--;
	return;	 
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

void GrafoMatrizAd::destruir(){
	for(int ii = 0; ii < this->M ; ii++){
		delete this->verticesActuales[ii];
	}
	this->~GrafoMatrizAd();
}


GrafoMatrizAd::~GrafoMatrizAd() {
	// this->vertices->iniciarCursor();
	// while (vertices->avanzarCursor()) {
	// 	delete this->vertices->obtenerCursor();
	// }
	// delete vertices;
}

