//
// Created by Jean C on 10/19/2022.
//

#include "../include/ArregloPadre.hpp"
#include <iostream>
//
// Created by jean on 14/10/22.
//

//template<typename TipoNodo>
void ArregloPadre::Crear() {

}

//template<typename TipoNodo>
void ArregloPadre::Destruir() { // TODO: llamarlo.
  for (int i = 0; i < this->arreglo.size(); i++) {
    delete this->arreglo[i];
  }
}

//template <typename TipoNodo>
void ArregloPadre::PonerRaiz(int etiqueta) {
  auto it = this->arreglo.begin();
  ArregloPadre::contenedorArreglo* newContenedor = new ArregloPadre::contenedorArreglo(etiqueta, nullptr, 0);
  // this->arreglo.emplace(it, newContenedor); // -1 porque no tiene papá.
  this->arreglo.push_back(newContenedor); // -1 porque no tiene papá.
}

//template <typename TipoNodo>
ArregloPadre::contenedorArreglo* ArregloPadre::AgregarHijo(contenedorArreglo* nodoPadre,int etiqueta) {
  auto it = this->arreglo.end();
  int nuevo_nodo_id = this->arreglo.size();
//  this->arreglo.emplace(it, ArregloPadre::contenedorArreglo(etiqueta, nodoPadre->nodo_id-1, nuevo_nodo_id)); // nodo_id empieza en 1
  ArregloPadre::contenedorArreglo* newContenedor = new contenedorArreglo(etiqueta, nodoPadre, nuevo_nodo_id);
  this->arreglo.push_back(newContenedor);

//  this->arreglo.emplace(it, ArregloPadre::contenedorArreglo(etiqueta, nodoPadre->nodo_id, nuevo_nodo_id)); // nodo_id empieza en 1
  // return nuevo_nodo_id+1; // Para el "outside-world" el arreglo empieza en 1, entonces tengo que sumarle 1.
//  ArregloPadre::Nodo* toRet = &(this->arreglo.back());
//  return toRet;
  return newContenedor;
//  return &(this->arreglo.back());
}

ArregloPadre::contenedorArreglo* ArregloPadre::AgregarHijoMasDerecho(contenedorArreglo* nodoPadre, int etiqueta) {
  auto it = this->arreglo.end();
  int nuevo_nodo_id = this->arreglo.size();
//  this->arreglo.emplace(it, ArregloPadre::contenedorArreglo(etiqueta, nodoPadre->nodo_id-1, nuevo_nodo_id));
  // this->arreglo.emplace(it, ArregloPadre::contenedorArreglo(etiqueta, nodoPadre->nodo_id, nuevo_nodo_id));
  // return nuevo_nodo_id+1; // Para el "outside-world" el arreglo empieza en 1, entonces tengo que sumarle 1.
  // ArregloPadre::contenedorArreglo* toRet = &(this->arreglo.back());
  // return toRet;
  ArregloPadre::contenedorArreglo* newContenedor = new contenedorArreglo(etiqueta, nodoPadre, nuevo_nodo_id);
  this->arreglo.push_back((newContenedor));
  return newContenedor;
  // return (this->arreglo.back());

}

void ArregloPadre::BorrarHoja(ArregloPadre::contenedorArreglo* nodo) {
 for (int i = 0 ; i < this->arreglo.size(); i++) {
   if (this->arreglo[i]->etiqueta == nodo->etiqueta) {
     this->arreglo.erase(this->arreglo.begin()+i);
   }
 }
}
// void ArregloPadre::BorrarHoja(ArregloPadre::contenedorArreglo* nodo_id_externo) {
// //  this->arreglo.erase(this->arreglo.begin()+(nodo_id_externo->nodo_id-1));
//   this->arreglo.erase(this->arreglo.begin()+(nodo_id_externo->nodo_id));

// }



ArregloPadre::contenedorArreglo* ArregloPadre::Raiz() {
  if (!this->arreglo.empty()) {
    return (this->arreglo[0]);
  }
  return nullptr; // Arbol esta vacio.
}

ArregloPadre::contenedorArreglo* ArregloPadre::Padre(ArregloPadre::contenedorArreglo* nodo_id_externo) {
//   return &(this->arreglo[this->arreglo[nodo_id_externo->nodo_id-1].padre]);
  // return &(this->arreglo[this->arreglo[nodo_id_externo->nodo_id].padre]);
  return nodo_id_externo->padre;
}

ArregloPadre::contenedorArreglo* ArregloPadre::HijoMasIzquierdo(ArregloPadre::contenedorArreglo* nodo_id_externo_papa) {
  // Necesito recorrer todo el arreglo e ir guardando el nodo_id cada vez que encuentre un nodo que tenga el papa que fue
  // pasado por parametro. De esta manera el nodo_id restante es el nodo_id del hijo mas izquierdo.
  int toRet = -1; // Nodo_id del hijo mas izquierdo, este valor va a ser devuelto.
  for (int i = 0; i < this->arreglo.size(); ++i) {
    // Técnicamente sería mas eficiente empezar i en el valor pasado por el parametro porque el hijo siempre tiene que estar
    // a la derecha del papá pero mejor por términos de efectividad lo voy a dejar asi.
//    if (this->arreglo[i].padre == (nodo_id_externo_papa->nodo_id-1)) { // los nodos por debajo en mi programa empiezan en 0, por eso el -1

    if (this->arreglo[i]->padre) {
      if (this->arreglo[i]->padre->etiqueta == (nodo_id_externo_papa->etiqueta)) { // los nodos por debajo en mi programa empiezan en 0, por eso el -1

        return (this->arreglo[i]);
      }

    }
  }
  return nullptr;
}

ArregloPadre::contenedorArreglo* ArregloPadre::HermanoDerecho(ArregloPadre::contenedorArreglo* nodo_id_hermano_externo) {
  // std::cout << "Prueba\n";
//  int papaComun = this->arreglo[nodo_id_hermano_externo->nodo_id-1].padre; // nodo por dentro es 1 valor menos por el arreglo.
  // int papaComun = this->arreglo[nodo_id_hermano_externo->nodo_id].padre; // nodo por dentro es 1 valor menos por el arreglo.
  int papaComun = -2;
  if (nodo_id_hermano_externo->padre) {
    papaComun = nodo_id_hermano_externo->padre->etiqueta;

  }

  // Empieza en nodo_id_hermano porque de esta manera, si a la derecha del arreglo a partir de el encontramos a otro nodo con el mismo
  // papa entonces es el hermano derecho.
  // for (int i = nodo_id_hermano_externo->nodo_id+1; i < this->arreglo.size(); ++i) { // Le deberia hacer -1, pero ocupo que empiece a buscar 1 pos mayor, porque sino se encuentra a si mismo.
  bool encontrado = false;
  for (int i = 0; i < this->arreglo.size(); ++i) { // Le deberia hacer -1, pero ocupo que empiece a buscar 1 pos mayor, porque sino se encuentra a si mismo.
    if (this->arreglo[i]->padre) {
      if ((this->arreglo[i]->padre->etiqueta == papaComun) && encontrado) { // como es inmediatamente el siguiente encontrado a la derecha del arreglo, es el herm. der
        return (this->arreglo[i]);
      }
    }
    if (this->arreglo[i]->etiqueta == nodo_id_hermano_externo->etiqueta) {
      encontrado = true;
    }
  }
  return nullptr;
}

int ArregloPadre::Etiqueta(ArregloPadre::contenedorArreglo* nodo_id_externo) {
  return nodo_id_externo->etiqueta;
}

void ArregloPadre::ModificarEtiqueta(ArregloPadre::contenedorArreglo* nodo_id_externo, int etiqueta) {
  // this->arreglo[nodo_id_externo-1].etiqueta = etiqueta;
  nodo_id_externo->etiqueta = etiqueta;
}

int ArregloPadre::NumNodos() {
  return this->arreglo.size();
}

