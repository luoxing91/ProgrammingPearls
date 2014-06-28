#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIT     8
#define SHIFT   3
#define MASK    0x07

#define N	10000000

typedef  unsigned char	__u8;
typedef  unsigned int	__u32;

unsigned char *p;

void clr(){
  memset(p, 0, N/BIT);
}

void set(__u32 i){
  *(p+(i>>3))|=(1<<(i & MASK));
}

__u8 test(__u32 i){
  return (*(p+(i>>3)) & (1<<(i & MASK)));
}

int main(void){
  p=(__u8 *)malloc(N/BIT);
 
  FILE *fp;
  fp = fopen("file.txt", "r");

  int i;
  
  clr();
  
  while (fscanf(fp, "%d", &i) != EOF)
    set(i);
   
  for(i = 0; i < N; i++){
    if (test(i))
      printf("%d\t", i);
  }
  
  fclose(fp);
  free(p);
  return 0;
}
