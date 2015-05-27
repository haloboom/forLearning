#include <stdio.h>
//#include "bubble.c"
#include "cal.c"
int main()
{
  //buble.c_test
  /*int arr[]={3,4,2,1,5,9,0};
  bubble(arr,sizeof(arr)/sizeof(arr[0]),0);
  printf("int size:%d\tshort size:%d\tlong size:%d\n",sizeof(int),sizeof(short),sizeof(long));
  int i,m=sizeof(arr)/sizeof(arr[0]);
  printf("now:%d\n",arr);
  for(i=0;i<m;i++)
  {
    printf(
        "ADDR:%d-->%d\t",arr+i,arr[i]);
  }
  printf("\n");
  */
  //cal.c_test
  
  printf("Input Y/D:");
  int year,day;
  scanf("%d/%d",&year,&day);
	printf("year:%d,day:%d\n",year,day);
  cal(year,day);

  return 0;
}

