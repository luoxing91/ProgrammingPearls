/*
file name: priqueue.cpp
purpose:
	优先级队列：
	堆通过插入新元素和提取最小元素这两种操作来维护元素集合，每个操作所需的时间都为O(log n)。
create time: 2012-08-14

modify history:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <set>

#define DEBUG		0
using namespace std;


template<class T>
class priqueue {
private:
    size_t n;
    size_t maxsize;
    T *x;
public:
    priqueue (int m){
        maxsize = m;
        x = new T[maxsize];
        n = 0;
    }
    void insert (const T& t){
        int i, p;
        ++n;
        assert(n <= maxsize);
        x[n] = t;
        for (int i = n; i >= 1 && x[p = i/2] > x[i]; i = p){
            std::swap(x[p], x[i]);
        }
    }
    T extractmin(){
        T t = x[0];
        --n;
        x[0] = x[n];
        size_t i = 0;
        while(true) {
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;
            size_t min = i;
            if (left < n && x[left] < x[min]) {
                min = left;
            }
            if (right < n && x[right] < x[min]) {
                min = right;
            }
            if ((left >= n && right >= n) || (min == i)) {
                break;
            }
            i = min;
        }
        return t;
    }
};

template<class T>
void pqsort (T v[], int n) {
    priqueue<T> pq(n);
    int i;

    for (size_t i = 0; i < n; i++) {
        pq.insert(v[i]);
    }
    for (size_t i = 0; i < n; i++) {
        v[i] = pq.extractmin();
    }
}
