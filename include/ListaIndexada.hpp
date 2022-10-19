#ifndef LISTAINDEXADAHPP
#define LISTAINDEXADAHPP

class ListaIndexada
{

class Nodo
{
    friend class ListaIndexada;
    private:
    int dato;
    Nodo* siguiente;
    public:
    Nodo(int dato);
    ~Nodo();
};

private:

    Nodo* primero;
    Nodo* ultimo;
    int contador;
public:
    ListaIndexada();
    ~ListaIndexada();
    void insertar(int dato,int posicion);
    void borrar(int posicion);
    int recuperar(int posicion);
    void modificar(int dato,int posicion);
    int numElem();
    void imprimir();
};
#endif