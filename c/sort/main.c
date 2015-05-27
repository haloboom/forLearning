#include <stdio.h>
#define LEN 10
#define DEFAULT "quicksort.c"
/*(quicksort/bubble...)*/
#define HDR "quicksort.c"
#include HDR
void display(int *arry)
{
  short i;
 for(i=0;i<LEN-1;i++)
   printf("%d,",arry[i]);
 printf("%d\n",arry[LEN-1]);
}

int main()
{
int arry[LEN]={3,7,0,5,2,6,1,8,4,9};
printf("Now:");
display(arry);
quicksort(arry,0,LEN-1);
printf("Then:");
display(arry);
return 0;
}

