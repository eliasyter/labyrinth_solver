#ifndef PILES__H
#define PILES__H


#include <stdio.h>
#include <stdlib.h>
struct T_pair{
    int val1; 
    int val2; 
}; 

struct cell{
    struct T_pair * pair; 
    struct cell * suivant; 
}; 


struct pile {
    struct cell * tete; 
    int taille; 
}; 




void cree_vide(struct pile * pile1); 

void insere(struct pile * pile1, struct T_pair x); 

int est_vide(struct pile * pile1); 

struct T_pair * recuperation(struct pile * pile1); 

void destruction(struct pile * pile1); 










#endif
