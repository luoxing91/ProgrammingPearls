#include <iostream>  //NOLINT
void rotate(char* var, size_t frontSize, size_t size) {
    if ( var == NULL || size <= frontSize) {
        return ;
    }
    char* front = (char*) calloc(frontSize, sizeof(char));
    memmove(front, var, frontSize);
    memmove(var, var + frontSize, size - frontSize);
    memmove(var+( size- frontSize), front, frontSize);
    free(front);
}

void rotate1(char *array, size_t frontSize, size_t size) {
    if ( var == NULL || size <= frontSize) {
        return ;
    }

    reverse(array, frontSize);
    reverse(array + frontSize, size - frontSize);
    reverse(array, size);
}

