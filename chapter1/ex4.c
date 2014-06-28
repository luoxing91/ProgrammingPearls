/* Problem 4 */
/* Produce m unique numbers randomly */

#include "defs.h"

void genshuf(int m, int n, int * vector)
{
	int i, j, t;
	for(i = 0; i < n; i++)
		vector[i] = i;
	for(i = 0; i < m; i++) {
		j = rand() % n;
		t = vector[i];
		vector[i] = vector[j];
		vector[j] = t;
	}
}
	
	
