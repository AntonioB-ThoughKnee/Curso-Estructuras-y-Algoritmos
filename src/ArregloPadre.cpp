//
// Created by Jean C on 10/19/2022.
//

#include "../include/ArregloPadre.hpp"
//
// Created by jean on 14/10/22.
//

//template<typename TipoNodo>
void ArregloPadre::Crear() {

}

//template<typename TipoNodo>
void ArregloPadre::Destruir() {

}

//template <typename TipoNodo>
void ArregloPadre::PonerRaiz(int etiqueta) {
    auto it = this->arreglo.begin();

    this->arreglo.emplace(it, ArregloPadre::contenedorArreglo(etiqueta, -1, 0)); // -1 porque no tiene papá.
}

//template <typename TipoNodo>
int ArregloPadre::AgregarHijo(int nodoPadre,int etiqueta) {
    auto it = this->arreglo.end();
    int nuevo_nodo_id = this->arreglo.size();
    this->arreglo.emplace(it, ArregloPadre::contenedorArreglo(etiqueta, nodoPadre-1, nuevo_nodo_id)); // nodo_id empieza en 1
    return nuevo_nodo_id+1; // Para el "outside-world" el arreglo empieza en 1, entonces tengo que sumarle 1.
}

int ArregloPadre::AgregarHijoMasDerecho(int nodoPadre, int etiqueta) {
    auto it = this->arreglo.end();
    int nuevo_nodo_id = this->arreglo.size();
    this->arreglo.emplace(it, ArregloPadre::contenedorArreglo(etiqueta, nodoPadre-1, nuevo_nodo_id));
    return nuevo_nodo_id+1; // Para el "outside-world" el arreglo empieza en 1, entonces tengo que sumarle 1.

}

//void ArregloPadre::BorrarHoja(std::string etiqueta) {
//  for (int i = 0 ; i < this->arreglo.size(); i++) {
//    if (this->arreglo[i].etiqueta == etiqueta) {
//      this->arreglo.erase(this->arreglo.begin()+i);
//    }
//  }
//}
void ArregloPadre::BorrarHoja(int nodo_id_externo) {
    this->arreglo.erase(this->arreglo.begin()+(nodo_id_externo-1));
}



int ArregloPadre::Raiz() {
    if (!this->arreglo.empty()) {
        return (this->arreglo[0].nodo_id)+1;
    }
    return -1; // Arbol esta vacio.
}

int ArregloPadre::Padre(int nodo_id_externo) {
    return (this->arreglo[nodo_id_externo-1].padre)+1;
}

int ArregloPadre::HijoMasIzquierdo(int nodo_id_externo_papa) {
    // Necesito recorrer todo el arreglo e ir guardando el nodo_id cada vez que encuentre un nodo que tenga el papa que fue
    // pasado por parametro. De esta manera el nodo_id restante es el nodo_id del hijo mas izquierdo.
    int toRet = -1; // Nodo_id del hijo mas izquierdo, este valor va a ser devuelto.
    for (int i = 0; i < this->arreglo.size(); ++i) {
        // Técnicamente sería mas eficiente empezar i en el valor pasado por el parametro porque el hijo siempre tiene que estar
        // a la derecha del papá pero mejor por términos de efectividad lo voy a dejar asi.
        if (this->arreglo[i].padre == (nodo_id_externo_papa-1)) { // los nodos por debajo en mi programa empiezan en 0, por eso el -1
            return (this->arreglo[i].nodo_id)+1;
        }
    }
    return toRet;
}

int ArregloPadre::HermanoDerecho(int nodo_id_hermano_externo) {
    int papaComun = this->arreglo[nodo_id_hermano_externo-1].padre; // nodo por dentro es 1 valor menos por el arreglo.
    // Empieza en nodo_id_hermano porque de esta manera, si a la derecha del arreglo a partir de el encontramos a otro nodo con el mismo
    // papa entonces es el hermano derecho.
    for (int i = nodo_id_hermano_externo; i < this->arreglo.size(); ++i) { // Le deberia hacer -1, pero ocupo que empiece a buscar 1 pos mayor, porque sino se encuentra a si mismo.
        if (this->arreglo[i].padre == papaComun) { // como es inmediatamente el siguiente encontrado a la derecha del arreglo, es el herm. der
            return (this->arreglo[i].nodo_id)+1;
        }
    }
    return -1;
}

int ArregloPadre::Etiqueta(int nodo_id_externo) {
    return this->arreglo[nodo_id_externo-1].etiqueta;
}

void ArregloPadre::ModificaEtiqueta(int etiqueta, int nodo_id_externo) {
    this->arreglo[nodo_id_externo-1].etiqueta = etiqueta;
}

int ArregloPadre::NumNodos() {
    return this->arreglo.size();
}


