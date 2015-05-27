#include<stdio.h>
#define AS 0b1111111111
int main()
{
  int i,j,h,k,n;
  for(i=AS;i>0;i--)
  {
    n=10;
    k=i;
    for(j=1;j<=10;j++)
    {
      h = k&0b1000000000;
      n = (h!=0)?n*2:n-j;
      k <<= 1;
    }
    if(n==100)
      printf("i:%d\n",i);
  }
  return 0;
}
