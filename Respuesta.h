#include "SocketDatagrama.h"


class Respuesta{

    public:
        Respuesta(int);
        struct mensaje *getRequest(void);
        void sendReply(Anchura * nodes, char *ipCliente, int puertoCliente);

    private:
        SocketDatagrama *socketlocal;
};
