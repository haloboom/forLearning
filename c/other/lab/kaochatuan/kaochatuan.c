#include<stdio.h>
int main()
{
int i ,j ,k;
int price=0,people=0;
for(i=1;i<=9;i++)
  for(j=1;j<=18;j++)
    for(k=1;k<=36;k++)
    {
      price=400*i+200*j+50*k;
      people=i+j+k;
      if(price>3600||people>36) break;
      else if(price==3600&&people==36)
      {
        printf("领导:%d,副领导:%d,司机:%d\n",i,j,k);
        return 1;
      }
      else continue;
    }
return 0;
}
