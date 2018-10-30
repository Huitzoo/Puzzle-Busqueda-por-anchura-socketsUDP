#include <iostream>
#include "Coordenada.h"

Coordenada::Coordenada(int xx, int yy) : x(xx), y(yy){ 

}

int Coordenada::obtenerX(){
  return x;
}

int Coordenada::obtenerY(){
  return y;
}

void Coordenada::inicializarX(int xx){
  x = xx;
  return;
}

void Coordenada::inicializarY(int yy){
  y = yy;
  return;
}
