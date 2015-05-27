#include<stdio.h>
int main()
{
  int arr[3][4];
  int i,j;
  for(i=0;i<3;i++)
    for(j=0;j<4;j++)
      arr[i][j]=i+j;
  while(--i)
  {
    j=4;
    while(--j)
      printf("arr[%d][%d]:%d ",i,j,*(*(arr+i)+j));
    printf("\n");
  }
  return 0;
}
