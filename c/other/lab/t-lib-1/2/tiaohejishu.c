#include	<stdio.h>
#define N 10000000
int main()
{
	int i;
	double sum=0;
	for(i=1;i<=N;i++)
	{
		sum+=1.0/i;
		if(sum>15.0)
			{
				printf("i=%d\n",i);
				break;
			}
	}
	return 0;
}