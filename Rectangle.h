#ifndef __RECTANGLE
#define __RECTANGLE
#include <iostream>
#include <vector>
#include "CImg.h"
using namespace std;
using namespace cimg_library;


class Rectangle
{
protected : // declaration des variables proteger
	vector<float> x; // creation d'un vecteur de float pour les x
	vector<float> y; // creation d'un vecteur de float pour les y
	unsigned char color[3]; // creation d'un tableau de 3 cases pour contenir les taux de couleur
public : // declaration des variables public
	Rectangle(); // constructeur
	Rectangle(const Rectangle&); // constructeur par recopie
	~Rectangle(); // destructeur
	Rectangle& operator=(const Rectangle&); // surcharge de l'operateur =
	
	//creation getters pour x et y dans le cas vecteur entier
	vector<float> get_x() const{return x;}
	vector<float> get_y() const{return y;}
	
	//creation getters pour x et y dans le cas d'un angle precis
	float get_x(int angle) const{return x.at(angle);}
	float get_y(int angle) const{return y.at(angle);}
	
	//creation getters pour le tableau de couleur
	const unsigned char* get_color() const{return color;}
	
	//creation setters pour x et y dans le cas vecteur entier
	void set_x(int angle, float X){x.at(angle)=X;}
	void set_y(int angle, float Y){y.at(angle)=Y;}

	//creation setters pour x et y dans le cas d'un angle precis
	void set_x(vector<float> X){x=X;}
	void set_y(vector<float> Y){y=Y;}
	
	//creation setters des couleurs avec le ratio RGB
	void set_color(unsigned char rouge,unsigned char vert,unsigned char bleu){
		color[0]=rouge;
		color[1]=vert;
		color[2]=bleu;
	}
	
	//creation setters des couleurs a partir d'une autre couleur
	void set_color(const unsigned char* COLOR){
		color[0]=COLOR[0];
		color[1]=COLOR[1];
		color[2]=COLOR[2];
	}
	
	//declaration des prototype de méthode et fonction lié a la classe Rectangle
	void DrawRectangle(CImg<unsigned char>& );
	bool Chevauchement(Rectangle);
	vector<Rectangle> ChevauchementVecteur(vector<Rectangle>);
};

#endif

