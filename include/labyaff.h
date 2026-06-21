#ifndef LABYAFF__H
#define LABYAFF__H

#include "laby.h"

enum _couleur{
	Rouge,
	Vert,
	Bleu,
	Standard
};
typedef enum _couleur Couleur;

void printcolor(Couleur couleur);

void lineup(int lignes);

void printcase(Case c);

void printlaby(int lin, int col, Case lab[][col]);

#endif
