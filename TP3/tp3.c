#include "mt19937ar.c"
#include "mt19937ar.h"
#include "tp3.h"
#include <math.h>


double simPi(int nbPoints)
{
    double  x_r,y_r;
    int     RADIUS = 1,inside_circle = 0,i;

    for(i=0; i<nbPoints; i++)
    {
        x_r = genrand_real1();
        y_r = genrand_real1();
        if(pow(x_r,2) + pow(y_r,2) < pow(RADIUS,2))
        {
            inside_circle ++;//Number of points inside the circle
        }
    }
    return 4*(double)inside_circle/nbPoints;
}


void launchingPi(int points)
{   
    int     i,n=10;
    double  T[n],meanPI=0,r_error,a_error;

    for(i=0; i<n; i++){
        T[i] = simPi(points);
        meanPI += T[i];
    }
    meanPI = meanPI/n;
    a_error = meanPI - M_PI;
    r_error = a_error/M_PI;
    printf("Pour %d expériences avec %d points : \n",n,points);
    printf("Mean : %lf\n",meanPI);
    printf("Erreur absolue : %lf\nErreur relative : %lf\n",a_error,r_error);
}

void confidenceInterval(int n,int points)
{

    int     i;
    double  tab[n],R,S2,sum=0,mean,T[21]={2.228,2.201,2.179,2.160,2.145,2.131,2.120,2.110,2.101,2.093,2.086,2.080,2.074,2.069,2.064,2.056,2.052,2.048,2.045,2.042};

    for(i=0; i<n; i++)
    {   
        tab[i] = simPi(points);
        mean += tab[i];
    }
    mean = mean/n;
    for(i=0; i<n; i++)
    {
        sum += pow(tab[i]-mean,2);
    }

    S2 = sum/(n-1);
    R = T[n-10]*sqrt(S2/n);
    printf("Intervalle : [%lf : %lf]\n", mean -R, mean +R);

}

int main(void)
{
    /*
    1)
    printf("%lf",simPi(1000)); //3.
    printf("%lf",simPi(4000));//3.14
    printf("%lf",simPi(1000000));//3.141 
    
    2)
    launchingPi(1000);
    launchingPi(1000000);
    
    3)*/
    confidenceInterval(20,1000);
}