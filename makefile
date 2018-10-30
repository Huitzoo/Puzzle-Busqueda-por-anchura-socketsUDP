main: main.cpp Tablero.o Ficha.o Coordenada.o
	g++ main.cpp Tablero.o Coordenada.o Ficha.o -o main

Tablero.o: Tablero.cpp Tablero.h
	g++ Tablero.cpp -c

Ficha.o: Ficha.cpp Ficha.h
	g++ Ficha.cpp -c

Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c

