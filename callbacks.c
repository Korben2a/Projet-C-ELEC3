/*  Auteur : Enzo Darnaudguilhem
	Création : avril-mai 2020
	Version 2
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <libsx.h>
#include "callbacks.h"
#include "data.h"


extern Widget Entry1, Entry2, Resultats;



/*
	Callback bouton quitter
	Role : quitter l'application
*/
void quitter(Widget q, void *d){
	exit(EXIT_SUCCESS);
}


/*
	Callback bouton verifier
	Role :  recupere les mots des joueurs
			verifie leur validité
			annonce du gagnant
*/
void verifier(Widget q, void *d){
	if ( tirageFini(d) ){
		//on recupere les mots des joueurs
		char *mot1 = GetStringEntry(Entry1);
		char *mot2 = GetStringEntry(Entry2);

		motsValides(mot1,mot2,d);

		bonus(d);

	

	}
}



/*
	Callback bouton jouer
	Role : reinitialise la partie, vide toutes les cases
			Les lettres peuvent etre retirees
*/
void jouer(Widget w, void *d){
	clear(d);
}


/*Callback bouton voyelle
  	Role :  tire une voyelle disponible et l'affiche dans la zone d'affichage
*/
void voyelle(Widget w, void *d){
	stockerVoyelle(d);
}

/*
	Callback bouton consonne
  	Role :  tire une consonne disponible et l'affiche dans la zone d'affichage
*/
void consonne(Widget w, void *d){
	stockerConsonne(d);
}
