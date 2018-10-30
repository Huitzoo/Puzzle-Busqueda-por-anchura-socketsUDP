#ifndef SOLICITUD_H_
#define SOLICITUD_H_

#include "SocketDatagrama.h"

//#include "mensaje.h"

class Solicitud{
    private:
        SocketDatagrama *socketlocal;
    public:
        Solicitud();
        int doOperation(char *IP, int puerto, int operationId, Anchura *nodes);
        Anchura *esperaRespuesta();
};

#endif