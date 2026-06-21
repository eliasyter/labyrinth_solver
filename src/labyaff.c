#include "labyaff.h"
#include <stdio.h>
#include <unistd.h>
void printcolor(Couleur couleur){
	switch (couleur){
		case Rouge:
			printf("\033[91;1m");
			break;
		case Vert:
			printf("\033[92;1m");
			break;
		case Bleu:
			printf("\033[94;1m");
			break;
		case Standard:
		default:
			printf("\033[1m");
	}

	printf("\u2588\u2588\033[0m");
}

void lineup(int lignes){
	for (int i=0; i<lignes; i++){
		printf("\033[F");
	}
}

void printcase(Case c){
	switch (c){
		case mur: 
			printcolor(Bleu); 
			break;
		case vide:
			printcolor(Standard); 
			break;
		case visite: 
			printcolor(Vert); 
			break; 
		case cul: 
			printcolor(Rouge); 
			break; 
		default: 
			printcolor(Standard); 
	}
}

void printlaby(int lin, int col, Case lab[][col]){
	for (int i=0; i<lin; i++){
		for (int j=0; j<col; j++){
			printcase(lab[i][j]); 
			
		}
		printf("\n"); 
	}
    lineup(lin); 
    usleep(1 * 100);
}
