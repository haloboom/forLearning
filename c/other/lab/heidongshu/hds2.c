#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include"hds2.h"
#define BASE 12345//基数
#define TL 16//循环圈的最大长度
#define CT 20//测试次数
int main()
{
  int i,x,y,base=BASE;
  HDS hds[TL];//公用一个空间
  for (i=0;i<CT;i++) 
  {
    init_hds(hds+0,base,i);
    handle(hds);
    getxy(hds,&x,&y);
    printf("%d:",i);
    display_hds(hds,x,y);
  }
  return 0;
}
void handle(HDS hds[])//对结构数组做陷阱处理
{
  int i=0,max,min;
  char str[10];
  do {
    strcpy(str,hds[i].n);
    max=alptoint(bubble_nx(str));
    min=alptoint(bubble_zx(str));
    hds[++i].N=max-min;
    sprintf(hds[i].n,"%d",hds[i].N);
  } while (i<TL);
}
void getxy(HDS hds[],int *x,int *y)//获取陷阱的始末位置
{
  for(*x=0;*x<TL-1;(*x)++)
    for (*y=*x+1;*y<TL;(*y)++)
      if(hds[*x].N==hds[*y].N)
      {
        return ;
      }
}
void init_hds(HDS *hds,int base,int i)//随机初始化五位数
{
  while(i--)
  {
   base+=i*i-24i+1234*(base/15000); 
  }
  hds->N=base;
  sprintf(hds->n,"%d",hds->N);
}
void display_hds(HDS hds[],int x,int y)//打印黑洞数陷阱
{
  int i;
  printf("x:%d y:%d\n",x,y);
  printf("[");
  for(i=x;i<y-1;i++)
  {
    printf("%d,",hds[i].N);
  }
  printf("%d]\n",hds[i].N);
}
int alptoint(char *str)
{
  int i,ans=0,n=strlen(str);
  for(i=0;i<n;i++)
    ans+=(int)(str[i]-'0')*pow(10,n-i-1);
  return ans;
}
char *bubble_zx(char str[])
{
  int i,j,n=strlen(str);
  char tmp;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
      if(str[i]>str[j])
      {
        tmp=str[i];
        str[i]=str[j];
        str[j]=tmp;
      }
    }
  return str;
}
char *bubble_nx(char str[])
{
  int i,j,n=strlen(str);
  char tmp;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
      if(str[i]<str[j])
      {
        tmp=str[i];
        str[i]=str[j];
        str[j]=tmp;
      }
    }
  return str;
}