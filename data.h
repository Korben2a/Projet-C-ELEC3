/*  Auteur : Enzo Darnaudguilhem
	Création : avril-mai 2020
	Version 2
*/

#pragma once 

#include <libsx.h>

#define MAX_ALPHA 50
#define TAILLE_MOT_MAX 9

/*
Structure qui gère tous les elements du jeu
*/
typedef struct{
	char lettres[9];  //chaine de caractères des lettres tirees
	int cpt_lettres;		//compteur de lettres tirees

	char *voyelles;  //tableau des 6 voyelles
	int freqVoyelles[6]; //frequences des voyelles disponibles
	
	char *consonnes;  //tableau des 20 consonnes
	int freqConsonnes[20]; //frequences des consonnes disponibles


}data;


extern void resetLettres_tirees( data *d);

extern char tirerVoyelle(data *d);
extern void stockerVoyelle(data *d);
extern char tirerConsonne(data *d);
extern void stockerConsonne(data *d);

extern int tirageFini( data *d);
extern char *getLettresTirees( data *d, char * lettres );
extern void clear(data *d);

extern char * majuscules(char *mot_choisi);
extern int verifDico(const char *mot_choisi);
extern int verifLettres(const char *mot_choisi, data *d);
extern int motValide(const char *mot_choisi, data *d);

extern char * tirerLettres(char *lettres_tirees);

