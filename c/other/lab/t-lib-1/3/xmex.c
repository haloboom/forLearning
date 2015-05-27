#include	<stdio.h>
#include	<math.h>
#define DOT 1000000
int main()
{
	double i=2.5,n=2.6;
	for(;i<n;i+=1.0/DOT)
		{
			if(pow(i,i)>=10&&pow(i,i)<=10.000017)
				printf("i=%lf,i^i=%lf\n",i,pow(i,i));
		}
	return 0;
}