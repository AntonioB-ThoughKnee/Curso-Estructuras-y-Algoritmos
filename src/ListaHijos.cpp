
#include "../include/ListaHijos.hpp"

void ListaHijos::Crear() {
  this->pPrimeroPrincipal = nullptr;
  cantNodos = 0;
}

void ListaHijos::Destruir() {
  ContenedorPrincipal* iter = this->pPrimeroPrincipal;
  while (iter != nullptr) {
    ContenedorSublista* iter2 = iter->primerHijo;
    while (iter2 != nullptr) {
      // delete &iter2; // ?
      // iter2 = iter2->sgte;
      ContenedorSublista* temp = iter2->sgte;
      delete iter2;
      iter2 = temp;
    }
    ContenedorPrincipal* temp = iter->sgtePrincipal;
    delete iter;
    iter = temp;
  }
  cantNodos = 0;
}

void ListaHijos::PonerRaiz(std::string etiqueta) {
  this->pPrimeroPrincipal = new ContenedorPrincipal(nullptr, etiqueta, nullptr);
  this->pUltimoPrincipal = this->pPrimeroPrincipal;
  cantNodos++;
}

ListaHijos::ContenedorPrincipal* ListaHijos::AgregarHijo(ListaHijos::ContenedorPrincipal* nodoPadre, std::string etiqueta) {
  ContenedorPrincipal* iter = this->pPrimeroPrincipal;
  ContenedorPrincipal* nuevoContenedor = new ContenedorPrincipal(nullptr, etiqueta, nullptr); // puntero porque sino se borra
  // Lo agrego a la lista principal.
  ContenedorPrincipal* ultimoInicial = this->pUltimoPrincipal;
  ultimoInicial->sgtePrincipal = nuevoContenedor;
  this->pUltimoPrincipal = pUltimoPrincipal->sgtePrincipal;

  // Lo agrego en la sublista que corresponde.
  while (iter != nullptr) {
    if (iter == nodoPadre) { // DIRECCIÓN VS DIRECCIÓN
      // Si la lista esta vacia
      if (iter->primerHijo == nullptr) {
        iter->primerHijo = new ContenedorSublista(this->pUltimoPrincipal);
        iter->ultimoHijo = iter->primerHijo;
      }
      else { // La lista no está vacía y se tiene entonces un ultimoHijo válido, entonces:
        iter->ultimoHijo->sgte = new ContenedorSublista(this->pUltimoPrincipal);
        iter->ultimoHijo = iter->ultimoHijo->sgte;

      }
    }
    iter = iter->sgtePrincipal;

  }
  cantNodos++;
  // TODO: revisar el retorno aqui, este puede hacerse sobre el primer elemento aqui lo estoy agregando de ultimo, lo podria agregar de 1ero.
  return nuevoContenedor;
}

ListaHijos::ContenedorPrincipal* ListaHijos::AgregarHijoMasDerecho(ListaHijos::ContenedorPrincipal* nodoPadre, std::string etiqueta) {
  ContenedorPrincipal* iter = this->pPrimeroPrincipal;
  ContenedorPrincipal* nuevoContenedor = new ContenedorPrincipal(nullptr, etiqueta, nullptr); // puntero porque sino se borra
  ContenedorPrincipal* ultimoInicial = this->pUltimoPrincipal;
  ultimoInicial->sgtePrincipal = nuevoContenedor;
  this->pUltimoPrincipal = pUltimoPrincipal->sgtePrincipal;


  while (iter != nullptr) {
    if (iter == nodoPadre) { // DIRECCION VS DIRECCION
      // Si la lista esta vacia
      if (iter->primerHijo == nullptr) {
        iter->primerHijo = new ContenedorSublista(this->pUltimoPrincipal);
        iter->ultimoHijo = iter->primerHijo;
      }
      else { // La lista no está vacía y se tiene entonces un ultimoHijo válido, entonces:
        iter->ultimoHijo->sgte = new ContenedorSublista(this->pUltimoPrincipal);
        iter->ultimoHijo = iter->ultimoHijo->sgte;
      }
    }
    iter = iter->sgtePrincipal;

  }
  cantNodos++;
  // TODO: revisar el retorno aqui
  return nuevoContenedor;
}

void ListaHijos::BorrarHoja(ContenedorPrincipal* nodo) {
  // TODO: BorrarHoja()
  ContenedorPrincipal* iter = this->pPrimeroPrincipal;
  // Caso Inicio
  if (iter == nodo) {
    ContenedorPrincipal* temp = this->pPrimeroPrincipal;
    this->pPrimeroPrincipal = this->pPrimeroPrincipal->sgtePrincipal;
    delete temp;
  }
  /* Casos Medio y Final */
  while (iter != nullptr) {
    if (iter->sgtePrincipal == nodo) {
      ContenedorPrincipal* temp = iter->sgtePrincipal;
      iter->sgtePrincipal = iter->sgtePrincipal->sgtePrincipal;

      ContenedorSublista* iter2 = temp->primerHijo;
      while (iter2 != nullptr) { /* BORRAR LOS HIJOS DEL NODO */
        // delete &iter2; // ?
        // iter2 = iter2->sgte;
        ContenedorSublista* temp = iter2->sgte;
        delete iter2;
        iter2 = temp;
      }

      delete temp;
      break;
    } // end if
    iter = iter->sgtePrincipal;
  }
  this->cantNodos--;
}

ListaHijos::ContenedorPrincipal* ListaHijos::Raiz() {
  return this->pPrimeroPrincipal;
}

ListaHijos::ContenedorPrincipal* ListaHijos::Padre(ListaHijos::ContenedorPrincipal* nodoHijo) {
  ContenedorPrincipal* iter = this->pPrimeroPrincipal;
  while (iter != nullptr) {
    ContenedorSublista* iterHijos = iter->primerHijo;
    while (iterHijos != nullptr) {
      if (iterHijos->nodo == nodoHijo) { // Comparo direcciones?
        return iter;
      }
      iterHijos = iterHijos->sgte;
    }
    iter = iter->sgtePrincipal;
  }
  // No se encontró el padre
  return nullptr;
  // if *nodoPadre == ...
}

ListaHijos::ContenedorPrincipal* ListaHijos::HijoMasIzquierdo(ListaHijos::ContenedorPrincipal *nodo) {
  if (nodo->primerHijo != nullptr) {
    return nodo->primerHijo->nodo;
  }

  return nullptr;
}

ListaHijos::ContenedorPrincipal* ListaHijos::HermanoDerecho(ListaHijos::ContenedorPrincipal* nodo) {
  ContenedorPrincipal* iter = this->pPrimeroPrincipal;
  while (iter != nullptr) {
    ContenedorSublista* iterHijos = iter->primerHijo;
    while (iterHijos != nullptr) {
      if (iterHijos->nodo == nodo) { // Comparo direcciones?
        if (iterHijos->sgte != nullptr) {
          return iterHijos->sgte->nodo;
        }
      }
      iterHijos = iterHijos->sgte;
    }
    iter = iter->sgtePrincipal;
  }
  // No se encontró el HermanoDerecho
  return nullptr;
  // if *nodoPadre == ...
}

std::string ListaHijos::Etiqueta(ListaHijos::ContenedorPrincipal* nodo) {
  return nodo->etiqueta;
}

void ListaHijos::ModificaEtiqueta(std::string etiqueta, ListaHijos::ContenedorPrincipal *nodo) {
  nodo->etiqueta = etiqueta;
}

int ListaHijos::NumNodos() {
  return cantNodos;
}






