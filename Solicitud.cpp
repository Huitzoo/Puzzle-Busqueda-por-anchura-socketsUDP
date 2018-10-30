#include "Solicitud.h"
#include <cstring>
#include <iostream>
#include <string.h>

using namespace std;

Solicitud::Solicitud(){
    socketlocal = new SocketDatagrama(0);
}

int Solicitud::doOperation(char *IP, int puerto, int operationId, Anchura *nodes){
    mensaje peticion;
    bzero(&peticion, sizeof(peticion)); //Se limpia la estructura
    //Se copian datos a copia en mensaje
    memcpy(peticion.IP, IP, strlen(IP)+1);
    peticion.messageType = 0;
    peticion.puerto = puerto;
    peticion.operationId = operationId;
    memcpy(peticion.nodos.nodo_inicial, nodes->nodo_inicial, TAM_NODO);
    memcpy(peticion.nodos.nodo_final, nodes->nodo_final, TAM_NODO);
    peticion.nodos.numero_hijos = nodes->numero_hijos;
    peticion.nodos.total = nodes->total;
    for(int i = 0; i < nodes->total; i++){
        memcpy(peticion.nodos.hijos[i], nodes->hijos[i],10);
        //peticion.nodos.id[i] = nodes->id[i];
        peticion.nodos.idPadre[i] = nodes->idPadre[i];
    }

    socketlocal->envia(&peticion);
    return 0;
}

Anchura * Solicitud::esperaRespuesta(){
    mensaje *m  = socketlocal->recibe();
    return &(m->nodos);
}