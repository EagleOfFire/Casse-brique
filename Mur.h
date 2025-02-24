#ifndef __MUR
#define __MUR

#include <iostream>
#include "Rectangle.h"

class Mur : public Rectangle
{
	protected :
		char polarPos;
	public :
		Mur(); // constructeur
		~Mur(); // destructeur
		Mur(const Mur&); // constructeur par recopie
		Mur& operator=(const Mur&); // surcharge de l'operateur =
		
		//creation getters pour la position polaire
		char get_polarPos() const {return polarPos;}
		//creation setters pour la position polaire
		void set_polarPos(char a){polarPos=a;}
		
		//declaration des differentes méthode
		void construction(char polar, float x1,float x2,float y1,float y2);
};


#endif
