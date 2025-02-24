#include "Briques.h"

// constructeur
Briques::Briques(){
	set_HP(2);
	set_color(0,0,255);
	//longueur = 75
	set_x(0,15);
	set_x(1,90);
	//hauteur = 40
	set_y(0,15);
	set_y(1,55);
}

//Constructeur par recopie
Briques::Briques(const Briques& B){
	x=B.get_x();
	y=B.get_y();
	for(int i=0;i<3;i++) color[i]=B.get_color()[i];
	HP=B.get_HP();
}

// surcharge de l'operateur =
Briques& Briques::operator=(const Briques& cible){
    if (&cible != this){
		set_x(cible.get_x());
		set_y(cible.get_y());
		set_color(cible.get_color());
		set_HP(cible.get_HP());
    }
	return *this;
}

// destructeur
Briques::~Briques(){}

//Methode qui renvoit le nombre d'HP d'une briques et change sa couleur si necessaire
int Briques::HPleft(){
	if(get_HP()==1){set_color(51,255,255);}
	return get_HP();
}

//Methode de construction des briques 
void Briques::construireBriques(int row,int col){
	set_x(0,get_x(0)+row*79);
	set_y(0,get_y(0)+col*45);
	
	set_x(1,get_x(1)+row*79);
	set_y(1,get_y(1)+col*45);
}

//Methode de suppression des vies d'une brique
void Briques::removeHP(){
	set_HP(get_HP()-1);
}

