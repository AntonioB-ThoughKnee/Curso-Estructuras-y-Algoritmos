#include "../include/VerticeListaAd.hpp"

using namespace std;

VerticeListaAd::VerticeListaAd(){
}
VerticeListaAd::VerticeListaAd(std::string etiqueta){
	this->etiqueta = etiqueta;
	VerticeListaAd::ContenedorAristas* contenedorVacio = new ContenedorAristas(nullptr, 0);
	this->adyacentes.insertar(contenedorVacio, 1);
}
VerticeListaAd::~VerticeListaAd(){}
