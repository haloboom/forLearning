#include <stdio.h>
#define MODE 7
int isleap(int year)
{
	return (!(year%4) && year%100) || !(year%400);
}
int main()
{
	int currentDay=6,startYear=1949,endYear=2012;
	int i,cnt=0;
	for(i=startYear+1;i<endYear;i++)
	{
		if(isleap(i))
			{
				currentDay+=366;
				currentDay%=MODE;
			}
			else
			{
				currentDay+=365;
				currentDay%=MODE;
			}
			if(currentDay==0) 
			{
				cnt++;
				printf("%d,",i);
			}
		}
		printf("%d\n",cnt);
	return 0;
}