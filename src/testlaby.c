// votre code ici

#define LINE 101
#define COL 101


#include "laby.h"
#include "labyaff.h"


int main(){
    Case laby[LINE][COL];
    while (1){
    gen_laby(LINE,COL,laby);
    printlaby(LINE,COL,laby);

   // lineup(21); 
    //parselaby(21,21,laby); 
    

     resolution(LINE,COL,laby); 
}
}
