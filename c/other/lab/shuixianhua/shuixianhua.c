#include<stdio.h>
#include<math.h>
#include<string.h>
#define LEN 21
int countni(char *arr)
{
  int i,cnt=0;
  for(i=0;i<LEN+1;i++)
    if(arr[i]=='9')
      cnt++;
  return cnt;
}
int numplus(char *arr)
{
 if(strcmp("999999999000000000000",arr)>0)
 {
  int i;
  for(i=LEN-1;i>0;i--)
  {
    arr[i-1]+=(arr[i]=='9')?1:0;
    arr[i-1]-='0';
    arr[i-1]%=10;
    arr[i-1]+='0';
  }
  arr[20]+=1;
  arr[20]-='0';
  arr[20]%=10;
  arr[20]+='0';
  return 1;
 }
 else
 {
   return 0;
 }
 return -1;
}
double sum(char *arr)
{
  int i;
  double sum=0;
  for(i=0;i<LEN;i++)
  {
    sum+=pow((arr[i]-'0'),21);
  }
  return sum;
}
int judge(char *arr)
{
  int n=countni(arr);
  if(arr[0]=='1')
    if(n<=9)
      return 1;
    else return 0;
  else
  switch(arr[1]-'0')
  {
    case 1:return n>1?0:1;
    case 2:return n>2?0:1;
    case 3:return n>3?0:1;
    case 4:return n>4?0:1;
    case 5:return n>5?0:1;
    case 6:return n>6?0:1;
    case 7:return n>7?0:1;
    case 8:return n>8?0:1;
    case 9:return n>9?0:1;
    defaults:return 0;
  }
  return -1;
}
int main()
{
  char num[LEN+1]="010000000000000000000";

  do{
   if(judge(num))
    {
      double s=sum(num);
      char arr[LEN+1];
      sprintf(arr,"%21.0lf",s);
      if(strcmp(num,arr)==0)
        printf("num:%s\n",num);
    }
   else
     continue;
  }while(numplus(num));

  return 1;
}
