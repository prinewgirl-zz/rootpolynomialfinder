/*
 * main.c
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
#include <string.h>

#include "laguerre.h"
#include "deflation.h"

#define TOL 1.0e-13


int main(int argc, char **argv)
{
	
	FILE *fp;
	
	int n,N,i,j;
	double temp1,temp2;
	double complex *poly;
	double complex roots;
	char *buffer;
	char *token;
	const char sep[2] = " ";
    
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "Error opening file \n");
		return -1;
	}
	

    
    size_t bufsize = 64;
    size_t characters;
	buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
		fprintf(stderr, "Unable to allocate buffer\n");
        return -1;
    }
    
   
    
    
    if (getline(&buffer,&bufsize,fp) != EOF){
		token = strtok(buffer, sep);	
		n = atoi(buffer); 
		
		poly = malloc ((n+1) * sizeof (double complex));
	}
	
	j = 0;
	while(getline(&buffer,&bufsize,fp) != EOF)
		{
			
			temp1 = atof(strtok(buffer, sep));	
			temp2 = atof(strtok(NULL, sep));  
			poly[j] =  temp1 + temp2*I;
			//printf("Numero mesmo %.13f %+.13fi \n",creal(poly[j]), cimag(poly[j])); 
			j++;
			

			}

	//double complex pol[] = {-2.0 + 0.0I,0.0+0.0I,1.0+0.0I};
	//poly = pol;
	
	//roots = malloc (n * sizeof (double complex));
	printf("Root(s):\n");
	
	N = n;
	for(i=0;i<N;i++) {
		roots = laguerre(poly,n,TOL);
		printf("%.12f %+.12fi \n",creal(roots), cimag(roots)); 
		poly = deflate(roots,poly,n);
		n--;

	}
	
	return 0;
}

