#define RADIUS 1


/*------------------------------------------------------------------*/
/* simPi        Computes pi with the Monte Carlo                    */
/*                                                                  */
/* Parameters : nbPoints An integer                                 */
/*                                                                  */
/* Return : A pi approximation , double                             */
/*------------------------------------------------------------------*/

double simPi(int);

/*------------------------------------------------------------------*/
/* launchingPi                                                      */
/* Computes independent experiments of pi to obtain a mean          */
/*                                                                  */
/* Parameters : points An integer                                   */
/*                                                                  */
/* Return : void                                                    */
/*------------------------------------------------------------------*/
void launchingPi(int);


/*------------------------------------------------------------------*/
/* confidenceInterval                                               */
/* Computes the confidence interval around the simulated mean       */
/*                                                                  */
/* Parameters : n,points 2 integers                                 */
/*                                                                  */
/* Return : void                                                    */
/*------------------------------------------------------------------*/
void confidenceInterval(int,int);