#include <time.h>
#include <stdlib.h>
/* Ex1 */
void pr_ints(const int*, int);
int compare(const void*, const void*);

/* Ex2 */
#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte) \
	(byte & 0x80 ? 1 : 0), \
	(byte & 0x40 ? 1 : 0), \
	(byte & 0x20 ? 1 : 0), \
	(byte & 0x10 ? 1 : 0), \
	(byte & 0x08 ? 1 : 0), \
	(byte & 0x04 ? 1 : 0), \
	(byte & 0x02 ? 1 : 0), \
	(byte & 0x01 ? 1 : 0)
#define pr_bin(byte) \
	printf(BYTETOBINARYPATTERN "\n", BYTETOBINARY(byte))

void set1(int, char*);
void set0(int, char*);
int get(int, char*);
void clean(char*, int);

	
/* Ex3 */
#define MAX 10000000
#define CNT 1000000


#define TIMER_INIT			   \
	clock_t starttime, endtime;	   \
	int timer_times
	
#define TIMER(txt, times, process)					\
	starttime = clock();						\
	for(timer_times = 0; timer_times < times; ++timer_times) {	\
		process;						\
	}								\
	endtime = clock() ;						\
	printf("%-50s %20lu\n",						\
		txt, endtime - starttime);
	

/* Ex4 */
#define KNUTH_INIT				\
	int knuth_select, knuth_i;

/* select M elements from (0, N] */
#define KNUTH(M, N, process)						\
	knuth_select = M;						\
	for(knuth_i = 1; knuth_i <= N; ++knuth_i) { \
		if((rand() % (N + 1 - knuth_i)) < knuth_select) {	\
			process;					\
			knuth_select --;				\
		}							\
	}							
	
void genshuf(int, int, int * );
