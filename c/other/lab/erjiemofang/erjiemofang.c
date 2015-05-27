#include<stdio.h>
#include<string.h>
#define RED 1
#define BLUE 2
#define YELLOW 3
#define WHITE 4
#define ORANGE 5
#define GREEN 6
typedef struct{
int i_xyz_color[3];
}Apex;
Apex target[9]=
{
{0},
{GREEN,ORANGE,WHITE},//绿橙白
{GREEN,RED,WHITE},//绿红白
{GREEN,RED,YELLOW},//绿红黄
{GREEN,ORANGE,YELLOW},//绿橙黄
{BLUE,ORANGE,WHITE},//蓝橙白
{BLUE,RED,WHITE},//蓝红白
{BLUE,ORANGE,YELLOW},//蓝橙黄
{BLUE,RED,YELLOW}//蓝红黄;
};

void swap(int t1,int t2)
{
  target[0]=target[t1];
  target[t1]=target[t2];
  target[t2]=target[0];
}
void opt_x()
{
  swap(1,2);//1->2
  swap(1,3);//2->3
  swap(1,4);//3->4
  //swap(2,1);//4->1
  int tmp;
  tmp=target[1].i_xyz_color[1];
  target[1].i_xyz_color[1]=target[1].i_xyz_color[2];
  target[1].i_xyz_color[2]=tmp;

  tmp=target[2].i_xyz_color[1];
  target[2].i_xyz_color[1]=target[2].i_xyz_color[2];
  target[2].i_xyz_color[2]=tmp;

  tmp=target[3].i_xyz_color[1];
  target[3].i_xyz_color[1]=target[3].i_xyz_color[2];
  target[3].i_xyz_color[2]=tmp;

  tmp=target[4].i_xyz_color[1];
  target[4].i_xyz_color[1]=target[4].i_xyz_color[2];
  target[4].i_xyz_color[2]=tmp;
}
void opt_y()
{
  swap(2,6);//2->6
  swap(2,7);//6->7
  swap(2,3);//7->3
  int tmp;
  tmp=target[3].i_xyz_color[0];
  target[3].i_xyz_color[0]=target[3].i_xyz_color[2];
  target[3].i_xyz_color[2]=tmp;

  tmp=target[6].i_xyz_color[0];
  target[6].i_xyz_color[0]=target[6].i_xyz_color[2];
  target[6].i_xyz_color[2]=tmp;

  tmp=target[2].i_xyz_color[0];
  target[2].i_xyz_color[0]=target[2].i_xyz_color[2];
  target[2].i_xyz_color[2]=tmp;

  tmp=target[7].i_xyz_color[0];
  target[7].i_xyz_color[0]=target[7].i_xyz_color[2];
  target[7].i_xyz_color[2]=tmp;

}
void opt_z()
{
  swap(1,5);//1->5
  swap(1,6);//5->6
  swap(1,2);//6->2  
  int tmp;
  tmp=target[1].i_xyz_color[1];
  target[1].i_xyz_color[1]=target[1].i_xyz_color[0];
  target[1].i_xyz_color[0]=tmp;

  tmp=target[2].i_xyz_color[1];
  target[2].i_xyz_color[1]=target[2].i_xyz_color[0];
  target[2].i_xyz_color[0]=tmp;

  tmp=target[5].i_xyz_color[1];
  target[5].i_xyz_color[1]=target[5].i_xyz_color[0];
  target[5].i_xyz_color[0]=tmp;

  tmp=target[6].i_xyz_color[1];
  target[6].i_xyz_color[1]=target[6].i_xyz_color[0];
  target[6].i_xyz_color[0]=tmp;
}
int main()
{
  char string[]="xy";
  int i,n=strlen(string);
  for(i=0;i<n;i++)
  {
    switch(string[i])
    {
      case 'x':opt_x();break;
      case 'y':opt_y();break;
      case 'z':opt_z();break;
    }
  }
  for(i=0;i<3;i++)
  {
    switch(target[2].i_xyz_color[i])
    {
      case RED:printf("red ");break;
      case BLUE:printf("bule ");break;
      case YELLOW:printf("yellow ");break;
      case WHITE:printf("white ");break;
      case ORANGE:printf("orange ");break;
      case GREEN:printf("green ");break;
    }
  }
  printf("\n");
  return 1;
}
