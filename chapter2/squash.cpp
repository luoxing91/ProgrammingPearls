#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(){
  char word[80];
  char sig[80];
  char oldsig[80];
  int linenum=0;
  while(scanf("%s %s",sig,word)!=EOF){
    if(strcmp(oldsig,sig)!=0 && linenum>0)
      printf("\n");
    strcpy(oldsig,sig);
    linenum++;
    printf("%s ",word);
  }
  printf("\n");
  return 0;
}
