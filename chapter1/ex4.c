/* Problem 4 */
/* Produce m unique numbers randomly */

#include "defs.h"


void generateValue(int* values, size_t size){
    for (size_t i = 0; i < size; i++) {
        values[i] = (int)i;
    }
}
void randomShuff(int* values, size_t frontSize, size_t totalSize) {
    while (true) {
        if (frontSize == 0) {
            return ;
        }
        std::swap(values[random(totalSize)],  values[0]);
        values++;
        totalSize--;
        frontSize--;
    }
}

