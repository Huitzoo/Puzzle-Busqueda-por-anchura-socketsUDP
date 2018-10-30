#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_
#include <netinet/in.h>//Familia AF_INET
#include "funciones.h"

class SocketDatagrama{
  private:
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    int s; //ID socket
  
  public:
    SocketDatagrama(int);
    ~SocketDatagrama();
    //Recibe un paquete tipo datagrama proveniente de este socket
    struct mensaje* recibe();
    //Envía un paquete tipo datagrama desde este socket
    int envia(mensaje*);
};

#endif
