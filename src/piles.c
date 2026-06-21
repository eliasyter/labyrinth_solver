#include "piles.h"


void cree_vide(struct pile * pile1){
    pile1->tete=NULL;
    pile1->taille=0; 
}

void insere(struct pile * pile1, struct T_pair x){
    struct cell * new_cell;
    struct T_pair * new_pair; 
    new_pair=malloc(sizeof(struct T_pair)); 
    new_cell=malloc(sizeof(struct cell)); 
    new_pair->val1=x.val1; 
    new_pair->val2=x.val2; 
    new_cell->pair=new_pair; 
    new_cell->suivant=pile1->tete;
    pile1->tete=new_cell; 
    pile1->taille ++;  
}


int est_vide(struct pile * pile1){
    if (pile1->taille==0){
        return 1; 
    }else {
        return 0; 
    }
}

struct T_pair * recuperation(struct pile * pile1){
    struct T_pair * resultat = pile1->tete->pair; 
    if (est_vide(pile1)){
        return NULL;         
    }else{
        struct cell * tmp; 
        tmp= pile1->tete; 
        pile1->tete= pile1->tete->suivant;
        free(tmp); 
    }
    pile1->taille --; 
    return resultat; 

}

void destruction(struct pile * pile1){
    while (!est_vide(pile1)){
        recuperation(pile1); 
    }
} 