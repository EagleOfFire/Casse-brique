#include "Raquette.h"

// constructeur
Raquette::Raquette(){
	set_color(0,255,0);
	set_x(0,200);
	set_x(1,300);
	set_y(0,450);
	set_y(1,460);
}

// destructeur
Raquette::~Raquette(){}

//Constructeur par recopie
Raquette::Raquette(const Raquette& B){
	x=B.get_x();
	y=B.get_y();
	for(int i=0;i<3;i++) color[i]=B.get_color()[i];
}

// surcharge de l'operateur =
Raquette& Raquette::operator=(const Raquette& cible){
    if (&cible != this){
		set_x(cible.get_x());
		set_y(cible.get_y());
		set_color(cible.get_color());
    }
	return *this;
}

//methode de gestion des deplacement de la raquette
void Raquette::deplacement(double x){
	vector<float>X;
	X.resize(2);
	
	X.at(0)=x-50;
	X.at(1)=x+50;
	
	set_x(X);
}
