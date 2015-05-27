#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define LEN 5//五位十进制数
#define ALEN 100//存储可能出现的循环圈
#define TLEN 20//随机输入的数字
#define BASENUM 10000//初始五位数
int alptoint(char *str);
char *bubble_nx(char str[]);
char *bubble_zx(char str[]);
typedef struct{
  int N;//输入都数字
  char num[LEN+1];//将十进制数存储在数字里
}ELM;

int cmp(ELM *elms,int *x,int *y);
void handle(ELM **elm,int i)
{
  sprintf(elm[i]->num,"4%d",elm[i]->N);//数字转换成字符串
  int max=alptoint(bubble_nx(elm[i]->num)),min=alptoint(bubble_zx(elm[i]->num));//字符串按数字大小重组
  elm[i+1]->N=max-min;//重组后转换成数字相减
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
  for(i=0;i<n;i++)
    for(j=i+1;j<n-i;j++)
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
  for(i=0;i<n;i++)
    for(j=i+1;j<n-i;j++)
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
int cmp(ELM *elms,int *x,int *y)//得到循环圈的结尾下标
{
  int i,j;
  for(i=0;i<ALEN-1;i++)
    for(j=1;j<ALEN;j++)
      if(elms[i].N==elms[j].N)
        {
          *x=i;
          *y=j;
        }
  return 1;
}
int main()
{
  ELM elements[TLEN][ALEN];
  ELM *elms[]=(*elements);
  int i;
  for(i=0;i<TLEN;i++)
    elements[i][0].N=BASENUM+i*i*i-BASENUM/(40*i);
  while(i-->=0)//打印循环圈
  {
    int x,y,j=0;
    do handle(elements,j++);
    while(cmp(elements[i],&x,&y));
    printf("[");
    for(;x<y;x++)
      if(x==y-1)
        printf("%d]\n",elements[i][x].N);
      else printf("%d,",elements[i][x].N);
  }
  return 0;
}
