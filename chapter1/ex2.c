/* Problem 2 */
/* Implement bit vector using bitwise operator */

#include <stdio.h>
#include <string.h>
#include "defs.h"

void set1(int pos, char* vector) {
    vector[pos/8] |= (0x1 << pos%8);
}

void set0(int pos, char* vector) {
    vector[pos/8] &= ~(0x1 << pos%8);
}

int get(int pos, char* vector) {
    return (vector[pos/8] & (0x1 << pos%8)) ? 1 : 0;
}

void clean(char* vector, size_t len){
    for(size_t i = 0; i < len; ++i)
        vector[i] = 0;
}

	
