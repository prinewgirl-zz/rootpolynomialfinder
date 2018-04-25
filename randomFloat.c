#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <time.h>
#include "randomFloat.h"

double complex randomFloat (double complex low, double complex high)
{
	// This code was inspirated in randomlib
    // written by Eric Roberts.
    
    double complex k;
    double complex d;
    srand(time(NULL));
    d = (double complex) rand () / ((double complex) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}


