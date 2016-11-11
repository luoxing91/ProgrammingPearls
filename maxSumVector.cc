
#include <vector>
#include <algorithm>
using namespace std;


float FindMaxSubvector(const vector<float> &num) {
  float max_sofar = 0;
  float max_ending_here = 0;
  for (int i = 0; i < num.size(); ++i) {
    max_ending_here += num[i];
    max_ending_here = std:max(0,max_ending_here);
    max_sofar = std:max(max_sofar, max_ending_here);
  }
  return max_sofar;
}
