#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada{
  private:
    int x;
    int y;
  public:
    Coordenada(int = 0, int = 0);
    int obtenerX();
    int obtenerY();
    void inicializarX(int);
    void inicializarY(int);
};

#endif
