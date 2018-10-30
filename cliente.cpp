#include "Solicitud.h"
#include "Tablero.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

void atiende(Solicitud s){

}

int main(int argc, char** argv){
    Solicitud solicitud;
    int servidores = atoi(argv[1]);
    Anchura nodos[servidores], *ptr[servidores];
    for(int i = 0; i < servidores; i++){
        ptr[i] = &nodos[i];
        bzero(&nodos[i], sizeof(nodos[i])); //Se limpia la estructura
        memcpy(nodos[i].nodo_inicial, argv[2], 10);
        memcpy(nodos[i].nodo_final, argv[3], 10);    
    }
    Anchura *a = busqueda(nodos[0].nodo_inicial,nodos[0].nodo_final,7);
    int explorador = a->total-a->numero_hijos;
    int hijos = ceil(a->numero_hijos/servidores);
    int sobra = a->numero_hijos%servidores;
    /* Se reparte a los servidores */
    int aux = explorador;
    int k = 0;
    for(int i = 0; i < servidores; i++){
        nodos[i].numero_hijos = hijos;     
        nodos[i].total = explorador+hijos;
        nodos[i].bandera = 0;   
        k = 0;
        if (i==servidores-1 && sobra != 0) {
            nodos[i].numero_hijos = hijos + sobra; 
            nodos[i].total = explorador+hijos+sobra;           
        }
        for(int j = 0; j<explorador; j++){
            memcpy(nodos[i].hijos[j], a->hijos[j],10);
            nodos[i].idPadre[j] = a->idPadre[j];
            k++;
        }
        for(int j = aux; j<aux+nodos[i].numero_hijos; j++){
            memcpy(nodos[i].hijos[k], a->hijos[j],10);
            nodos[i].idPadre[k] = a->idPadre[j];
            k++;
        }
        aux = aux + nodos[i].numero_hijos;
    }  
    //cout << nodos.hijos[0] << endl;
    //explorados = (char**)realloc(explorados,(i+1)*10);
    //rose21042016
    Anchura *r[servidores];
    for(int i = 0; i < servidores; i++){
        solicitud.doOperation(argv[6+i], atoi(argv[4]), atoi(argv[5]), ptr[i]);
    }
    for(size_t i = 0; i < servidores; i++){
        r[i] = solicitud.esperaRespuesta();
        if(r[i]->bandera == 1){
            for(int j = 0; j < r[i]->total; j++){
                cout  <<  r[i]->hijos[j]  <<endl;
            }
            
       }
    }
    return 0;
}