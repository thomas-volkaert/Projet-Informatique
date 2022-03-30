#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "main.h"
#include "mt19937ar.c"

typedef struct Rabbit Rabbit;
struct Rabbit{
    int age;
    char genre;
    bool adult;
    Rabbit *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Rabbit *premier;
};

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Rabbit *rabbit = malloc(sizeof(*rabbit));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }
    rabbit->age = 0;
    rabbit->genre = "F";
    rabbit->adult = FALSE;
    liste->premier = rabbit;

    return liste;
}

/*void insertion(Liste *liste, int newRabbit)
{

}*/
void simuFibonacci(int MAX)
{
    int i,temp,
        adultRabbit = 0,
        youngRabbit = 2;
    printf("Nombres de couples le mois 0 : 1\n");

    for(i = 0; i<MAX+1; i++)
    {
        temp = youngRabbit;
        youngRabbit += adultRabbit;
        adultRabbit += temp;
        youngRabbit -= temp;
        printf("Nombres de couples le mois %d : %d\n",i+1,(adultRabbit+youngRabbit)/2);
    }

}

int numberOfBornedBabies(int rabbit[]) // V
{
    double x_random = genrand_real1();
    double childbirthDeath = genrand_real1();

    if(childbirthDeath < 0.15)
    {
        rabbit[1]--;
    }
    if(x_random < 1/16)
    {
        return 3;
    }
    else if (x_random < 3/16)
    {
        return 4;
    }
    else if (x_random < 6/16)
    {
        return 5;
    }
    else if (x_random < 10/16)
    {
        return 6;
    }
    else if (x_random < 13/16)
    {
        return 7;
    }
    else if (x_random < 15/16)
    {
        return 8;
    }
    else
    {
        return 9;
    }
}


/*
int deathAge(int age) // 75% adult 50% babies -15% per year if >7yo
{

}

int babyToAdult(void)
{
    
}
*/

void babyGenre(int rabbit[]) // V
{
    double genre = genrand_real1();
    if (genre <= 0.5 )
    {
        rabbit[2]++;
    }
    else
    {
        rabbit[3]++;
    }
}



int main(void)
{
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    int i,x,
        month = 0,
        adultFemaleRabbit = 0,
        adultMaleRabbit = 0,
        babyFemaleRabbit = 1,
        babyMaleRabbit = 1,
        rabbit[][] = {adultMaleRabbit,adultFemaleRabbit,babyMaleRabbit,babyFemaleRabbit};

    
}