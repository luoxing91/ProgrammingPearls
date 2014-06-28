/* Problem 2 */
/* Implement bit vector using bitwise operator */

#include <stdio.h>
#include <string.h>
#include "defs.h"

void set1(int pos, char* vector)		/* set the position to 1 */
{
	vector[pos/8] |= (0x1 << pos%8);
}

void set0(int pos, char* vector)		/* set the position to 0 */
{
	vector[pos/8] &= ~(0x1 << pos%8);
}

int get(int pos, char* vector)
{
	return (vector[pos/8] & (0x1 << pos%8)) ? 1 : 0;
}
void clean(char* vector, int len)
{
	int i;
	for(i = 0; i < len; ++i)
		vector[len] = 0;
}

	
