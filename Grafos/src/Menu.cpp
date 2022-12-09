#include "../include/Menu.hpp"
#include "../include/Algoritmos.hpp"
#include <iostream>

using namespace Algoritmos;
using namespace std;


Menu::Menu(){
  this->grafo=new Grafo();
}
Menu::~Menu(){
  if (this->grafo){
    delete this->grafo;
  }
}
void Menu::Run(){
cout<<"\nBienvenid@ al programa de pruebas! \n"<<endl;

bool loopPrincipal = true;

while(loopPrincipal){
  cout<<"Por favor, seleccione una opcion: 1-Operadores 2-Algoritmos \n"<<endl;
  int opcionPrincipal;
  cin>> opcionPrincipal;
  switch (opcionPrincipal)
  {
  case 1:
    this->menuOperadores();
    break;
  case 2:
    this->menuAlgoritmos();
    break;
  default:
    loopPrincipal=false;
    break;
  }
}


}
void Menu::menuOperadores(){
  cout<<"\n MENU DE OPERADORES \n"<<endl;

  bool loopOperadores = true;

  while(loopOperadores){
    string opciones="\nPor favor, seleccione una opcion:\n" 
    "1-Crear 2-Destruir 3-Agregar Vertice 4-EliminarVertice 5-ModificarEtiqueta\n" 
    "6-Etiqueta 7-AgregarArista 8-EliminarArista 9-ModificarPeso 10-Peso\n"
    "11-PrimerVertice 12-SiguienteVertice 13-PrimerVerticeAdjacente 14-SiguienteVerticeAdjacente\n"
    "15-NumVertices OTRO-SALIR \n";
    int opcionOperadores;
    cout<<opciones<<endl;
    cin>>opcionOperadores;
  
    switch (opcionOperadores)
    {
    case 1:
      {
      cout<<"opcion 1 elegida"<<endl;
      break;
      }
    case 2:
      {
      // cout<<"ahhh si -dijo carlos"<<endl;
      cout << "opcion 2 elegida" << endl;
      break;
      }
    case 3:
      {
      cout<<"Ingrese la etiqueta del vertice que desea agregar: "<<endl;
      string etiqueta;
      cin>> etiqueta;
      Vertice* v=this->grafo->agregarVertice(etiqueta);
      this->idVertice.insert({etiqueta,v});
      cout<<"Se agrego el vertice"<<endl;
      break;
      }
    case 4:
      {
      cout<<"Ingrese la etiqueta del vertice que desea eliminar: "<<endl;
      string etiqueta;
      cin>> etiqueta;
      this->grafo->eliminarVertice(etiqueta);
      cout<<"Se elimino el vertice"<<endl;
      break;
      }
    case 5:
      {
      cout<<"Ingrese la etiqueta del vertice que desea modificar: "<<endl;
      string etiquetaVertice;
      cin>> etiquetaVertice;
      cout<<"Ingrese la nueva etiqueta: "<<endl;
      string etiquetaNueva;
      cin>> etiquetaNueva;
      this->grafo->modificarEtiqueta(this->idVertice[etiquetaVertice], etiquetaNueva);
      break;
      }
    case 6:
      {
        cout<<"opcion 6 elegida"<<endl;
      break;
      }
    case 7:
      {
        cout<<"Ingrese la etiqueta del vertice1"<<endl;
        string etiqueta1;
        cin>> etiqueta1;
        cout<<"Ingrese la etiqueta del vertice2: "<<endl;
        string etiqueta2;
        cin>> etiqueta2;
        cout<<"Ingrese el peso de la arita que desea agregar: "<<endl;
        int peso;
        cin>> peso;
        this->grafo->agregarArista(this->idVertice[etiqueta1],this->idVertice[etiqueta2],peso);
      break;
      }
    case 8:
      {
        cout<<"Ingrese la etiqueta del vertice1"<<endl;
        string etiqueta1;
        cin>> etiqueta1;
        cout<<"Ingrese la etiqueta del vertice2: "<<endl;
        string etiqueta2;
        cin>> etiqueta2;
        this->grafo->eliminarArista(this->idVertice[etiqueta1],this->idVertice[etiqueta2]);
      break;
      }
    case 9:
      {
        cout<<"Ingrese la etiqueta del vertice1"<<endl;
        string etiqueta1;
        cin>> etiqueta1;
        cout<<"Ingrese la etiqueta del vertice2: "<<endl;
        string etiqueta2;
        cin>> etiqueta2;
        cout<<"Ingrese el peso de la arita que desea modificar: "<<endl;
        int peso;
        cin>> peso;
        this->grafo->modificarArista(this->idVertice[etiqueta1],this->idVertice[etiqueta2],peso);
      break;
      }
    case 10:
      {
        cout<<"Ingrese la etiqueta del vertice1"<<endl;
        string etiqueta1;
        cin>> etiqueta1;
        cout<<"Ingrese la etiqueta del vertice2: "<<endl;
        string etiqueta2;
        cin>> etiqueta2;
        cout<<"El peso es: "<<this->grafo->peso(this->idVertice[etiqueta1],this->idVertice[etiqueta2])<<endl;
      break;
      }
    case 11:
      {
        this->menuPrimerVertice();
      break;
      }
    case 12:
      {
      cout<<"Ingrese la etiqueta del vertice del que desea conocer el siguiente vertice: "<<endl;
      string etiqueta;
      cin>> etiqueta;
      this->menuSiguienteVertice(etiqueta);
      break;
      }
    case 13:
      {
      cout<<"Ingrese la etiqueta del vertice del que desea conocer el primer vertice adjacente: "<<endl;
      string etiqueta;
      cin>> etiqueta;
      this->menuPrimerVerticeAdyacente(etiqueta);
      break;
      }
    case 14:
      {
        cout<<"Ingrese la etiqueta del vertice1"<<endl;
        string etiqueta1;
        cin>> etiqueta1;
        cout<<"Ingrese la etiqueta del vertice2: "<<endl;
        string etiqueta2;
        cin>> etiqueta2;
        this->menuSiguienteVerticeAdyacente(etiqueta1,etiqueta2);
      break;
      }
    case 15:
      {    
        this->menuNumVertices();
      break;
      }
    default:
      {
      loopOperadores=false;
      break;
      }
    }
  }
}

void Menu::menuAlgoritmos() {
  cout<<"\nMENU DE ALGORITMOS\n"<<endl;

  bool loopAlgoritmos = true;

  while(loopAlgoritmos){
    string opciones="Por favor, seleccione una opcion:\n" 
    "1-Dijkstra 2-Floyd 3-N Veces Dijkstra 4-Prim \n5-Kruskal 6-Circuito Hamilton\n"
    "7-Coloreo 8-HamiltonBERA OTRO-SALIR \n";
    int opcionAlgoritmos;
    cout<<opciones<<endl;
    cin>>opcionAlgoritmos;
  
    switch (opcionAlgoritmos)
    {
    case 1: {
      cout << "Ingrese la etiqueta del vertice inicial de Dijkstra" << endl;
      std::string etiqInicial;
      cin >> etiqInicial;
      menuDijkstra(etiqInicial);
      }break;
    case 2: {
      menuFloyd();
      }break;
    case 3: {
      menuNDijkstra();
      }break;
    case 4: {
      menuPrim();
      }break;
    case 5: {
      menuKruskal();
      }break;
    case 6: {
      menuHamilton();
      }break;
    case 7: {
      menuColoreo();
      }break;
    case 8: {
      menuHamiltonBERA();
      }break;
    default: {
      loopAlgoritmos=false;
      }break;
    }
  }
}
void Menu::menuCrear(){

}
void Menu::menuDestruir(){

}
void Menu::menuAgregarVertice(std::string etiqueta){
  this->grafo->agregarVertice(etiqueta);
}
void Menu::menuEliminarVertice(std::string etiqueta){
  this->grafo->eliminarVertice(etiqueta);
}
void Menu::menuEtiqueta(int vertice){
  
}
void Menu::menuAgregarArista(std::string etV1, std::string etV2, int peso){
  Vertice* v1 = idVertice[etV1];
  Vertice* v2 = idVertice[etV2];
  this->grafo->agregarArista(v1, v2, peso);
}
void Menu::menuEliminarArista(std::string etV1, std::string etV2){
  Vertice* v1 = idVertice[etV1];
  Vertice* v2 = idVertice[etV2];
  this->grafo->eliminarArista(v1, v2);
}
void Menu::menuModificarPeso(std::string etV1, std::string etV2, int peso){
  Vertice* v1 = idVertice[etV1];
  Vertice* v2 = idVertice[etV2];
  this->grafo->modificarArista(v1, v2, peso);
}
void Menu::menuPeso(std::string etV1, std::string etV2){
  Vertice* v1 = idVertice[etV1];
  Vertice* v2 = idVertice[etV2];
  std::cout << this->grafo->peso(v1, v2) << std::endl;
}
void Menu::menuPrimerVertice(){
  std::cout << this->grafo->etiqueta(this->grafo->primerVertice()) << std::endl;
}
void Menu::menuSiguienteVertice(std::string etV){
  Vertice* v1 = idVertice[etV];
  std::cout << this->grafo->etiqueta(this->grafo->siguienteVertice(v1))
    << std::endl;
}
void Menu::menuPrimerVerticeAdyacente(std::string etiqueta) {
  Vertice* v1 = idVertice[etiqueta];
  std::cout << this->grafo->etiqueta(this->grafo->primerVerticeAdyacente(v1))
    << std::endl;
}
void Menu::menuSiguienteVerticeAdyacente(std::string etV1, std::string etV2){
  Vertice* v1 = idVertice[etV1];
  Vertice* v2 = idVertice[etV2];
  std::cout << this->grafo->etiqueta(this->grafo->siguienteVerticeAdyacente(v1,
    v2)) << std::endl;
}
void Menu::menuNumVertices() {
  std::cout << this->grafo->numVertices() << std::endl;
}
void Menu::menuDijkstra(std::string etInicial){
  // MENSAJE INICIAL:
  cout << "Ejecutando Dijkstra" << endl;
  // DIJKSTRA
  Vertice* v1 = idVertice[etInicial];
  ListaIndexada<ContenedorDijkstra>* lista=new ListaIndexada<ContenedorDijkstra>;

	Dijkstra(this->grafo, v1, lista);
  cout << "Resultado de recorrido Dijkstra: " << endl;
  ContenedorDijkstra vert;
  for (int i = 1; i <= lista->numElem(); i++)  {
    vert = lista->recuperar(i);
    cout << this->grafo->etiqueta(vert.vertice)<<": "<<vert.pesoAcumulado <<endl;
  }
  cout << endl;
  delete lista;
  
}
void Menu::menuFloyd(){
  // IMPRESION MENSAJE
  cout << "Ejecutando Floyd..." << endl;
  // FLOYD
  Relacion1A1* relacion1a1G1=new Relacion1A1;
	int ** matrizPesosG1=new int *[this->grafo->numVertices()];
	Vertice *** matrizVerticesG1=new Vertice **[this->grafo->numVertices()];
	Floyd(this->grafo, matrizPesosG1, matrizVerticesG1, relacion1a1G1);
  cout<<endl;
  for(int i =0;i<grafo->numVertices();++i){
    for(int j=0;j<grafo->numVertices();++j){
      if (matrizPesosG1[i][j]==99999){
        cout<<0<<" ";				
      }else{
        cout<<matrizPesosG1[i][j]<<" ";
      }
    }
    cout<<endl;
  }
  delete relacion1a1G1;
  for(int i = 0; i < this->grafo->numVertices(); ++i){
		delete[] matrizPesosG1[i];
	 	delete[] matrizVerticesG1[i];
	}
	delete[] matrizPesosG1;
	delete[] matrizVerticesG1;
}
void Menu::menuNDijkstra(){
  // IMPRESION MENSAJE
  cout << "Ejecutando Dijkstra..." << endl;
  // DIJKSTRA
  ListaIndexada<ContenedorDijkstra>* listaG1=new 
    ListaIndexada<ContenedorDijkstra>[this->grafo->numVertices()];
  NDijkstra(this->grafo, listaG1);
  ContenedorDijkstra vert;
  for (int i =0; i < this->grafo->numVertices(); i++) {
    cout << endl << "Ejecucion #" << i << endl;
    for (int m = 1; m<=listaG1[i].numElem(); m++) {
      vert = listaG1[i].recuperar(m);
      cout << this->grafo->etiqueta(vert.vertice)<<": "<<vert.pesoAcumulado <<endl;
    }
  }
  cout << endl;
  delete[] listaG1;
}
void Menu::menuPrim(){
  // IMPRESION MENSAJE
  cout << "Ejecutando Prim..." << endl;
  // PRIM
  Prim(this->grafo);
  
}
void Menu::menuKruskal(){
  // IMPRESION MENSAJE
  cout << "Ejecutando Kruskal..." << endl;
  // KRUSKAL
  Kruskal(this->grafo);
}
void Menu::menuHamilton(){
  // IMPRESION MENSAJE
  cout << "Ejecutando Hamilton..." << endl;
  int pesoRecorrido = Hamilton(this->grafo);
  cout << "El peso resultante del recorrido de Hamilton es: " << pesoRecorrido
    << endl;
}
void Menu::menuColoreo(){
  // IMPRESION MENSAJE
  cout << "Ejecutando Coloreo..." << endl;
  int cantColores = Coloreo(this->grafo);
  cout << "La cantidad de colores utilizados por Coloreo es: " << cantColores
    << endl;
}
void Menu::menuHamiltonBERA(){
  // IMPRESION MENSAJE
  cout << "Ejecutando HamiltonBERA..." << endl;
  int pesoRecorrido = HamiltonBERA(this->grafo);
  cout << "El peso resultante del recorrido de Hamilton mediante Ramificacion y"
    " Acotamiento es: " << pesoRecorrido << endl; 

}
