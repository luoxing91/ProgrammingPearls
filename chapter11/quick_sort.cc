s
#include <iostream> //NOLINT
using std::cout;
using std::endl;
#include <cstdlib>

void swap(int *array, int m, int n) {
    std::swap(array[m], array[n]);
}


void isort(int *array, size size) {
    int  j;
    for (size_t i = 1; i < size; ++i) {
        int t = array[i];
        for (j = i; j >= 0  && array[j - 1] < t; --j) {
            array[j] = array[j - 1];
        }
        array[j - 1] = t;
    }
}



