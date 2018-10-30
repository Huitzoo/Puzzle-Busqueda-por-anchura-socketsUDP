#include "Tablero.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <strings.h>

using namespace std;

int Tablero::idGeneral = 0;


Tablero::Tablero(){

}
Tablero::Tablero(string tab){
  int aux = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      v.push_back(Ficha(tab[aux],Coordenada(i,j)));
      if(tab[aux] == '0'){
        vacia = Coordenada(i,j);
        posicion_v = aux;
      }
      aux ++;
    }
  }
  id = idGeneral;
  idPadre = idGeneral;
  idGeneral ++;
}
Tablero::Tablero(string tab, int ids){
  int aux = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      v.push_back(Ficha(tab[aux],Coordenada(i,j)));
      if(tab[aux] == '0'){
        vacia = Coordenada(i,j);
        posicion_v = aux;
      }
      aux ++;
    }
  }
  id = idGeneral;
  idPadre = ids;
  idGeneral ++;
}

Tablero::~Tablero(){
  //delete[] v;
}

char *Tablero::fichasToString(){
  char *fichas = new char[10];
  string ficha;
  int suma = 3;
  for(int i = 0; i < 9; i++){
    ficha = ficha+v[i].obtenerId();
  }
  strncpy(fichas, ficha.c_str(), 9);
  fichas[9] = 0;
  return fichas;
}

int Tablero::determinarMovimientos(){
  if(vacia.obtenerX()==1){ // esta en la fila 1
    if (vacia.obtenerY()==1) {
      return 4;
    }else{
      return 3;
    }
  }else{ //esta en la fila 0 o en 2
    if (vacia.obtenerY()==1) {
      return 3;
    }else{
      return 2;
    }
  }
}
int Tablero::getPadre(){
  return idPadre;
}

int Tablero::getId(){
  return id;
}

vector<Tablero> Tablero::moverFichas(int movimientos,char** explorados,int numero_explorados){
  int resta = 0;
  int x_vacio = vacia.obtenerX();
  int y_vacio = vacia.obtenerY();
  int bandera = 0;
  vector<Tablero> tablero_hijos;
  char aux;
  Tablero t;
  for(int j = 0; j < movimientos; j++){
    t = *this;
    for(int i = bandera; i < 9; i++){
      if(i != posicion_v){  
        Coordenada c = t.v[i].obtenerCoordenada();
        if(c.obtenerX() == x_vacio || c.obtenerY() == y_vacio){
          if(abs(c.obtenerY()-y_vacio) == 1 || abs(c.obtenerX()-x_vacio) == 1){
            aux = t.v[i].obtenerId();
            t.v[i].inicializarId(v[posicion_v].obtenerId());
            t.v[posicion_v].inicializarId(aux);
            t.vacia = c;
            t.posicion_v = i;
            t.idPadre = this->id;
            t.id = idGeneral;
            idGeneral +=1;
            bandera = i+1;
            int es_igual = 1;
            if(explorados!= NULL){
              for(int k = 0; k < numero_explorados; k++){
                if(strcmp(explorados[k],t.fichasToString())!=0){
                  es_igual = 0;    
                }else{
                  es_igual = 1;
                  break;  
                }
              }
              if(es_igual == 0) {
                tablero_hijos.push_back(t);
              }
            }else{
              tablero_hijos.push_back(t); 
            }
            break;
          }
        }
      }
    }
  }
  return tablero_hijos;
}
