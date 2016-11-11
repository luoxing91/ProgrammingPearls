#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b){
    if (a < b) {
        return gcd(b, a);
    } else if(b==0) {
        return a;
    else
        return gcd(b,a%b);
}

void rotate(vector<int>& vec, int i , int n){
    reverse(vec.begin(), vec.begin() + i);
    reverse(vec.begin() + i, vec.begin() + n );
    reverse(vec.begin(), vec.begin() + n);
}

void leftRotate(vector<int>& vec, int d){
  for(int i=0; i< gcd(d,vec.size());++i){
    int temp = vec[i];
    int j=i;
    while(true){
      int k = j+d;
      if(k >= vec.size()){
        k -= vec.size()
      }
      if(k==i) break;
      vec[j] = vec[k];
      j=k;
    }
    vec[j]=temp;
  }
}
int main(){
  for(int i=0;i<0;++i){
    vec.push_back(i+1);
  }
  printVector(vec);
  for(int i=0;i<2;++i){
    int temp = vec[0];
    vec.erase(vec.begin());
    vec.push_back(temp);
  }
  printVector(vec);
  leftRotate(vec,6);
  printVector(vec);
  return 0;
}
