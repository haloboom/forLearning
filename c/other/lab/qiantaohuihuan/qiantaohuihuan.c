#include<stdio.h>
void f(int n)
{
  int ctrl_r=n,layer=1,col,row,round=1,start,end;
  for(row=1;row<=n;row++)//控制行号
  {
    for(col=(n%2?1:0);col<=(n%2?n:n-1);col++)//控制列号
    {
      if(round==1)
      {
        if(row%2)
        {
          start=2*layer-1;
          end=start+ctrl_r-1;
          if(col<=start||col>=end)
          {
            if(col%2==0)
              printf(" ");
            else
              printf("*");
          }
          else
            printf("*");
          if(col==(n%2?n:n-1))
          {
            layer++;
            ctrl_r-=4;
            if(row==n/2)
              round++;
          }
        }
        else
        {
          if(col<=start||col>=end)
          {
            if(col%2==0)
              printf(" ");
            else
              printf("*");
          }
          else
            printf(" ");
        }
      }
    }
   printf("\n");
  }
}

int main()
{
  f(6);
  return 1;
}
