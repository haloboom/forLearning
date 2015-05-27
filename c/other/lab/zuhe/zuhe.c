#include<stdio.h>
int f(int n, int m)
{
	if(m>n) return 0;
	if(m==0) return 1;

	return f(n-1,m-1)+f(n-1,m) ;
}
int main()
{
  printf("%d\n",f(4,2));
  return 1;
}
