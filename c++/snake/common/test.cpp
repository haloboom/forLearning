#include <iostream>
#include <unistd.h>
#include <stdio.h>
// 清除屏幕 
#define CLEAR() printf("\033c")
// 上移光标 
#define MOVEUP(x) printf("\033[%dA", (x))
// 下移光标 
#define MOVEDOWN(x) printf("\033[%dB", (x))
// 左移光标 
#define MOVELEFT(y) printf("\033[%dD", (y))
// 右移光标 
#define MOVERIGHT(y) printf("\033[%dC",(y))
// 定位光标 
#define MOVETO(x,y) printf("\033[%d;%dH", (y), (x))
// 光标复位 
#define RESET_CURSOR() printf("\033[H")
// 隐藏光标 
#define HIDE_CURSOR() printf("\033[?25l")
// 显示光标 
#define SHOW_CURSOR() printf("\033[?25h")
using namespace std;
void drawFrame(int startx,int starty,int heigth,int width)
{
  int i,j;
  CLEAR();
  MOVETO(startx,starty);
  for(j=startx;j<startx+heigth;j++)
  {
    cout<<'*';
    MOVERIGHT(1);
    if(j==startx||j==startx+heigth-1)
    {
      for(i=starty;i<starty+width-1;i++)
      {
        cout<<'*';
        MOVERIGHT(1);
      }
    }
    else
    {
      MOVETO(startx+2*(width-1),j);
      cout<<'*';
    }
    MOVETO(startx,j+1);
  }
}
int main()
{
  unsigned char choice=0;
  drawFrame(4,5,6,10);
 /* int x=10,y=10;
  int i,j;
  int heigth,width;
  heigth=width=0;
  CLEAR();
  MOVETO(0,0);
  for(j=0;j<y/2;j++)
  {
    cout<<'*';
    MOVERIGHT(1);
    width++;
    if(j==0||j==(y/2-1))
    {
      for(i=0;i<x-1;i++)
      {
        cout<<'*';
        MOVERIGHT(1);
      }
    }
    else
    {
      MOVETO(2*x-1,width);
      cout<<'*';
    }
    MOVETO(heigth,width);
  }
 // while(choice!='x')
  {
    printf("Enter Your Choice:");
    printf("1:MOVEUP\n");
    printf("2:MOVEDOWN\n");
    printf("3:MOVELEFT\n");
    printf("4:MOVERIGHT\n");
    printf("5:MOVETO\n");
    printf("6:RESET_CURSOR\n");
    printf("7:HIDE_CURSOR\n");
    printf("8:SHOW_CURSOR\n");
    printf("9:CLEAR\n");
    printf("x:EXIT_PRO\n\n");
    switch(choice=getchar())
    {
      case '1':
        printf("X:");
        scanf("%d",&x);
        MOVEUP(x);
        break;
      case '2':
        printf("X:");
        scanf("%d",&x);
        MOVEDOWN(x);
        break;
      case '3':
        printf("Y:");
        scanf("%d",&y);
        MOVELEFT(y);
        break;
      case '4':
        printf("Y:");
        scanf("%d",&y);
        MOVERIGHT(y);
        break;
      case '5':
        printf("X,Y:");
        scanf("%d%d",&x,&y);
        MOVETO(x,y);
        break;
      case '6':
        RESET_CURSOR();
        break;
      case '7':
        HIDE_CURSOR();
        break;
      case '8':
        SHOW_CURSOR();
        break;
      case '9':
        CLEAR();
        break;
    }
  }*/
 return 0;
}
