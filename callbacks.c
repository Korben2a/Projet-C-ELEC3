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

		//on met en majuscule les mots des joueurs au cas ou ils ne l'ont pas deja fait
		majuscules(mot1);
		majuscules(mot2);

		
		//verifier le gagnant
		if (motValide(mot1, d)){
			//mot1 valide
			if (motValide(mot2, d)){
				//mot1 et mot2 valides
				if (strlen(mot1)==strlen(mot2)){
					SetTextWidgetText(Resultats,"Ex aequo",False);
				}

				else if (strlen(mot1)>strlen(mot2)){
					SetTextWidgetText(Resultats,"Le joueur 1 gagne, son mot est plus long",False);
				}

				else { 
					SetTextWidgetText(Resultats,"Le joueur 2 gagne, son mot est plus long !",False);
				}
				
			}

			//mot1 valide et mot2 invalide
			else {
				SetTextWidgetText(Resultats,"Le joueur 1 gagne, le mot du joueur 2 est invalide ! ",False);
			}
		}

		//mot1 invalide
		else {
			if (motValide(mot2, d)) {
				SetTextWidgetText(Resultats,"Le joueur 2 gagne, le mot du joueur 1 est invalide ! ",False);
			}

			//mot1 et mot2 invalides
			else{
				SetTextWidgetText(Resultats,"Aucun gagnant, mots invalides. ",False);
			}
		}
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
