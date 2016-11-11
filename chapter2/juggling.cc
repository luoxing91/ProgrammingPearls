#include <iostream>  //NOLINT
using std::cout;
using std::endl;

int gcd(int m, int n) {
    if (m < n) {
        return gcd(n, m);
    }
    assert(m >= n);
    while (n) {
        int temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}

void rotate(char *array, int n, int k) {
  int num_gcd = gcd(n, k);
  for (int i = 0; i < num_gcd; ++i) {
    char temp = array[i];
    int prev = i;
    int next;
    while (true) {
      next = prev + k;
      if (next >= n) {
        next -= n;
      }
      if (next == i) {
        break;
      }
      array[prev] = array[next];
      prev = next;
    }
    array[prev] = temp;
  }
}

