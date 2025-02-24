#include "Mur.h"

// constructeur
Mur::Mur(){
	set_color(128,128,128);
}

//Constructeur par recopie
Mur::Mur(const Mur& B){
	x=B.get_x();
	y=B.get_y();
	for(int i=0;i<3;i++) color[i]=B.get_color()[i];
	polarPos=B.get_polarPos();
}

// surcharge de l'operateur =
Mur& Mur::operator=(const Mur& cible){
    if (&cible != this){
		set_x(cible.get_x());
		set_y(cible.get_y());
		set_color(cible.get_color());
		set_polarPos(cible.get_polarPos());
    }
	return *this;
}

// constructeur parametree
void Mur::construction(char polar,float x1,float x2,float y1,float y2){
	set_polarPos(polar);
	set_x(0,x1);
	set_x(1,x2);
	set_y(0,y1);
	set_y(1,y2);	
}

// destructeur
Mur::~Mur(){}


