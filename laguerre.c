/*
 * laguerre.c
 * 
 * Copyright 2018 Priscila Gutierres <priscila.gutierres@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>


#include "evalpoly.h"
#include "polyderivative.h"
#include "randomFloat.h"

#define ITMAX 10000


double complex laguerre ( double complex *a, int n, double  tol) {
	int i;
	double complex poly, fderivative, sderivative, g, h, f , dx;
	double complex *fderivativetemp;
	double complex x = randomFloat(0.0 + 0.0I,100.0 + 0.0I);
	for(i=0;i < ITMAX; i++) 
	{
		//printf("x velho: %.2f %+.2fi\n", creal(x), cimag(x));
		poly = evalpoly(x,a,n);
		fderivativetemp = polyderivative(a,n);
		fderivative = evalpoly(x,fderivativetemp,n-1);
		//printf("derivada primeira: %.2f %+.2fi\n", creal(fderivative), cimag(fderivative));
		sderivative = evalpoly(x,polyderivative(fderivativetemp, n-1),n-2);

		if (cabsf(poly) < tol)
			return x;

		g = fderivative/poly;
		h = g*g - sderivative/poly;
		f = csqrtf((n-1)*(n*h - g*g));

		if (cabsf(g+f) > cabsf(g-f))
			dx = n/(g+f);
		else
			dx = n/(g-f);
		x = x - dx;
		//printf("x novo: %.2f %+.2fi\n", creal(x), cimag(x));
		if(cabsf(dx) < tol)
			return x;
			
	}
	printf("ERROR: Too many iterations! \n");
	
	
}

