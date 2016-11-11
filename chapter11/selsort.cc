#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void selSort(int *array_data, int array_size){
    if ( size <= 1) {
        return ;
    }
    for (size_t i = 1; i < size; i++) {
        if (array_data[i] > array_data[0]) {
            std::swap(array_data[0], array_data[i]);
        }
    }
    selSort(array_data + 1, size - 1);
}

