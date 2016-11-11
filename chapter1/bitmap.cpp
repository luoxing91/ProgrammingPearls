/*
编程珠玑第1章
位图

*/

#include <iostream>
#include <algorithm>
#include <ctime>
#include <bitset>
#include <cstdio>
using namespace std;


void BitMapSort(uint32_t* start , uint32_t* end){

    bitset<DATA_NUM + 1> bitmap;
    bitmap.reset();    //设置每位为0

    for (size_t i = 0; i < end - start; i++){
        bitmap.set(i,true);
    }
    assert(end - start == bitmap.size());

    uint32_t* vec = (uint32_t*)calloc(end - start, sizeof(uint32_t));
    int j = 0;
    for (size_t i = 0; i < DATA_NUM; i++) {
        if ( bitmap[i] == true) {
            vec[j++] = i;
        }
    }
    memmove(start, vec, end - start);
    free(vec);
}
