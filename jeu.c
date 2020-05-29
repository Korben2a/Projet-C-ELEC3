/*  Auteur : Enzo Darnaudguilhem
	Création : avril-mai 2020
	Version 2
*/

#include <stdlib.h>
#include <stdio.h>
#include <libsx.h> //itterface graphique
#include "callbacks.h"
#include "data.h"

#define entry_size 100

Widget 	Text1,Text2,Text3,Text4,Text5,Text6,Text7,Text8,Text9, //Zones de texte pour afficher les lettres tirées
		Entry1,	  // zone de saisie du joueur1
		Entry2,	  // zone de saisie du joueur2
		Resultats; //Zone de texte pour les resultats


/*	Antécédent : structure data creee et initialisee
	Role : cree l'interface graphique (fenetre, tous les boutons, zones de saisies)
*/
void init_display(int argc, char *argv[], void *d){
	/*creation et assemblage des widgets*/

	//initialisation
	Widget 	Bconsonne,	//bouton pour choisir une consonne
			Bvoyelle,	//bouton pour choisir une voyelle
			Label1,  	//Zone de texte
			Label2,		//Zone de texte
			Bjouer,	//bouton pour (re)commencer à jouer
			Bquit,	//bouton pour quitter
			Bverifier, //bouton pour verifier les resultats
			Block1, //case invisible pour faire de l'espace
			Block2;	//case invisible pour faire de l'espace


	//creation boutons et zones de saisies
	Bconsonne = MakeButton("  Consonne  ", consonne, d);
	Bvoyelle = MakeButton("  Voyelle  ", voyelle, d);
	Text1 = MakeTextWidget("       ", False, False, 60, 20);
	Text2 = MakeTextWidget("       ", False, False, 60, 20);
	Text3 = MakeTextWidget("       ", False, False, 60, 20);
	Text4 = MakeTextWidget("       ", False, False, 60, 20);
	Text5 = MakeTextWidget("       ", False, False, 60, 20);
	Text6 = MakeTextWidget("       ", False, False, 60, 20);
	Text7 = MakeTextWidget("       ", False, False, 60, 20);
	Text8 = MakeTextWidget("       ", False, False, 60, 20);
	Text9 = MakeTextWidget("       ", False, False, 60, 20);
	Label1 = MakeLabel(" Mot joueur 1 : ");
	Label2 = MakeLabel(" Mot joueur 2 : ");
	Entry1 = MakeStringEntry(NULL, entry_size, NULL, NULL);
	Entry2 = MakeStringEntry(NULL, entry_size, NULL, NULL);
	Bverifier = MakeButton("  Verififier les resultats  ", verifier, d);
	Resultats = MakeTextWidget("",False,False,400,20);
	Bjouer = MakeButton("  (Re)Jouer  ", jouer, d);
	Bquit = MakeButton("  Quitter  ", quitter, NULL);
	Block1 = MakeLabel("");
	Block2 = MakeLabel("                                         ");


	//Couleur des Widget
	SetBgColor(Bvoyelle,GetRGBColor(26,6,33));
	SetBgColor(Bconsonne,GetRGBColor(26,6,33));
	SetBgColor(Bvoyelle,GetRGBColor(26,6,33));
	SetBgColor(Bverifier,GetRGBColor(26,6,33));
	SetBgColor(Bquit,GetRGBColor(32,41,205));
	SetBgColor(Bjouer,GetRGBColor(32,41,205));
	SetBgColor(Bconsonne,GetRGBColor(26,6,33));
	SetBgColor(Bconsonne,GetRGBColor(26,6,33));
	SetBgColor(Label1,GetRGBColor(216,162,233));
	SetBgColor(Label2,GetRGBColor(216,162,233));
	SetBgColor(Entry1,GetRGBColor(247,229,254));
	SetBgColor(Entry2,GetRGBColor(247,229,254));
	SetBgColor(Resultats,GetRGBColor(247,229,254));
	SetBgColor(Resultats,GetRGBColor(247,229,254));
	SetBgColor(Block1,GetRGBColor(216,162,233));
	SetBgColor(Block2,GetRGBColor(216,162,233));

	SetFgColor(Bvoyelle,GetNamedColor("White"));
	SetFgColor(Bconsonne,GetNamedColor("White"));
	SetFgColor(Bverifier,GetNamedColor("White"));
	SetFgColor(Bquit,GetNamedColor("White"));
	SetFgColor(Bjouer,GetNamedColor("White"));
	SetFgColor(Label1,GetNamedColor("White"));
	SetFgColor(Label2,GetNamedColor("White"));

	SetBorderColor(Block1,GetRGBColor(216,162,233));
	SetBorderColor(Block2,GetRGBColor(216,162,233));


	//couleur des cases de lettres tirees
	SetBgColor(Text1,GetRGBColor(201,249,244));
	SetBgColor(Text2,GetRGBColor(201,249,244));
	SetBgColor(Text3,GetRGBColor(201,249,244));
	SetBgColor(Text4,GetRGBColor(201,249,244));
	SetBgColor(Text5,GetRGBColor(201,249,244));
	SetBgColor(Text6,GetRGBColor(201,249,244));
	SetBgColor(Text7,GetRGBColor(201,249,244));
	SetBgColor(Text8,GetRGBColor(201,249,244));
	SetBgColor(Text9,GetRGBColor(201,249,244));


	//position boutons et zone de saisie
	SetWidgetPos(Bvoyelle, PLACE_RIGHT, Bconsonne, NO_CARE, NULL);
	SetWidgetPos(Text1, PLACE_UNDER, Bconsonne, PLACE_UNDER, Bvoyelle);
	SetWidgetPos(Text2, PLACE_UNDER, Bconsonne, PLACE_RIGHT, Text1);
	SetWidgetPos(Text3, PLACE_UNDER, Bconsonne, PLACE_RIGHT, Text2);
	SetWidgetPos(Text4, PLACE_UNDER, Bconsonne, PLACE_RIGHT, Text3);
	SetWidgetPos(Text5, PLACE_UNDER, Bconsonne, PLACE_RIGHT, Text4);
	SetWidgetPos(Text6, PLACE_UNDER, Bconsonne, PLACE_RIGHT, Text5);
	SetWidgetPos(Text7, PLACE_UNDER, Bconsonne, PLACE_RIGHT, Text6);
	SetWidgetPos(Text8, PLACE_UNDER, Bconsonne, PLACE_RIGHT, Text7);
	SetWidgetPos(Text9, PLACE_UNDER, Bconsonne, PLACE_RIGHT, Text8);
	SetWidgetPos(Label1, PLACE_UNDER, Text1, NO_CARE, NULL);
	SetWidgetPos(Label2, PLACE_UNDER, Text1, PLACE_RIGHT, Entry1);
	SetWidgetPos(Entry1, PLACE_UNDER, Text1, PLACE_RIGHT, Label1);
	SetWidgetPos(Entry2, PLACE_UNDER, Text1, PLACE_RIGHT, Label2);
	SetWidgetPos(Bverifier, PLACE_UNDER, Entry1, NO_CARE, NULL);
	SetWidgetPos(Resultats, PLACE_UNDER, Entry1, PLACE_RIGHT, Bverifier);
	SetWidgetPos(Bquit, PLACE_UNDER, Block1, NO_CARE, NULL);
	SetWidgetPos(Bjouer, PLACE_UNDER, Block1, PLACE_RIGHT, Block2);
	SetWidgetPos(Block1, PLACE_UNDER, Bverifier, NO_CARE, NULL);
	SetWidgetPos(Block2, PLACE_UNDER, Block1, PLACE_RIGHT, Bquit);


	/*pour gérer les couleurs*/
	GetStandardColors();

	/*pour afficher l'interface*/
	ShowDisplay();


}



int main(int argc, char **argv) {
	data d;

	static char *args[] = {"-bg", "#D8A2E9", NULL};
	PredefArgs = args;

	if (OpenDisplay(argc, argv) == 0){
		fprintf(stderr, "Can't open display\n");
	}

	resetLettres_tirees(&d);

	init_display(argc, argv, &d);
	MainLoop();
	
    return EXIT_SUCCESS;

}
