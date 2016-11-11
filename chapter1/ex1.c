/* Problem 1 */
/* Using built-in sort */

#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b){
    return (* (int*)a - *(int*)b);
}


