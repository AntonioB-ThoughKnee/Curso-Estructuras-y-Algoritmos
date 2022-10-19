#ifndef COLAHPP
#define COLAHPP
class Cola{

private:
int inicio;
int final;
int capacidad;
int* cola;
int contador;

public:
Cola();
~Cola();
void Encolar(int elemento);
int Desencolar();
int numElem();
};
#endif