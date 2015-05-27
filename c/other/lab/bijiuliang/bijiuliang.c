#include<stdio.h>
int main()
{
 int x,a,b,c,d;
 for(x=20;x>0;x--)
   for(a=3;a<x;a++)
     for(b=2;b<a;b++)
       for(c=1;c<b;c++)
          if(1.0*(b*c*x +a*c*x +a*b*x +a*b*c)/(a*b*c*x)==1.0)
            printf("x:%d,a:%d,b:%d,c:%d,d:%d\n",x,a,b,c,0);
 return 0;
}
