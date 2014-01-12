#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 1000000

using namespace std;

int bigrand()
{
    srand((unsigned)time(0));
    int max = N;
    return rand()%max;
}
void genknuth(int m, int n)
{
    for(int t = 0; t < n; t++)
    {
        if((bigrand() % (n-t)) < m)
        {
            cout << t << "\n";
            m--;
        }
    }
}

int main()
{
    int m = 2;
    int n = 5;
    genknuth(m,n);
    return 0;
}