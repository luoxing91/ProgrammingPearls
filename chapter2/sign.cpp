#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int charcmp(const void * x,const  void *y){
  return *(const char *)x-*(const char *)y;
}
int main(){
  char word[80];
  char sig[80];
  while(scanf("%s",word) !=EOF){
    strcpy(sig,word);
    qsort(sig,strlen(sig),sizeof(char),charcmp);
    printf("%s %s\n",sig,word);
  }
  return 0;
}
