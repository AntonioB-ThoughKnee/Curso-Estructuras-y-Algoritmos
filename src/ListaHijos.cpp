#include "../include/ListaHijos.hpp"
//
// Created by jean on 17/10/22.
//


void ListaHijos::Crear() {
    this->pPrimeroPrincipal = nullptr;
    cantNodos = 0;
}

void ListaHijos::Destruir() {
    ContenedorPrincipal* iter = this->pPrimeroPrincipal;
    while (iter != nullptr) {
        ContenedorSublista* iter2 = iter->primerHijo;
        while (iter2 != nullptr) {
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

void ListaHijos::PonerRaiz(int etiqueta) {
    this->pPrimeroPrincipal = new ContenedorPrincipal(nullptr, etiqueta, nullptr);
    this->pUltimoPrincipal = this->pPrimeroPrincipal;
    cantNodos++;
}

ListaHijos::ContenedorPrincipal* ListaHijos::AgregarHijo(ListaHijos::ContenedorPrincipal* nodoPadre, int etiqueta) {
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

ListaHijos::ContenedorPrincipal* ListaHijos::AgregarHijoMasDerecho(ListaHijos::ContenedorPrincipal* nodoPadre, int etiqueta) {
    ContenedorPrincipal* iter = this->pPrimeroPrincipal;
    ContenedorPrincipal* nuevoContenedor = new ContenedorPrincipal(nullptr, etiqueta, nullptr); // puntero porque sino se borra
    ContenedorPrincipal* ultimoInicial = this->pUltimoPrincipal;
    this->pUltimoPrincipal->sgtePrincipal = nuevoContenedor;
    this->pUltimoPrincipal = this->pUltimoPrincipal->sgtePrincipal;


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
//    this->pUltimoPrincipal
    cantNodos++;
    // TODO: revisar el retorno aqui
    return nuevoContenedor;
}

void ListaHijos::BorrarHoja(ContenedorPrincipal* nodo) {
    // TODO: No tengo que borrar los hijos, pero antes de borrar a la hoja que quiero
    // tengo que recorrer todos los hijos de todos nos nodos para borrarlo como hijo
    // de otros nodos.
    ContenedorPrincipal* iter = this->pPrimeroPrincipal;
  // Caso Inicio Principal
  if (iter == nodo) {
    ContenedorPrincipal* temp = this->pPrimeroPrincipal;
    this->pPrimeroPrincipal = this->pPrimeroPrincipal->sgtePrincipal;
    // No lo tengo que buscar como hijo de otros nodos.
    delete temp;
    temp = nullptr;
    
  } else {
    /* Casos Medio y Final */
    while (iter != nullptr) {
        bool borrado = false;

        ContenedorSublista* iterHijos = iter->primerHijo;
        // podria comparar con etiquetas.
        /* CASOS INICIALES DE BORRADO (BORRADO DEL PRIMER ELEMENTO) */
        if (iterHijos != nullptr) {
            if (iterHijos->nodo == nodo) {
            ContenedorSublista* tempPrimerHijo = iter->primerHijo;
            iter->primerHijo = iter->primerHijo->sgte;
            
            iterHijos = tempPrimerHijo->sgte; 
            borrado = true;
            delete tempPrimerHijo;
            tempPrimerHijo = nullptr;
            // tecnicamente solo lo puede tener como hijo 1 vez.
            break;

            }
        }

        // Ocupo otra vez comparar con el siguiente porque no tengo como devolverme.
        // Necesito borrarlo como hijo de otros nodos.
        while (iterHijos != nullptr && !borrado) { // Buscar dentro de los hijos de todos los nodos.
          // TODO: Preguntar si es el primer caso porque si lo es tengo que 
          // cambiar el punter al primerHijo

           
            /* CASOS MEDIOS-FINALES DE BORRADO*/
            if (iterHijos->sgte != nullptr) {
              if (iterHijos->sgte->nodo == nodo) { // si el siguiente es el que ocupo borrar
                ContenedorSublista* temp = iterHijos->sgte; // el que ocupo borrar.
                iterHijos->sgte = temp->sgte; // le digo que el siguiente va a moverse 1 campo.
                
                // iterHijos = iterHijos->sgte; // no importa por el break?
                borrado = true;
                
                delete temp;
                temp = nullptr;


                // tecnicamente solo lo puede tener como hijo 1 vez.
                break;
              }
            }
            iterHijos = iterHijos->sgte;
        } // end else
        


        // Si el siguiente principal es el que tengo que borrar. 
        if (iter->sgtePrincipal == nodo) {
        ContenedorPrincipal* temp = iter->sgtePrincipal;
        iter->sgtePrincipal = iter->sgtePrincipal->sgtePrincipal;

        

        delete temp;
        temp = nullptr;
        
        break;
        } // end if
        iter = iter->sgtePrincipal;
    }
  this->cantNodos--;

  }
}


void ListaHijos::borrarComoHijo(ContenedorPrincipal* nodo) {

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

ListaHijos::ContenedorPrincipal* ListaHijos::HijoMasIzquierdo(ListaHijos::ContenedorPrincipal* nodo) {
    if (nodo->primerHijo != nullptr) {
        return nodo->primerHijo->nodo;
    }

    return nullptr;
}

ListaHijos::ContenedorPrincipal* ListaHijos::HermanoDerecho(ListaHijos::ContenedorPrincipal* nodo) {
    ContenedorPrincipal* iter = this->pPrimeroPrincipal;
    while (iter != nullptr) {
        ContenedorSublista* iter2 = iter->primerHijo;
        while (iter2 != nullptr){
            if (iter2->nodo == nodo) { // Comparo direcciones?
                if (iter2->sgte != nullptr) {
                    return iter2->sgte->nodo;
                }
            }
            if (iter2->sgte != nullptr) {
                iter2 = iter2->sgte;
            }
            else {
                iter2 = nullptr;
            }
        }
        iter = iter->sgtePrincipal;
    }
    // No se encontró el HermanoDerecho
    return nullptr;
    // if *nodoPadre == ...
}

int ListaHijos::Etiqueta(ListaHijos::ContenedorPrincipal* nodo) {
    if (nodo) {
        return nodo->etiqueta;
    }
    return -1;
}

void ListaHijos::ModificarEtiqueta(ContenedorPrincipal* nodo, int etiqueta) {
    nodo->etiqueta = etiqueta;
}

int ListaHijos::NumNodos() {
    return cantNodos;
}






