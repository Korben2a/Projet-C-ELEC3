/*  Auteur : Enzo Darnaudguilhem
	Création : avril-mai 2020
	Version 2
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "data.h"

#define MAX_ALPHA 50
#define TAILLE_MOT_MAX 9

extern Widget Text1,Text2,Text3,Text4,Text5,Text6,Text7,Text8,Text9,Entry1,Entry2,Resultats;


/*	
Role : reinitialise la structure data (compteur de lettres, frequences des lettres)
*/
extern void resetLettres_tirees( data *d){
	//initialisation du compteur de lettres
	d->cpt_lettres = 0;

	//Initialisation des lettres et leur fréquences
	//initialisation des voyelles
	d->voyelles = "AEIOUY";
	//on utilise un varibale freqVoyellessRemplissage qu'on peut initialiser facilement
	//int freqVoyellesRemplissage[6] = {9,15,8,6,6,1};
	int freqVoyellesRemplissage[6] = {9,15,8,6,6,1};
	for (int i=0 ; i<6 ; i++){
		d->freqVoyelles[i] = freqVoyellesRemplissage[i];
	}
	
	//initialisation des consonnes
	d->consonnes = "BCDFGHJKLMNPQRSTVWXZ";
	
	//on utilise un varibale freqConsonnesRemplissage qu'on peut initialiser facilement
	int freqConsonnesRemplissage[20] = {2,2,3,2,2,2,1,1,4,3,6,2,1,6,6,6,2,1,1,1};
	for (int i=0 ; i<20 ; i++){
		d->freqConsonnes[i] = freqConsonnesRemplissage[i];
	}
}


/*
	Antedecent : la structure data a ete initialisee
	Role :  Tirer une voyelle à l'aide d'un random
			Reduire la frequence de cette lettre de 1
			Retourne la voyelle
*/
char tirerVoyelle(data *d){
	srandom(time(NULL));

	//nombre de voyelles disponibles
	int nb_voyelles = 0;
	for (int i=0 ; i<6 ; i++){
		nb_voyelles = nb_voyelles + d->freqVoyelles[i];
	}
	nb_voyelles--; //les indices de tableaux commencent a 0

	//int aleatoire pour tirer la voyelle
	int random = rand() % nb_voyelles;

	//associer le random  a un indice de voyelle
	int cpt=0;
	int i=d->freqVoyelles[cpt];
	while(random > i){
		cpt++;
		i=i+d->freqVoyelles[cpt];	
	}

	//on tire la voyelle
	char voyelle_tiree = d->voyelles[cpt];
	
	
	//on enleve la voyelle tiree de la pioche
	switch(voyelle_tiree){
		case 'A' : d->freqVoyelles[0]--; break;
		case 'E' : d->freqVoyelles[1]--; break;
		case 'I' : d->freqVoyelles[2]--; break;
		case 'O' : d->freqVoyelles[3]--; break;
		case 'U' : d->freqVoyelles[4]--; break;
		case 'Y' : d->freqVoyelles[5]--; break;
	}
	
	//eviter les indices negatifs
	for (int k=0 ; k<6 ; k++){
		if (d->freqVoyelles[k] <0){
			d->freqVoyelles[k]=0;
		}
	}
	return voyelle_tiree;
}



/*
	Antedecent : la structure data a ete initialisee
	Role :  Tire une voyelle et la stocke dans la bonne case d'affichage
			et dans la structure (dans la chaine de caracteres lettres)
*/
void stockerVoyelle(data *d){
	if (d->cpt_lettres < TAILLE_MOT_MAX){
		//stocker la voyelle tiree dans sa case d'affichage
		char s[5]="    ";
		s[3]=tirerVoyelle(d);

		if (d->cpt_lettres == 0){
			SetTextWidgetText(Text1, s, False);
		}
		else if(d->cpt_lettres == 1){
			SetTextWidgetText(Text2, s, False);
		}
		else if(d->cpt_lettres == 2){
			SetTextWidgetText(Text3, s, False);
		}
		else if(d->cpt_lettres == 3){
			SetTextWidgetText(Text4, s, False);
		}
		else if(d->cpt_lettres == 4){
			SetTextWidgetText(Text5, s, False);
		}
		else if(d->cpt_lettres == 5){
			SetTextWidgetText(Text6, s, False);
		}
		else if(d->cpt_lettres == 6){
			SetTextWidgetText(Text7, s, False);
		}
		else if(d->cpt_lettres == 7){
			SetTextWidgetText(Text8, s, False);
		}
		else {
			SetTextWidgetText(Text9, s, False);
		}

		//stocker la consonne tiree dans la structure
		d->lettres[d->cpt_lettres]=s[3];

		//incrementer le compteur de lettres tirees
		d->cpt_lettres = d->cpt_lettres + 1;
	}	
}



/*
	Antedecent : la structure data a ete initialisee
	Role :  tirer une consonne à l'aide d'un random
			reduire la frequence de cette lettre de 1
			retournd la consonne
*/
char tirerConsonne(	data *d){
	srandom(time(NULL));
	//nombre de consonnes disponibles
	int nb_consonnes = 0;
	for (int i=0 ; i<20 ; i++){
		nb_consonnes = nb_consonnes + d->freqConsonnes[i];
	}
	nb_consonnes--; //les indices de tableaux commencent a 0

	//int aleatoire pour tirer la consonne
	int random = rand() % nb_consonnes;

	//associer le random  a un indice de consonne
	int cpt=0;
	int i=d->freqConsonnes[cpt];
	while(random > i){	
		cpt++;
		i=i+d->freqConsonnes[cpt];	
	}

	//on tire la consonne
	char consonne_tiree = d->consonnes[cpt];

	//on enleve la consonne tiree de la pioche
	switch(consonne_tiree){
		case 'B' : d->freqConsonnes[0]--; break;
		case 'C' : d->freqConsonnes[1]--; break;
		case 'D' : d->freqConsonnes[2]--; break;
		case 'F' : d->freqConsonnes[3]--; break;
		case 'G' : d->freqConsonnes[4]--; break;
		case 'H' : d->freqConsonnes[5]--; break;
		case 'J' : d->freqConsonnes[6]--; break;
		case 'K' : d->freqConsonnes[7]--; break;
		case 'L' : d->freqConsonnes[8]--; break;
		case 'M' : d->freqConsonnes[9]--; break;
		case 'N' : d->freqConsonnes[10]--; break;
		case 'P' : d->freqConsonnes[11]--; break;
		case 'Q' : d->freqConsonnes[12]--; break;
		case 'R' : d->freqConsonnes[13]--; break;
		case 'S' : d->freqConsonnes[14]--; break;
		case 'T' : d->freqConsonnes[15]--; break;
		case 'V' : d->freqConsonnes[16]--; break;
		case 'W' : d->freqConsonnes[17]--; break;
		case 'X' : d->freqConsonnes[18]--; break;
		case 'Z' : d->freqConsonnes[19]--; break;
	}
	
	//eviter les indices negatifs
	for (int k=0 ; k<6 ; k++){
		if (d->freqVoyelles[k] <0){
			d->freqVoyelles[k]=0;
		}
	}

	return consonne_tiree;
}
	


/*
	Antedecent : la structure data a ete initialisee
	Role :  Tire une consonne et la stocke dans la bonne case d'affichage
			et dans la structure
*/
void stockerConsonne(data *d){
	if (d->cpt_lettres < TAILLE_MOT_MAX){
		//stocker la voyelle tiree dans sa case d'affichage
		char s[5]="    ";
		s[3]=tirerConsonne(d);  //on met des espaces avant la lettrepour afficher au milieu de la case
	
		if (d->cpt_lettres == 0){
			SetTextWidgetText(Text1, s, False);
		}
		else if(d->cpt_lettres == 1){
			SetTextWidgetText(Text2, s, False);
		}
		else if(d->cpt_lettres == 2){
			SetTextWidgetText(Text3, s, False);
		}
		else if(d->cpt_lettres == 3){
			SetTextWidgetText(Text4, s, False);
		}
		else if(d->cpt_lettres == 4){
			SetTextWidgetText(Text5, s, False);
		}
		else if(d->cpt_lettres == 5){
			SetTextWidgetText(Text6, s, False);
		}
		else if(d->cpt_lettres == 6){
			SetTextWidgetText(Text7, s, False);
		}
		else if(d->cpt_lettres == 7){
			SetTextWidgetText(Text8, s, False);
		}
		else {
			SetTextWidgetText(Text9, s, False);
		}

		//on stocke la lettre tiree dans la structure
		d->lettres[d->cpt_lettres]=s[3];

		//incrementer le compteur de lettres tirees
		d->cpt_lettres = d->cpt_lettres + 1;
	}


}


/*
	Antedecent : la structure data a ete initialisee
	Role : renvoie 1 si les 9 lettres sont tirees, 0 sinon
*/
int tirageFini( data *d){
	return (d->cpt_lettres == TAILLE_MOT_MAX);
}



/*
	Role : Reinitialise tous les parametres pour une nouvelle partie
*/
void clear( data *d){
	//vide les cases
	SetTextWidgetText(Text1,"",False);
	SetTextWidgetText(Text2,"",False);
	SetTextWidgetText(Text3,"",False);
	SetTextWidgetText(Text4,"",False);
	SetTextWidgetText(Text5,"",False);
	SetTextWidgetText(Text6,"",False);
	SetTextWidgetText(Text7,"",False);
	SetTextWidgetText(Text8,"",False);
	SetTextWidgetText(Text9,"",False);
	SetStringEntry(Entry1,"");
	SetStringEntry(Entry2,"");
	SetTextWidgetText(Resultats,"",False);

	//reinitialise la structure
	resetLettres_tirees(d);
}



/*
	Antecedent :  mot_choisi est une chaine de caractere
	Role : met les lettres de la chaine de caractères en majuscule
*/
char * majuscules(char *mot_choisi){
	for (int c = 0 ; c < strlen(mot_choisi) ; c++){
		mot_choisi[c] = toupper(mot_choisi[c]);
	}

	return mot_choisi;
}




/*
	Antécédent : mot_choisi composé de 9 caracteres maximum
	Rôle : 	Parcoure le dictionnaire,
			renvoie 1 si le mot choisi est dans le dictionnaire, 0 sinon
*/
int verifDico(const char *mot_choisi){
	FILE *in;  //dictionnaire
	int res = 0;
	
	//gestion d'erreur d'ouverture du dictionnaire
	if ( ((in = fopen("dicolinux","r")) == NULL) ){
		perror("dico");
		exit(errno);
	}

	char mot[MAX_ALPHA];
	//parcoure le dictionnaire
	while( fscanf(in,"%s",mot) != EOF ){
		//compare les mots du dictionnaire et le mot_choisi
		if (strcmp(majuscules(mot),mot_choisi) == 0){
			res=1;  //les mots sont égaux
		}
	}
	//fermeture du dictionnaire
	fclose(in);

	return res;
}



/*
Antécédent : mot composé de 9 caractères maximum (majuscules ou autres caractères)
Rôle : Parcoure le mot, renvoie 1 si tous les caractères sont des lettres tirees sans doublon,
		0 sinon
*/
int verifLettres(const char *mot_choisi, data *d){
	int cpt_lettres = 0 ; //compteur de lettres valides
	int antiDoublon[TAILLE_MOT_MAX] = {0};  //pour eviter d'utiliser les lettres 2 fois
	for (int c = 0 ; c < strlen(mot_choisi) ; c++){
		//verifier que chaque lettre est une lettre tiree (sans doublon)
		for (int i=0 ; i<TAILLE_MOT_MAX ; i++){
			if (mot_choisi[c] == d->lettres[i]){
				if (antiDoublon[i] == 0){
					//lettre non utilisée plus de fois que disponible
					cpt_lettres ++;
					antiDoublon[i]=1;
				}				
			}
		}
	}
	
	//renvoie 1 si le compteur de lettres correspond à la taille du mot
	if (cpt_lettres >= strlen(mot_choisi)){
		return 1;
	}

	//touts les caractères ne sont pas des lettres tirees, ou il y a des doublons
	return 0;
}



/*
Antécédent : un mot a été choisi avec 9 caractères max
Role 		: renvoie 1 si le mot choisi existe dans le dictionnaire et s'il est composé de lettres tirees sans doublon
			0 sinon
*/
int motValide(const char *mot_choisi, data *d){
	if ( (verifDico(mot_choisi) == 1) && (verifLettres(mot_choisi,d) == 1) ){
		return 1;
	}
	return 0;
}