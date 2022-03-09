#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i,temp,
        adultRabbit = 0,
        youngRabbit = 2,
        N = 6;
        printf("Nombres de couples le mois 0 : 1\n");

    for(i = 0; i<N+1; i++)
    {
        temp = youngRabbit;
        youngRabbit += adultRabbit;
        adultRabbit += temp;
        youngRabbit -= temp;
        printf("Nombres de couples le mois %d : %d\n",i+1,(adultRabbit+youngRabbit)/2);
    }

}