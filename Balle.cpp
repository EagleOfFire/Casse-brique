#include "Balle.h"
#include <cmath>

// constructeur
Balle::Balle(){
	set_color(255,255,0);
	set_x(0,245);
	set_x(1,255);
	set_y(0,340);
	set_y(1,350);
	
	set_vitesse(0.5);
	set_direction((3*3.1415)/2);
}

// destructeur
Balle::~Balle(){}

//Constructeur par recopie
Balle::Balle(const Balle& B){
	x=B.get_x();
	y=B.get_y();
	for(int i=0;i<3;i++) color[i]=B.get_color()[i];
	vitesse=B.get_vitesse();
	direction=B.get_direction();
}

// surcharge de l'operateur =
Balle& Balle::operator=(const Balle& cible){
    if (&cible != this){
		set_x(cible.get_x());
		set_y(cible.get_y());
		set_color(cible.get_color());
		set_vitesse(cible.get_vitesse());
		set_direction(cible.get_direction());
    }
	return *this;
}

//Methode de gestion des deplacements
void Balle::deplacement(){
	vector<float>Newx;
	Newx.resize(2);
	Newx.at(0)=get_x(0)+get_vitesse()*cos(get_direction());
	Newx.at(1)=get_x(1)+get_vitesse()*cos(get_direction());	
	
	vector<float>Newy;
	Newy.resize(2);
	Newy.at(0)=get_y(0)-( get_vitesse()*sin(get_direction()) );
	Newy.at(1)=get_y(1)-( get_vitesse()*sin(get_direction()) );	
	
	set_x(Newx);
	set_y(Newy);
}

//Methode de creation du cote nord de la balle
Rectangle Balle::North(){
	Rectangle North;
	vector<float> X,Y;
	X.resize(2);
	Y.resize(2);
	X.at(0)=get_x(0);
	Y.at(0)=get_y(0)-1;
	X.at(1)=get_x(1);
	Y.at(1)=get_y(0);
	
	North.set_x(X);
	North.set_y(Y);
	return North;
}

//Methode de creation du cote sud de la balle
Rectangle Balle::South(){
	Rectangle South;
	vector<float> X,Y;
	X.resize(2);
	Y.resize(2);
	X.at(0)=get_x(0);
	Y.at(0)=get_y(1);
	X.at(1)=get_x(1);
	Y.at(1)=get_y(1)+1;
	
	South.set_x(X);
	South.set_y(Y);
	return South;
}

//Methode de creation du cote est de la balle
Rectangle Balle::Est(){
	Rectangle Est;
	vector<float> X,Y;
	X.resize(2);
	Y.resize(2);
	X.at(0)=get_x(0);
	Y.at(0)=get_y(1);
	X.at(1)=get_x(1)+1;
	Y.at(1)=get_y(1);
	
	Est.set_x(X);
	Est.set_y(Y);
	return Est;
}

//Methode de creation du cote ouest de la balle
Rectangle Balle::West(){
	Rectangle West;
	vector<float> X,Y;
	X.resize(2);
	Y.resize(2);
	X.at(0)=get_x(0)-1;
	Y.at(0)=get_y(0);
	X.at(1)=get_x(0);
	Y.at(1)=get_y(1);
	
	West.set_x(X);
	West.set_y(Y);	
	return West;
}

//Methode de calcul de la nouvelle direction lorsque la balle touche la raquette
void Balle::nouvelle_angle(double centreRaquette){
	float centreBalle=(get_x(0)+get_y(1))/2;
	float Newangle=centreBalle-centreRaquette;
	set_direction(fmod(get_direction()+Newangle,360));
}


