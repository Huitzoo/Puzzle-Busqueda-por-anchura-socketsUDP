#include "Tablero.h"
#include "funciones.h"
#include <string.h>
#include <iostream>

using namespace std;


Anchura *menu(mensaje *m){
    if(m->operationId==1){
        Anchura *resultado = NULL;
        int* id = NULL;
        char **explorar = NULL;
        for(size_t i = 0; i < m->nodos.total; i++){
            explorar = (char**)realloc(explorar,(i+1)*10);
            explorar[i] = (char*)malloc(10);
            id = (int*)realloc(id,(i+1)*sizeof(int));
            id[i] = m->nodos.idPadre[i];
            memcpy(explorar[i], m->nodos.hijos[i],10);
        }   
        resultado = busqueda(explorar,m->nodos.numero_hijos,m->nodos.total,m->nodos.nodo_final,id);
        return resultado;
    }
}

Anchura *busqueda(char **explorar,int numero_hijos,int total,char *meta, int *id){
    char **explorados = NULL;
    char **envia = NULL;
    vector<Tablero> hijos;
    vector<Tablero> t;
    vector<Tablero> todos;
    Anchura *a = new Anchura;
    int i = 0;
    int movimientos = 0;
    int x = 0;
    int y = total-numero_hijos;
    for(int i = 0; i < y; i++){
        explorados = (char**)realloc(explorados,(i+1)*10);
        explorados[i] = (char*)malloc(10);
        memcpy(explorados[i], explorar[i],10);
    }
    for(int i = y; i < total; i++){
        t.push_back(Tablero(explorar[i],id[i]));
    }    
    todos = t;
    int bandera = 0;
    int aux = 0;
    int idPadre =0;
    while(bandera!=1){
        movimientos = t.front().determinarMovimientos();
        hijos = t[0].moverFichas(movimientos,explorados,i);
        explorados = (char**)realloc(explorados,(i+1)*10);
        explorados[i] = (char*)malloc(10);
        memcpy(explorados[i], t[0].fichasToString(),10);
        //memcpy(a->hijos[i], t[0].fichasToString(),10);
        t.erase(t.begin());
        for(int j = 0; j < hijos.size(); j++){
            if(strcmp(hijos[j].fichasToString(),meta) == 0) {
                bandera = 1;
                memcpy(a->hijos[0], hijos[j].fichasToString(),10);
                idPadre = hijos[j].getPadre();
            }
            aux++;
            t.push_back(hijos[j]);   
            todos.push_back(hijos[j]);
        }       
        i++;
    } 
    //se agregan hijos en cola
    aux = 1;
    for(int j = todos.size()-1; j>=0 ; j--){
        if (todos[j].getId()==idPadre) {
            memcpy(a->hijos[aux], todos[j].fichasToString(),10);
            idPadre = todos[j].getPadre();
            aux++;
        }
    }
    a->bandera = bandera;
    a->total = aux;    
    return a;
}

Anchura *busqueda(char *inicio, char*meta, int niveles){
    char **explorados = NULL;
    Anchura *a = new Anchura;
    vector<Tablero> hijos;
    vector<Tablero> t;
    int i = 0;
    int movimientos = 0;
    t.push_back(Tablero(inicio));
    int bandera = 0;
    int aux = 0;
    while(i<niveles){
        movimientos = t.front().determinarMovimientos();
        hijos = t[0].moverFichas(movimientos,explorados,i);   
        explorados = (char**)realloc(explorados,(i+1)*10);
        explorados[i] = (char*)malloc(10);
        memcpy(a->hijos[i], t[0].fichasToString(),10);
        memcpy(explorados[i], t[0].fichasToString(),10);
        a->idPadre[i] = t[0].getPadre();
        t.erase(t.begin());
        for(int j = 0; j < hijos.size(); j++){
            //aux] = hijos[j].getId();
            if(strcmp(hijos[j].fichasToString(),meta) == 0) {
                bandera = 1;
            }
            aux++;
            t.push_back(hijos[j]);   
        }       
        i++;
    }
    
    //se agregan hijos en cola
    aux = 0;
    for(int j = i; j < i+t.size(); j++){
        a->idPadre[j] = t[aux].getPadre();
        memcpy(a->hijos[j], t[aux].fichasToString(),10);
        aux++;
        //a->idPadre[j] = t[j].getPadre();
    }
    cout << "Cliente Generó: " << endl;
    for(int j = 0; j < i; j++){
        cout << "Explorados: " << explorados[j] << endl;
    }

    for(int j = 0; j < i+t.size(); j++){
        cout << "Hijos: " << a->hijos[j] << " Padre: "<< a->idPadre[j] <<endl;
    }
    //Se agregan explorados
    
    
    a->bandera = bandera;
    a->numero_hijos = t.size();
    a->total = t.size()+i;    
    return a;
}