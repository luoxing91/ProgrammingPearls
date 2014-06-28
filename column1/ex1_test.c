#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int main()
{
	int a[] = {2, 3, 1, 10, 0};
	pr_ints(a, 5);
	qsort(a, 5, sizeof(int), compare);
	pr_ints(a, 5);
	return 0;
}
	
