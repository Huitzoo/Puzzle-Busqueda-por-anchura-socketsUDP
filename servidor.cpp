#include "Respuesta.h"
#include <iostream>
#include <cstring>
#include <string>
#include "Tablero.h"

using namespace std;

int main(int argc, char** argv){
  int pto = atoi(argv[1]);
  Respuesta r(pto);
  mensaje *m = r.getRequest();
  Anchura *a = new Anchura;
  a = menu(m);
  for(int i = 0; i < a->total; i++){
    memcpy(m->nodos.hijos[i],a->hijos[i], 10);
  }
  m->nodos.total = a->total;
  m->nodos.bandera = a->bandera;
  r.sendReply(&(m->nodos),m->IP, m->puerto);
}
