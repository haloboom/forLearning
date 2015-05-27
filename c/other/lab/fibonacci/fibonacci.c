#include<stdio.h>
#define MODE 10007
int f(int n)
{
  int i,fn,fn_1=1,fn_2=1;
  if(n<3) return 1;
  else
  {
    for(i=3;i<=n;i++)
    {
      fn_1%=MODE;
      fn_2%=MODE;
      fn=fn_1+fn_2;
      fn%=MODE;
      fn_2=fn_1;
      fn_1=fn;
    }
  }
  return fn;
}
int main()
{
  int mathematics,n;
  scanf("%d",&n);
  mathematics=f(n);
  printf("%d",mathematics);
  return 1;
}

