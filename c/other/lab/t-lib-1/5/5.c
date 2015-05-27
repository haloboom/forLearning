#include<stdio.h>
int main()
{
  long a,b,c;
  int cnt=0;
  scanf("%ld",&c);
  for(a=3;a<c;a+=3)
    for(b=4;b<c;b+=4)
    {
      if((a*a + b*b) == c*c)
        cnt++;
    }
  printf("%d\n",cnt);
  return 0;
}
