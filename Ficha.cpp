#include "Ficha.h"
#include <iostream>
using namespace std;

Ficha::Ficha(char id, Coordenada co){
  id_numero = id;
  coordenada = co;
}

void Ficha::inicializarId(char id){
  id_numero = id;
  return;
}

void Ficha::inicializarCoord(Coordenada co){
  coordenada = co;
  return;
}

char Ficha::obtenerId(){
  return id_numero;
}

Coordenada Ficha::obtenerCoordenada(){
  return coordenada;
}