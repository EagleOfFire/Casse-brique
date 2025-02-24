#ifndef __BRIQUES
#define __BRIQUES

#include <iostream>
#include "Rectangle.h"

class Briques : public Rectangle
{
	protected :
		int HP;
	public :
		Briques(); // constructeur
		~Briques(); // destructeur
		Briques(const Briques&); // constructeur par recopie
		Briques& operator=(const Briques&); // surcharge de l'operateur =
		
		//creation getters pour HP
		int get_HP() const {return HP;}
		//creation setters pour HP
		void set_HP(int v){HP=v;}
		
		//declaration des differentes methodes
		int HPleft();
		void construireBriques(int,int);
		void removeHP();
};

#endif


