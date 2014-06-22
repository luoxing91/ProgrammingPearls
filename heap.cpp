#include<algorithm>
using namespace std;
template<typename T>
class priqueue{

 public:
  priqueue(int m){
    maxsize=m;
    x = new T[maxsize+1];
    n=0;
  }
  void insert(T t){
  //pre #S < maxsize
  //post S = original S \uniset {t}
    if(n>=maxsize){
      //      exit(0);
    }
    x[++n]=t;
    int p;
    for(int i=n;i>1&&x[p=i/2]>x[i];i=p)
      swap(p,i);
  }
  T extractmin(){
    if(n <1) // exit(0);
    T t =x[1];
    x[1]=x[n--];
    //    siftdown(n);
    int i,c;
    for(i=1;(c=2*i)<=n;i=c){
      if(c+1<=n && x[c+1]<x[c])
        c++;
      if(x[i]<x[c])
        break;
      swap(c,i);
    }
    return t;
  }
 private:
  int n;
  int maxsize;
  T* x;
  void swap(int i, int j){
    std::swap(x[i],x[j]);
  }
      
};
void siftup(int n){
  //  pre n> 0 && heap(1,n-1)
  // post
  int i =n;
  while(true){
    // invariant: heap(1,n) except perhaps i-th or its parent
    if(i=1) break;
    int p=i-1/2;
    if(x[p]<=x[i]) break;
    swap(p,i);
    i=p;
  }
         
}
void siftdown(int n){
  // pre heap(2,n) && n>=0
  //post heap(1,n)
  int i=1;
  while(true){
    //
    int child = 2* i;
    if(child >n) break;
    if(child+1 <=n){
      if(x[child+1]<x[child])
        child++;
    }
    if(x[i]<=x[child])break;
    swap(child,i);
    i=child;                       
  }
}
