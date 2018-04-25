/*
 * polderivative.c
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
#include "polyderivative.h"


#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "polyderivative.h"

double complex *polyderivative(double complex *a, int n) {

	int i;
	double complex *b;
	if (n == 0)
	{
		b = malloc (sizeof (double complex));
		b[0] = 0;
		return b;
	}
	b = malloc ((n) * sizeof (double complex));
	b[0] = a[1];
	
	for (i = 1;i < n; i++) {
		b[i] = a[i+1]*(i+1);
		
		
	}
	
	return b;
	}
