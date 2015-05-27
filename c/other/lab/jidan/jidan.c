#include<stdio.h>
int main()
{
 int i;
 for(i=1;i<150;i++)
   if((1.0*32/(150-i))*i == (24.5/i)*(150-i))
     printf("1.%d,2.%d\n",i,150-i);
 return 0;
}
