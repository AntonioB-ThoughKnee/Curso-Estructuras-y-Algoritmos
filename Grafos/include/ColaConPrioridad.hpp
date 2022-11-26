#ifndef COLACONPRIORIDAD_H_
#define COLACONPRIORIDAD_H_
#include <string>
#include "Nodo.hpp"

template<class T> class ColaPrioridad {
private:
	Nodo<T>* frente;
	Nodo<T>* fondo;
	unsigned int tam;
public:
	/*
	 * post: instancia de Cola vacía y lista para ser usada.
	 */
	ColaPrioridad();
	/*
	 * pre: el nodo debe existir
	 * post: Actualiza el valor de la prioridad del nodo y lo ordena en la cola.
	 */
	void actualizarValor(T vertice, unsigned int prioridad);
	/*
	 * post: devuelve si la Cola no tiene ningún elemento.
	 */
	bool estaVacia();
	/*
	 * post: agrega 'elemento' en el fondo de la Cola.
	 */
	void acolar(T elemento, unsigned int prioridad);
	/*
	 * pre: devuelve el tamanio de la cola
	 */
	unsigned int obtenerTam();
	/*
	 * pre : la Cola no está vacía.
	 * post: remueve el frente de la Cola y lo devuelve.
	 */
	T desacolar();
	/*
	 * pre : la Cola no está vacía.
	 * post: devuelve el frente de la Cola.
	 */
	T obtenerFrente();
	/*
	 * Ordena la cola segun la prioridad
	 */
	void ordenar();
	/*
	 * post: remueve todos los elementos y libera
	 * los recursos tomados por la estructura de datos.
	 */
	~ColaPrioridad();
};
template<class T>
ColaPrioridad<T>::ColaPrioridad() {
	this->frente = NULL;
	this->fondo = NULL;
	this->tam = 0;
}
template<class T>
bool ColaPrioridad<T>::estaVacia() {
	return (this->frente == NULL);
}
template<class T>
void ColaPrioridad<T>::acolar(T elemento, unsigned int prioridad) {
	Nodo<T>* nuevoFondo = new Nodo<T>(elemento);
	nuevoFondo->cambiarPrioridad(prioridad);
	if (this->estaVacia()) {
		this->frente = nuevoFondo;
		this->fondo = nuevoFondo;
	} else if (this->frente->obtenerPrioridad() > prioridad) {
		Nodo<T>* nodoSiguiente = this->frente;
		this->frente = nuevoFondo;
		nuevoFondo->cambiarSiguiente(nodoSiguiente);
	} else {
		Nodo<T>* aCambiar = this->frente;
		while(aCambiar->obtenerSiguiente() != NULL && aCambiar->obtenerSiguiente()->obtenerPrioridad()<prioridad){
			aCambiar=aCambiar->obtenerSiguiente();
		}
		Nodo<T>* siguiente = aCambiar->obtenerSiguiente();
		aCambiar->cambiarSiguiente(nuevoFondo);
		nuevoFondo->cambiarSiguiente(siguiente);
		if(siguiente==NULL){
			this->fondo = nuevoFondo;
		}
	}
	this->tam++;
}
template<class T>
void ColaPrioridad<T>::actualizarValor(T vertice, unsigned int valor){
	Nodo<T>* aux = this->frente;
	bool encontrado = (this->frente->obtenerDato() == vertice);
	while(aux!=NULL && !encontrado){
		aux = aux->obtenerSiguiente();
		encontrado = (aux->obtenerDato() == vertice);
	}
	if(encontrado){
		aux->cambiarPrioridad(valor);
	}
	this->ordenar();
}
template<class T>
unsigned int ColaPrioridad<T>::obtenerTam(){
	return this->tam;
}
template<class T>
void ColaPrioridad<T>::ordenar() {
	Nodo<T>* anterior = this->frente;
	unsigned int prioridadAnterior, i = 1, j = 1;
	T datoAnterior;

	while (i<=this->obtenerTam() ){
		Nodo<T>* siguiente = anterior->obtenerSiguiente();
		while (j<this->obtenerTam()-1) {
			if (anterior->obtenerPrioridad() > siguiente->obtenerPrioridad()) {
				prioridadAnterior = anterior->obtenerPrioridad();
				datoAnterior = anterior->obtenerDato();

				anterior->cambiarPrioridad(siguiente->obtenerPrioridad());
				anterior->cambiarDato(siguiente->obtenerDato());

				siguiente->cambiarPrioridad(prioridadAnterior);
				siguiente->cambiarDato(datoAnterior);
			}
			siguiente = siguiente->obtenerSiguiente();
			j++;
		}
		anterior = anterior->obtenerSiguiente();
		i++;
	}
}
template<class T>
T ColaPrioridad<T>::desacolar() {
	if (this->estaVacia()) {
		throw std::string("No se puede desacolar, la cola está vacía.");
	}
	Nodo<T>* frenteAnterior = this->frente;
	this->frente = frenteAnterior->obtenerSiguiente();
	if (this->frente == NULL) {
		this->fondo = NULL;
	}
	T elemento = frenteAnterior->obtenerDato();
	this->tam--;
	delete frenteAnterior;
	return elemento;
}
template<class T>
T ColaPrioridad<T>::obtenerFrente() {
	if (this->estaVacia()) {
		throw std::string("No se puede obtener el frente, la cola está vacía.");
	}
	T elemento = this->frente->obtenerDato();
	return elemento;
}

template<class T>
ColaPrioridad<T>::~ColaPrioridad() {
	while (!this->estaVacia()) {
		this->desacolar();
	}
}
#endif /* COLA_H_ */
