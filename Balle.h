#ifndef __BALLE
#define __BALLE

#include <iostream>
#include "Rectangle.h"

class Balle : public Rectangle
{
	protected :
		float vitesse; 
		float direction; // en rad
	public :
		Balle(); // constructeur
		~Balle(); // destructeur
		Balle(const Balle&); // constructeur par recopie
		Balle& operator=(const Balle&); // surcharge de l'operateur =	

		//creation getters pour la vitesse
		float get_vitesse() const {return vitesse;}
		//creation setters pour la vitesse
		void set_vitesse(float v){vitesse = v;}
		//creation getters pour la direction
		float get_direction() const {return direction;}
		//creation setters pour la direction
		void set_direction(float d){direction = d;}
		
		//declaration des differentes methode
		void deplacement();
		Rectangle North();
		Rectangle South();
		Rectangle Est();
		Rectangle West();
		void nouvelle_angle(double);
};

#endif
