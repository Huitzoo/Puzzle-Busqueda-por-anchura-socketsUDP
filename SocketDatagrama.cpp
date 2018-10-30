#include "SocketDatagrama.h"
#include <sys/types.h> //socket
#include <sys/socket.h> //socket
#include <strings.h>//bzero
#include <arpa/inet.h>//htons
#include <cstring>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;


//Crea un socket tipo datagrama y su parámetro es el puerto local
SocketDatagrama::SocketDatagrama(int pto){
  s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //Crea el socket UDP de datagrama
  bzero((char *)&direccionLocal, sizeof(direccionLocal));
  direccionLocal.sin_family = AF_INET;
  direccionLocal.sin_port = htons(pto);
  direccionLocal.sin_addr.s_addr = INADDR_ANY;

  bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal)); //Se enlaza a la dirección local
}

SocketDatagrama::~SocketDatagrama(){
  close(s);
}

struct mensaje* SocketDatagrama::recibe(){
  mensaje * m = new mensaje;
  unsigned int addr_len = sizeof(direccionForanea);
  int recibido = recvfrom(s, m, sizeof(mensaje), 0, (struct sockaddr *)&direccionForanea, &addr_len);
  memcpy(m->IP, inet_ntoa(direccionForanea.sin_addr), strlen(inet_ntoa(direccionForanea.sin_addr))+1);
  cout << "Respuesta de: " << m->IP << endl;
  m->puerto = ntohs(direccionForanea.sin_port);
  return m;
}

//Envía un paquete tipo datagrama desde este socket
int SocketDatagrama::envia(mensaje*m){
  direccionForanea.sin_family = AF_INET;
  direccionForanea.sin_addr.s_addr = inet_addr(m->IP);
  direccionForanea.sin_port = htons(m->puerto);
  int enviado = sendto(s, m, sizeof(*m), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
  return enviado;
}
