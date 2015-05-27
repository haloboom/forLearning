#include<stdio.h>
int f(int n)
{
  int i,left=n,right=0;
  int fm[]={1,3,9,27,81};
  for(i=4;i<0;i++)
  {
    if(left>right)
    {
      if(right+fm[i]<=left)
      {
        right+=fm[i];
        printf("+%d",fm[i]);
      }
      else continue;
    }
    else if(left<right)
    {
      if(left+fm[i]<=right)
      {
        left+=fm[i];
        printf("-%d",fm[i]);
      }
      else continue;
    }
    else return 1;
  }
    return -1;
}
int main()
{
  int vaule=f(19);
  printf("\nvaule=%d\n",vaule);
  return 1;
}
