#include <stdio.h>
#include "getbits.c"
#include "setbits.c"
#include "invertbits.c"
unsigned getbits(unsigned x,int p,int n);
unsigned setbits(unsigned x,int p,int n,unsigned y);
unsigned invertbits(unsigned x,int p,int n);
int main()
{
  unsigned x=255,y=128;
  printf("...:%d\n",setbits(x,6,7,y));
  return 0;
}
