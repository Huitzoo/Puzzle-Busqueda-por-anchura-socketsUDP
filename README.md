# Puzzle-Busqueda-por-anchura-socketsUDP
Implementación del algoritmo de búsqueda por anchura en una aplicación distribuida. 

Compilar:
    Cliente:  make -f makefileC
    Servidor: make -f makefileS

Ejecutar
    Para el cliente: 

    ./cliente a b c d e f....
    a: número de servidores
    b: puzzle inicial
    c: puzzle final
    d: puerto de los servidores, todos deben usar el mismo puerto.
    e: numero de operación, 1
    f...: las ips de los servidores que vamos a usar.

    Ejemplo:
    ./cliente 1 123456780 087654321 7200 1 127.0.0.1

    Para el servidor:

    ./servidor a
    a: Es el puerto que se va a utilizar.

    Ejemplo 
    ./servidor 7200
    