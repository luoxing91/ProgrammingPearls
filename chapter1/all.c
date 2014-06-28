#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000000
#define CNT 1000000b


/* Ex4 */
#define TIMER_INIT			   \
	clock_t starttime, endtime;	   
	
#define TIMER(process)						\
	starttime = clock();						\
	process								\
	endtime = clock() ;						\
	printf("%lu %lu\n",					\
		endtime, starttime

void set1(int pos, char* vector)		/* set the position to 1 */
{
	vector[pos/8] |= (0x1 << pos%8);
}


int main()
{
	/* use qsort first */
	int i;
	TIMER_INIT;
	char vector2[CNT/8 + 1];
	starttime = clock();
	for(i = 0; i < CNT; ++i)
			set1(rand() % MAX, vector2);
	endtime = clock();
	printf("%lu %lu\n", endtime, starttime);

			
		
}
