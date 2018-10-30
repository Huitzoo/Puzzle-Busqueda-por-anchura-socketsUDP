#include "Respuesta.h"
#include <cstring>
#include <iostream>

using namespace std;

Respuesta::Respuesta(int pl){
    socketlocal = new SocketDatagrama(pl);
}

struct mensaje *Respuesta::getRequest(){
    mensaje *peticion;
    peticion = socketlocal->recibe();
    return peticion;
}

void Respuesta::sendReply(Anchura * nodes, char*ipCliente, int puertoCliente){
    mensaje respuesta;
    bzero(&respuesta, sizeof(respuesta));
    memcpy(respuesta.IP, ipCliente, strlen(ipCliente)+1);
    respuesta.messageType = 1;
    respuesta.puerto = puertoCliente;
    memcpy(respuesta.nodos.nodo_inicial, nodes->nodo_inicial, TAM_NODO);
    memcpy(respuesta.nodos.nodo_final, nodes->nodo_final, TAM_NODO);
    respuesta.nodos.numero_hijos = nodes->numero_hijos;
    respuesta.nodos.bandera = nodes->bandera;
    respuesta.nodos.total = nodes->total;
    for(int i = 0; i < nodes->total; i++){
        memcpy(respuesta.nodos.hijos[i], nodes->hijos[i],TAM_NODO);
    }
    socketlocal->envia(&respuesta);
}
