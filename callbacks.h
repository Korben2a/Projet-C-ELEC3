/*  Auteur : Enzo Darnaudguilhem
	Création : avril-mai 2020
	Version 2
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <libsx.h>
#include "data.h"


extern void quitter(Widget q, void *d);

extern void verifier(Widget q, void *d);

extern void jouer(Widget w, void *d);
extern void voyelle(Widget w, void *d);
extern void consonne(Widget w, void *d);

