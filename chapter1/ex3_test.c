#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int main()
{
	int unsorted[MAX];
	genshuf(CNT, MAX, unsorted);

	/* /\* use qsort first *\/ */
	/* int vector1[CNT]; */
	/* int i; */

	/* TIMER_INIT; */
	
	/* TIMER(  "Init the vector", 1, */
	/* 	for(i = 0; i < CNT; ++i) */
	/* 		vector1[i] = unsorted[i]); */

	/* TIMER(  "Quicksort", 1, */
	/* 	qsort(vector1, CNT, sizeof(int), compare)); */

	/* char vector2[MAX/8 + 1]; */

	/* TIMER(  "Init the Bitvector", 1, */
	/* 	clean(vector2, CNT/8)); */
	
	/* TIMER( "bitsort", 1, */
	/* 	for(i = 0; i < CNT; ++i) */
	/* 		set1(unsorted[i], vector2)); */
	/* return 0; */

}
