#define TAM_MAX_DATA 40000
#define TAM_NODO 10
#include <iostream>

using namespace std;



struct Anchura{
    int numero_hijos;
    int bandera;
    char nodo_final[TAM_NODO];
    char nodo_inicial[TAM_NODO];
    //int id[(TAM_MAX_DATA-2*TAM_NODO+2*sizeof(int))/TAM_NODO];
    int idPadre[(TAM_MAX_DATA-2*TAM_NODO+2*sizeof(int))/TAM_NODO];
    int total;
    char hijos[(TAM_MAX_DATA-2*TAM_NODO+2*sizeof(int))/TAM_NODO][TAM_NODO];
};


struct mensaje{
    int messageType; //0= Solicitud, 1 = Respuesta
    unsigned int requestId; //Identificador del mensaje
    char IP[16];
    int puerto;
    int operationId; //Identificador de la operación
    Anchura nodos;
};

Anchura *menu(mensaje *);
Anchura *busqueda(char **,int,int,char*,int*);
Anchura *busqueda(char *,char*,int);
