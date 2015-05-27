#include<stdio.h>
double jiecheng(int n)
{
  if(n>1)
    return n*jiecheng(n-1);
  else return 1;
}
int main()
{
  double ans;
  int n;
  printf("get n:");
  scanf("%d",&n);
  ans=jiecheng(n);
  printf("ans=%160.159e\n",ans);
  return 0;
}
