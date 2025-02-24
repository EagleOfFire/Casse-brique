#include "Rectangle.h"

// constructeur
Rectangle::Rectangle(){
	x.resize(2);
	x.at(0)=1;
	x.at(1)=10;
	
	y.resize(2);
	y.at(0)=1;
	y.at(1)=10;
	
	color[0]=255;
	color[1]=0;
	color[2]=0;
}

// constructeur par recopie
Rectangle::Rectangle(const Rectangle& B){
	x=B.get_x();
	y=B.get_y();
	for(int i=0;i<3;i++) color[i]=B.get_color()[i];
}

// surcharge de l'operateur =
Rectangle& Rectangle::operator=(const Rectangle& cible){cerr << "plop" << endl;
    if (&cible != this){
		set_x(cible.get_x());
		set_y(cible.get_y());
		set_color(cible.get_color());
    }
	return *this;
}

Rectangle::~Rectangle(){}// destructeur

//Methode d'affichage d'un rectangle
void Rectangle::DrawRectangle(CImg<unsigned char> &image){
	image.draw_rectangle(get_x(0),get_y(0),get_x(1),get_y(1), get_color());
}

//Methode de vérification de chevauchement de 2 rectangle
bool Rectangle::Chevauchement(Rectangle cible){
	vector<float> Rx = cible.get_x();
	vector<float> Ry = cible.get_y();
	
	if(	x.at(0) < Rx.at(1) && Rx.at(0) < x.at(1) && Ry.at(0) < y.at(1) && y.at(0) < Ry.at(1))
		return true;
	else return false;
}

//Methode de verification de chevauchement entre un rectangle et un vecteur de rectangle
vector<Rectangle> Rectangle::ChevauchementVecteur(vector<Rectangle> listRectangle){
	vector<Rectangle> Chevaucher;
	for(int i =0 ; i< listRectangle.size();i++ ){
		if(Chevauchement(listRectangle.at(i))){
			Chevaucher.resize(Chevaucher.size()+1);
			Chevaucher.back()=listRectangle.at(i);
		}
	}
	return Chevaucher;
}
