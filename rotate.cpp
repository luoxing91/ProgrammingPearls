#include<iostream>
#include<vector>
using namespace std;
void printVector(const vector<int>& vec){
  vector<int>::iterator it= vec.begin();
  while(it!=vec.end()){
    cout<< *it << ' ';
    ++it;
  }
  cout<< endl;
}
int gcd(int a, int b){
  if(b==0)
    return a;
  else
    return gcd(b,a%b);
}
void reverseVec(vector<int>& vec,int i, int n){
  reverse(vec.begin()+i,vec.begin()+n+1);
}
void rotate(vector<int>& vec, int i , int n){
  reverseVec(vec,0,i-1);
  reverseVec(vec,i,n-1);
  reverseVec(vec,0,n-1);
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
