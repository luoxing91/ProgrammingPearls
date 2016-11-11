/*
file name: priqueue_ternary.cpp
purpose:
	书中的“优先级队列”是基于“完全二叉树”，请基于“完全三叉树”来实现“优先级队列”。
creator: guangwei jiang
create time: 2012-08-14

modify history:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <set>


using namespace std;

// notes: bigrand should at least 64bits
unsigned long long bigrand()
{
	return RAND_MAX*rand() + rand();
}

template<class T>
class priqueue_ternary {
private:
	int n, maxsize;
	T *x;
public:
	priqueue_ternary (int m)
	{
		maxsize = m;
		x = new T[maxsize+1];
		n = 0;
	}
	void insert (T t)
	{
		int i, p;
		x[++n] = t;
		for (i = n; i > 1 && x[p=(i+1)/3] > x[i]; i = p)
		{
			swap(p, i);
		}
	}
	T extractmin() {

		// 1st step, get the min value x[1];
		T t = x[0];
                --n;
		// 2nd step, assign another value(x[n]) to x[1], and n descrease 1;
		x[0] = x[n];
		// 3rd step, re-sort the heap
                int i = 0;
                while(true) {
                    int left = 3*i+1;
                    int mid = 3*i+2;
                    int right = 3*i+3;
                    int min = i;
                    if (left < n && x[left] < x[min]) {
                        min = left;
                    }
                    if (mid < n && x[mid] < x[min]) {
                        min = mid;
                    }
                    if (right < n && x[right] < x[min]) {
                        min = right;
                    }
                    if ( min == i || (left >= n && right >= n && mid >= n )) {
                        break;
                    }
                    i = min;
                }
		return t;
	}
};

template<class T>
void pqsort (T v[], int n)
{
	priqueue_ternary<T> pq(n);
	int i;

	for (i = 0; i < n; i++)
	{
		pq.insert(v[i]);
	}
	for (i = 0; i < n; i++)
	{
		v[i] = pq.extractmin();
	}
}


