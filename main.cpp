#include <iostream>
#include <stdio.h>
#include <cmath>
#include "CImg.h"
#include "Rectangle.h"
#include "Raquette.h"
#include "Balle.h"
#include "Mur.h"
#include "Briques.h"
using namespace std;
using namespace cimg_library;

int main()
{
	//creation des differents objet et variables
	Balle balle;
	Raquette raquette;
	Mur North,Sud,Ouest,Est;
	vector<Briques> briques;
	briques.resize(30);
	int a=0;
	unsigned char color[3];
	color[0]=255;
	color[1]=255;
	color[2]=255;
	CImg<unsigned char> img(500,500,1,3,0);
	CImgDisplay disp(img,"display");

	//creation des murs
	North.construction('N',0,500,0,10);
	Ouest.construction('O',0,10,0,500);
	Est.construction('E',490,500,0,500);
	Sud.construction('S',0,500,490,500);
	Sud.set_color(255,0,0);
	
	//creation des briques
	int i=0;
	for(int a=0;a<6;a++){
		for(int b=0;b<5;b++){
			briques.at(i).construireBriques(a,b);
			if(i==briques.size()) break;
			else i++;
		}
	}
	//passage a 2 HP de la moitie des briques
	for(int i=0;i<briques.size();i++){if(i%2) briques.at(i).set_HP(1);}
	
	//affichage de message de start
		img.draw_text(225,200,"3",color,0,999999,Font(100));
		disp.display(img);
		disp.wait(1000);	
		img.fill(0);
		img.draw_text(225,200,"2",color,0,999999,Font(100));
		disp.display(img);
		disp.wait(1000);	
		img.fill(0);
		img.draw_text(225,200,"1",color,0,999999,Font(100));
		disp.display(img);
		disp.wait(1000);	
		img.fill(0);
		img.draw_text(125,200,"START",color,0,999999,Font(100));
		disp.display(img);
		disp.wait(1000);	
		img.fill(0);
	
	while (not disp.is_closed()){
		//mise a jour de la position de la raquette et de la balle
		balle.deplacement();
		double Xmouse= disp.mouse_x();
		raquette.deplacement(Xmouse);
		
		//boucle de hestion des briques
		for(int i=0;i<briques.size();i++){
			//gestion des degats sur les briques
			if(briques.at(i).Chevauchement(balle)) briques.at(i).removeHP();
			
			//gestion des rebond de la balle lors du contact avec des briques
			if (balle.North().Chevauchement(briques.at(i)) && !balle.South().Chevauchement(briques.at(i)))
				balle.set_direction(3.1415-balle.get_direction());
			if (balle.West().Chevauchement(briques.at(i)) && !balle.Est().Chevauchement(briques.at(i)))
				balle.set_direction(-balle.get_direction());
			if (balle.South().Chevauchement(briques.at(i)) && !balle.North().Chevauchement(briques.at(i)))
				balle.set_direction(3.1415-balle.get_direction());
			if (balle.West().Chevauchement(briques.at(i)) && !balle.West().Chevauchement(briques.at(i)))
				balle.set_direction(-balle.get_direction());
			
			// gestion de la suppression d'une brique lorsque celle n'a plus d'HP
			if(briques.at(i).HPleft() == 0) briques.erase(briques.begin()+i);
		}
		
		//gestion des rebond pour les murs non letals
		if(balle.Chevauchement(North) || balle.Chevauchement(Ouest) || balle.Chevauchement(Est))
			balle.set_direction(balle.get_direction()+45);
		//gestion du contact avec le mur letal(game over)
		if(balle.Chevauchement(Sud)){
			img.draw_text(15,290,"GAME OVER",color,0,999999,Font(100));
			disp.display(img);
			disp.wait(10000);
		}
		//gestion du contact entre la balle et la raquette
		if(balle.Chevauchement(raquette)) {
			if(a==1){ 
				if(balle.get_direction()<0) balle.set_direction(360-balle.get_direction()); // si la direction n'est pas comprise entre 0 et 360 on la ramene entre ces bornes
				balle.set_direction(fmod(3.1415-balle.get_direction(),2*3.1415)); //calcul de la nouvelle direction
				balle.nouvelle_angle(disp.mouse_x());
			}
			else {
				balle.set_direction(fmod((3*3.1415)/4,360.0)); // lors du premier lancer la direction est vertical on doit gere ce cas particulier
				a=1;
			}
		}

		//Une fois tout les calculs realise on vide l'affichage puis on affiche le nouveaux mis a jour
		img.fill(0);
		North.DrawRectangle(img);
		Sud.DrawRectangle(img);
		Ouest.DrawRectangle(img);
		Est.DrawRectangle(img);
		raquette.DrawRectangle(img);
		balle.DrawRectangle(img);
		for(int i=0;i<briques.size();i++){ briques.at(i).DrawRectangle(img);}
		disp.display(img);
	}
}


