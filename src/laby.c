#include "laby.h"
#include "labyaff.h"
#include "piles.h"
#include <stdio.h>
#include <time.h>


int T_F_count_opptions(int opptions[]){
     int i=0;
    int k;  
    for (k=0;k<4;k++){
        if (opptions[k]==1){
            i++;
        }
    }
    return i; 


}


int is_full(int lignes, int colonnes, int T_F_laby[][colonnes]){
    for (int l=0;l<lignes;l++){
        for (int c=0; c<colonnes;c++){
            if (T_F_laby[l][c]){
                return 0; 
            }
        }
    }
    return 1; 
}

void gen_laby(int lignes, int colonnes, Case laby[][colonnes]){
    srand(time(NULL));
    int T_F_laby[lignes][colonnes]; 
    


    for (int l=0; l<lignes;l++){
        for (int c=0;c<colonnes;c++){
            if (l==0 || c==0){
                laby[l][c]=mur;
                T_F_laby[l][c]=0;  
            }else if (l==lignes-1||c==colonnes-1){ 
                laby[l][c]=mur;
                T_F_laby[l][c]=0; 
            }else{
                laby[l][c]=vide; 
                T_F_laby[l][c]=1; 
            }         

            if (l%2==0){
                T_F_laby[l][c]=0; 
                laby[l][c]=mur; 
            
            }else if (c%2==0){
                T_F_laby[l][c]=0; 
                laby[l][c]=mur; 
        }

        }
    }

    int start_l; 
    int start_c;
    
    struct T_pair * tmp; 
    tmp = malloc(sizeof(struct T_pair)); 
    start_l=((rand()%((lignes-1)/2))*2)+1; 
    start_c=((rand()%((colonnes-1)/2))*2)+1; 
    printf("line:%d, colonne:%d, random:%d \n", start_l,start_c, rand());
    
    struct T_pair start_pair; 
    start_pair.val1=start_l; 
    start_pair.val2=start_c; 
    struct pile * chemin;
    chemin=malloc(sizeof(struct pile));
    cree_vide(chemin);  
    insere(chemin,start_pair); 
    
	int opptions[4];  
    struct T_pair pos; 
    pos= start_pair; 

    int vei; 
    int vei_count; 
    
    while (!is_full(lignes,colonnes,T_F_laby)){
        T_F_laby[pos.val1][pos.val2]=0; 
        if (pos.val1>1){
            opptions[0]=T_F_laby[pos.val1-2][pos.val2];
        }else{ 
            opptions[0]=0;
        }
        if (pos.val1<lignes-2){
            opptions[1]=T_F_laby[pos.val1+2][pos.val2]; 
        }else{ 
            opptions[1]=0; 
        }
        if (pos.val2>1){
            opptions[2]=T_F_laby[pos.val1][pos.val2-2]; 
        }else{
            opptions[2]=0; 
        }
        if (pos.val2<colonnes-2){
            opptions[3]=T_F_laby[pos.val1][pos.val2+2];
        }else{
            opptions[3]=0;
        }
        
        if (T_F_count_opptions(opptions)==0){
            tmp=recuperation(chemin);
            //printf("recup : %d %d\n\n\n", tmp->val1, tmp->val2);
            pos.val1=tmp->val1; 
            pos.val2=tmp->val2; 
        }else{
        if (T_F_count_opptions(opptions)>1){
            insere(chemin,pos);
            
        }
        vei_count=0; 
        vei= rand()%T_F_count_opptions(opptions);
        for (int i=0; i<4; i++){

            if (opptions[i]==1){
                 
            if (vei==vei_count){ 
            switch (i){
                            case 0: 
                            laby[pos.val1-1][pos.val2]=vide; 
                            pos.val1=pos.val1-2;
                            break; 
                            case 1:
                            laby[pos.val1+1][pos.val2]=vide; 
                            pos.val1=pos.val1+2;  
                            break; 
                            case 2:
                            laby[pos.val1][pos.val2-1]=vide; 
                            pos.val2=pos.val2-2; 
                            break; 
                            case 3:
                            laby[pos.val1][pos.val2+1]=vide; 
                            pos.val2=pos.val2+2; 
                            break; 
            }
                break; 
        }
        vei_count++;  
        }     
    } 
  }
    printlaby(lignes,colonnes,laby);
}

    laby[1][0]=vide; 
    laby[lignes-2][colonnes-1]=vide; 

}










void parselaby(int lignes, int colonnes, Case laby[][colonnes])
{
				int i;
				int j;
				FILE * fd=fopen(LABY_FILE,"r");

				for (i=0;i<lignes;i++) {
				for (j=0;j<lignes;j++) {
				fscanf(fd,"%d",(int *)&laby[i][j]);
				}
				}
}

				// completer le code des autres fonctions 

int count_opptions(Case opptions[]){
    int i=0;
    int k;  
    for (k=0;k<4;k++){
        if (opptions[k]==vide){
            i++;
        }
    }
    return i; 
}


void resolution(int lin, int col, Case laby[][col]){

				struct pile * chemin_cur;
				chemin_cur = malloc(sizeof(struct pile)); 
				cree_vide(chemin_cur);
				struct T_pair start={1,1};

				struct T_pair pos= start;
				Case opptions[4];  
				insere(chemin_cur,pos); 
				laby[1][0]=visite; 
				struct T_pair * tmp; 

				while (pos.val1 < lin-2 || pos.val2 < col-1){ 	
								laby[pos.val1][pos.val2]=visite; 
								//printf("%d %d\n", pos.val1, pos.val2);

								opptions[0]=laby[pos.val1-1][pos.val2]; 
								opptions[1]=laby[pos.val1+1][pos.val2]; 
								opptions[2]=laby[pos.val1][pos.val2-1]; 
								opptions[3]=laby[pos.val1][pos.val2+1];

								//printf("%d\n", count_opptions(opptions));
								if (count_opptions(opptions)==0){
												tmp=recuperation(chemin_cur);
												//printf("recup : %d %d\n\n\n", tmp->val1, tmp->val2);
												pos.val1=tmp->val1; 
												pos.val2=tmp->val2; 

								}else{
								if (count_opptions(opptions)>1){
												insere(chemin_cur,pos); 
								}
								for (int i=0; i<4; i++){
												if (opptions[i]==vide){
												switch (i){
																case 0:
																pos.val1=pos.val1-1; 
																break; 
																case 1:
																pos.val1=pos.val1+1; 
																break; 
																case 2:
																pos.val2=pos.val2-1; 
																break; 
																case 3:
																pos.val2=pos.val2+1; 
																break; 
												}
								break; 
								} 
				}
				}
				laby[pos.val1][pos.val2]=visite;
				printlaby(lin,col,laby); 
				//lineup(lin); 
				}
				lineup(-lin); 
				destruction(chemin_cur); 


}























