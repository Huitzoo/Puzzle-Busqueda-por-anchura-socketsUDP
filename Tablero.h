#ifndef TABLERO_H_
#define TABLERO_H_

#include <vector>
#include "Ficha.h"
#include <string>

using namespace std;

class Tablero{
  static int idGeneral;
  
  private:
    vector<Ficha> v;
    Coordenada vacia;
    int posicion_v;
    int id;
    int idPadre;

  public:
    Tablero(string);
    Tablero(string,int);
    Tablero();
    ~Tablero();
    int determinarMovimientos();
    vector<Tablero> moverFichas(int,char**,int);
    char *fichasToString();
    int getPadre();
    int getId();
};

#endif
