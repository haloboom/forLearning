#include<stdio.h>
#include<stdlib.h>
#define L1 0
#define L2 1
#define L3 2
#define LEN 16

typedef struct{
  int layerLevel;
  char location[LEN];
  struct Layer *treeLayer;
  struct Layer *nextLayer;
}Layer;
Layer f()
{
  FILE *fp;
  char ch;
  int cnt,curlev=0;
  int i;
  Layer head={0,'',NULL,NULL};
  Layer *tip=&head;
  if((fp=fopen("a.txt","r"))==NULL)
  {
    printf("shit!\n");
    exit(-1);
  }
  while(!feof(fp))
  {
    cnt=i=0;
    Layer *lp=(Layer *)malloc(sizeof(Layer));
    while((ch=fgetc(fp))!='\n')
    {
      if(ch==' ')
        cnt++;
      else
        lp->location[i]=ch;
    }
    switch(cnt)
    {
      case L1:lp->layerLevel=L1;break;
      case L2:lp->layerLevel=L2;break
      case L3:lp->layerLevel=L3;break;
      defaults:break;
    }
    switch(cnt-curlev)
    {
      case 0:tip->nextLayer=lp;tip=lp;break;
      case 1:tip->treeLayer=lp;break;
      defaults:break;
    }
  }
 return head;
}
int main()
{
  f();
  return 0;
}
