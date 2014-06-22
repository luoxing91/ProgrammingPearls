#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

int comlen(char*p,char *q){
  int i=0;
  while(*p && (*p++ == *q++))
    i++;
  return i;
}
int pstrcmp(const void *p,const void * q){
  return strcmp(*(char* const *)p,*(char* const * )q);
}
int main(){
  using namespace std;
  char c[80];
  char* a[80];
  const char* j="banana";
  int n =strlen(j);
  //  cout<<n<<endl;
  const char* k;
  int i=0;
  strcpy(c,j);
  for( i=0;i<=n;i++){
    //c[i]=*k;
    a[i]=c+i;
    //    cout<<a<<"["<<i<<"]:"<<a[i]<<endl;
  }
  //  c[i]=0;
  qsort(a,n,sizeof(char*),pstrcmp);
  int maxlen=0;
  int maxi=0;
  for(int i=0;i<n;i++){
    if(comlen(a[i],a[i+1])>maxlen){
      maxlen=comlen(a[i],a[i+1]);
      maxi=i;
    }
  }

  // cout<<maxlen<<a[maxi]<<endl;

  printf("%.*s\n",maxlen,a[maxi]);
}
