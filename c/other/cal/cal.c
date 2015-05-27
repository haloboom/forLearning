#define MLEN 12

short isleap(int year)
{
  return (year%400==0||(year%100!=0 && year%4==0))?29:28;
}
void cal(int year,int day)
{
  short date[MLEN]={31,isleap(year),31,30,31,30,31,31,30,31,30,31};
	short i;
	int sum=0;
	
  if(day>=31)
  {
    for(i=1,sum=date[0];day>sum;i++)
      sum+=date[i];
  printf("M:%d/D:%d\n",i,date[i-1]-(sum-day));
  }

  else
  {
    int m;
    short count=3;
    printf("input Month:");
    scanf("%d",&m);
    while(count--&&m==2)
    {
      printf("Error,enter again:");
      scanf("%d",&m);
    }
    m--;
    while(--m>=0)
      sum+=date[m];
    sum+=day;
    printf("The day is the %d days\n",sum);
  }
}
