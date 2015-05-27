#include<stdio.h>
#include<string.h>
#define LEN 50
void f(char *arr)
{
  int exit,k=0,i,j,n=strlen(arr);
  char tmparr[LEN]={'0'};
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      if(arr[i]==tmparr[j])
      {
        exit=1;
        break;
      }
    if(exit==0)
      tmparr[k++]=arr[i];
    exit=0;
  }
  strcpy(arr,tmparr);
}
void draw(char *full,int n)
{
  int i;
  for(i=0;i<n;i++)
    full[i]=' ';
  full[i]='\0';
}
void handle(char *arr)
{
  int i,j,k,n=strlen(arr);
  char full[LEN];
  for(i=0;i<n;i++)
  {
    for(j=n-1-i;j>=0;j--)
    {
      printf("%c",arr[n-1-j]);
    }
    draw(full,i);
    printf("%s\n",full);
  }
}
int main()
{
  char str[]="aaabbbcccddddd";
  f(str);
  handle(str);
return 1;
}
