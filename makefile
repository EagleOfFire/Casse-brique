main : main.cpp Rectangle.o Raquette.o Balle.o Mur.o Briques.o
	g++ -o main main.cpp Rectangle.o Raquette.o Balle.o Mur.o Briques.o -Wfatal-errors -lX11 -lpthread

Rectangle.o : Rectangle.h Rectangle.cpp
	g++ -c Rectangle.cpp 

Raquette.o : Raquette.h Raquette.cpp
	g++ -c Raquette.cpp
	
Balle.o : Balle.h Balle.cpp
	g++ -c Balle.cpp
	
Mur.o : Mur.h Mur.cpp
	g++ -c Mur.cpp

Briques.o : Briques.h Briques.cpp
	g++ -c Briques.cpp
