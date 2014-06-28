#include <stdio.h>
#include "defs.h"

int main()
{
	char vec[50];
	set1(5, vec);
	pr_bin(vec[0]);
	
	set1(6, vec);
	pr_bin(vec[0]);

	set0(6, vec);
	pr_bin(vec[0]);

	printf("%d\n",get(5,vec));
	printf("%d\n",get(6,vec));
	return 0;
}

