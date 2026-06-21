#ifndef LABY__H
#define LABY__H

#define LABY_FILE "data/laby.txt"

// definir le type Case
enum Case {vide , mur, visite, cul};

typedef enum Case Case;



void gen_laby(int lignes, int colonnes, Case laby[][colonnes]);
void parselaby(int lignes, int colonnes, Case laby[][colonnes]);

// definir le prototype des autres fonctions
void resolution(int lin, int col, Case laby[][col]);

#endif
