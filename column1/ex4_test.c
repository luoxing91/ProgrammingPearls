#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "defs.h"

int main()
{
	KNUTH_INIT;
	srand(time(NULL));
	KNUTH( 10, MAX,
	       printf("%d\n", knuth_i));

	int i;
	for(i = 0; i < 10; ++i) {
		KNUTH( 2, 10,
		       printf("%d(%d)\n", knuth_i, knuth_select));
	}

	TIMER_INIT;

	TIMER( "generate 100 KNUTH number under 1k", 1,
	       KNUTH(100, 1000,));
	TIMER( "generate 100 KNUTH number under 10k", 1,
	       KNUTH(100, 10000,));
	TIMER( "generate 100 KNUTH number under 100k", 1,
	       KNUTH(100, 100000,));		
	TIMER( "generate 100 KNUTH number under 1m", 1,
	       KNUTH(100, 1000000,) );

	TIMER( "generate 100 KNUTH number under 10m", 1,
	       KNUTH(100, 10000000,) );


	int vector[1000];
	genshuf(10, 1000, vector);
	TIMER( "generate shuffle", 1,
	       for(i = 0; i < 10; ++i)
		       printf("%d\n", vector[i]););
	return 0;
}
