#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void seed(){

    int i,N,N0,N1,N2;

    printf("\nEnter the seed : ");
    scanf("%d",&N0);
    printf("\nEnter N : ");
    scanf("%d",&N);
    printf("N0 = %d\n",N0);
    for(i=1; i<N; i++){
        N1 = (N0*N0)/100;
        N2 = N1%10000;
        printf("N%d = %d\n",i,N2);
        N0 = N2;
    }
}  

void probHeadTails(){

    int random,prob=0,i;
    srand( time( NULL ) );

    for(i = 0; i < 10; i++){
        random = rand()%2;
        if(random == 1){
            prob += 1;
        }
    }
    prob = (100*prob)/10;
    printf("\nprobabilite d'avoir 1 sur 10 lances= %d\n", prob );
    prob = 0;

    for(i = 0; i< 100; i++){
        random = rand()%2;
        if(random == 1){
            prob += 1;
        }
    }
    prob = (100*prob)/100;
    printf("\nprobabilite d'avoir 1 sur 100 lances = %d\n", prob);
    prob=0;

    for(i = 0; i < 1000; i++){
        random = rand()%2;
        if(random == 1){
            prob += 1;
        }
    }
    prob = (100*prob)/1000;
    printf("\nprobabilite d'avoir 1 sur 1000 lances = %d\n", prob);
    prob=0;
} 

void probDice6(){
    int random,prob=0,i,tab[6] ={0},dice ;
    srand( time( NULL ) );

    printf("Pour 100 experiences : \n");
    for(i = 0; i<100; i++){
        dice = rand()%6;
        tab[dice] += 1;
    }
    for(i=0; i<6; i++){
        printf("%d : %d\n",i+1,tab[i]);
        tab[i] = 0;
    }
    
    printf("Pour 1000 experiences : \n");
    for(i = 0; i<1000; i++){
        dice = rand()%6;
        tab[dice] += 1;
    }
    for(i=0; i<6; i++){
        printf("%d : %d\n",i+1,tab[i]);
        tab[i] = 0;
    }
} 

void probDice10(){
    int random,prob=0,i,tab[10] ={0},dice ;
    srand( time( NULL ) );

    printf("Pour 10 experiences : \n");
    for(i = 0; i<10; i++){
        dice = rand()%10;
        tab[dice] += 1;
    }
    for(i=0; i<10; i++){
        printf("%d : %d\n",i+1,tab[i]);
        tab[i] = 0;
    }

    printf("Pour 100 experiences : \n");
    for(i = 0; i<100; i++){
        dice = rand()%10;
        tab[dice] += 1;
    }
    for(i=0; i<10; i++){
        printf("%d : %d\n",i+1,tab[i]);
        tab[i] = 0;
    }
    
    printf("Pour 1000 experiences : \n");
    for(i = 0; i<1000; i++){
        dice = rand()%10;
        tab[dice] += 1;
    }
    for(i=0; i<10; i++){
        printf("%d : %d\n",i+1,tab[i]);
        tab[i] = 0;
    }

    printf("Pour 1000000 experiences : \n");
    for(i = 0; i<1000000; i++){
        dice = rand()%10;
        tab[dice] += 1;
    }
    for(i=0; i<10; i++){
        printf("%d : %d\n",i+1,tab[i]);
        tab[i] = 0;
    }
} 

int main(){
	seed();
	probHeadTails();
	probDice6();
    probDice10();
}

/*
Question 2 :

On peut voir qu'a partir de N4 une boucle apparaitre avec la seed 4100.
Par contre on remarque qu'avec la seed 1234 on converge vers 0
a partir de N56.
Or avec la seed 3141 on voit que l'on obtient 100 tout le temps a partir
de N7.

Question 3 :

Non il ne convient pas a des applications scientifique car on ne peut pas
revenir en arrière car la seed est determine avec le temps. Or il peut
convenir a des jeux d'essaies.

Question 4 :

Pour des petits tirages l'equiprobabilite entre pile et face 

Question 5 :
*/
