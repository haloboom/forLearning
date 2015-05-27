#include<stdio.h>
#define N 64
int f()
{
  int tip1,top2,top3,cnt=0;
  int arr1[64],arr2[64],arr3[64];
  for(tip1=0;tip1<N;top1++)
  {
    arr1[tip1]=top1+1;
    arr2[tip1]=0
    arr3[tip1]=0;
  }
  top1=top2=top3=0;
  while(top2<N && top3<N)
  {
    if(!top2)
      arr2[top2++]==arr1[tip1++];
    else if(!top3)
      arr3[top3++]=arr1[tip1++];
    else
    {
      
    }
    cnt++;
  }

  return cnt;
}

