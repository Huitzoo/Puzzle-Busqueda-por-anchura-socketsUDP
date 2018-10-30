#ifndef FICHA_H_
#define FICHA_H_
#include "Coordenada.h"

class Ficha{
  private:
    char id_numero;
    Coordenada coordenada;
    
  public:
    Ficha(char, Coordenada);
    Ficha();
    void inicializarId(char);
    void inicializarCoord(Coordenada);
    char obtenerId();
    Coordenada obtenerCoordenada();
    //Coordenada obtenerCoordenada();
};

#endif
