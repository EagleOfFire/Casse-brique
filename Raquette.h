#ifndef __RAQUETTE
#define __RAQUETTE

#include <iostream>
#include "Rectangle.h"

class Raquette : public Rectangle
{
public :
	Raquette(); // constructeur
	~Raquette(); // destructeur
	Raquette(const Raquette&); // constructeur par recopie
	Raquette& operator=(const Raquette&); // surcharge de l'operateur =
		
	//declaration de la methode de deplacement
	void deplacement(double);
};

#endif
