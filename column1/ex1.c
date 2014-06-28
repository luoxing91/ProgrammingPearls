/* Problem 1 */
/* Using built-in sort */

#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
	return (* (int*)a - *(int*)b);
}

void pr_ints (const int * a, int len)
{
	int i;
	for(i = 0; i < len; ++i)
		printf("%d\t", a[i]);
	printf("\n");
}
	

