//
// Created by jean on 14/10/22.
//

#include "../include/ArregloSenaladorPadre.h"
//template<typename TipoNodo>
void ArregloPadre::Crear() {

}

//template<typename TipoNodo>
void ArregloPadre::Destruir() {

}

//template <typename TipoNodo>
void ArregloPadre::PonerRaiz(int etiqueta) {
  auto it = this->arreglo.begin();
  ArregloPadre::Nodo* tmp = new Nodo(0);

  this->arreglo.emplace(it, ArregloPadre::contenedorArreglo(etiqueta, tmp, tmp)); 
}

//template <typename TipoNodo>
ArregloPadre::Nodo* ArregloPadre::AgregarHijo(ArregloPadre::Nodo* nodoPadre, int etiqueta) {
  auto it = this->arreglo.end();
  ArregloPadre::Nodo* nuevo_nodo_id = new Nodo(this->arreglo.size());
  this->arreglo.emplace(it, ArregloPadre::contenedorArreglo(etiqueta, nodoPadre, nuevo_nodo_id)); // nodo_id empieza en 1
  return nuevo_nodo_id;
}
  // //===========================  
  // Nodo* tmp = new Nodo(etiqueta);
  // Nodo* tmpHijoOriginal = nodo->hijo;
  // nodo->hijo = tmp;
  // tmp->hermano = tmpHijoOriginal;
  // contador++;
  
  // return tmp;
  //=====  
ArregloPadre::Nodo* ArregloPadre::AgregarHijoMasDerecho(ArregloPadre::Nodo* nodoPadre, int etiqueta) {
  auto it = this->arreglo.end();
  ArregloPadre::Nodo* nuevo_nodo_id = new Nodo(this->arreglo.size());
  this->arreglo.emplace(it, ArregloPadre::contenedorArreglo(etiqueta, nodoPadre, nuevo_nodo_id));
  return nuevo_nodo_id; // Para el "outside-world" el arreglo empieza en 1, entonces tengo que sumarle 1.

}

//void ArregloPadre::BorrarHoja(int etiqueta) {
//  for (int i = 0 ; i < this->arreglo.size(); i++) {
//    if (this->arreglo[i].etiqueta == etiqueta) {
//      this->arreglo.erase(this->arreglo.begin()+i);
//    }
//  }
//}

void ArregloPadre::BorrarHoja(ArregloPadre::Nodo*  nodo_id_externo) {
  this->arreglo.erase(this->arreglo.begin()+(nodo_id_externo->indice));
}



ArregloPadre::Nodo* ArregloPadre::Raiz() {
  return (this->arreglo[0].nodo_id);
  
}

ArregloPadre::Nodo* ArregloPadre::Padre(ArregloPadre::Nodo* nodo_id_externo) {
  return (this->arreglo[nodo_id_externo->indice].padre);
}

ArregloPadre::Nodo* ArregloPadre::HMI(ArregloPadre::Nodo* nodo_id_externo_papa) {
  // Necesito recorrer todo el arreglo e ir guardando el nodo_id cada vez que encuentre un nodo que tenga el papa que fue
  // pasado por parametro. De esta manera el nodo_id restante es el nodo_id del hijo mas izquierdo.
  ArregloPadre::Nodo* toRet; // Nodo_id del hijo mas izquierdo, este valor va a ser devuelto.
  for (int i = 0; i < this->arreglo.size(); ++i) {
  // Técnicamente sería mas eficiente empezar i en el valor pasado por el parametro porque el hijo siempre tiene que estar
  // a la derecha del papá pero mejor por términos de efectividad lo voy a dejar asi.
    if (this->arreglo[i].padre == (nodo_id_externo_papa)) { // los nodos por debajo en mi programa empiezan en 0, por eso el -1
      return (this->arreglo[i].nodo_id);
    }
  }
  return toRet;
}

ArregloPadre::Nodo* ArregloPadre::HD(ArregloPadre::Nodo* nodo_id_hermano_externo) {
  ArregloPadre::Nodo* papaComun = this->arreglo[nodo_id_hermano_externo->indice].padre; // nodo por dentro es 1 valor menos por el arreglo.
  // Empieza en nodo_id_hermano porque de esta manera, si a la derecha del arreglo a partir de el encontramos a otro nodo con el mismo
  // papa entonces es el hermano derecho.
  for (int i = nodo_id_hermano_externo->indice; i < this->arreglo.size(); ++i) { // Le deberia hacer -1, pero ocupo que empiece a buscar 1 pos mayor, porque sino se encuentra a si mismo.
    if (this->arreglo[i].padre == papaComun) { // como es inmediatamente el siguiente encontrado a la derecha del arreglo, es el herm. der
      return (this->arreglo[i].nodo_id)+1;
    }
  }
  return papaComun;
}

int ArregloPadre::Etiqueta(ArregloPadre::Nodo* nodo_id_externo) {
  return this->arreglo[nodo_id_externo->indice].etiqueta;
}

void ArregloPadre::ModificaEtiqueta(ArregloPadre::Nodo* nodo_id_externo, int etiqueta) {
  this->arreglo[nodo_id_externo->indice].etiqueta = etiqueta;
}

int ArregloPadre::NumNodos() {
  return this->arreglo.size();
}


