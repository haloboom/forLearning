#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TMS 100000
#define random(n) (rand()%n)
float list[][4]=
 {    //a  b    c    d
  /*a*/{0, 0.1, 0.3, 0.5},
  /*b*/{0.9, 0, 0.7, 0.4},
  /*c*/{0.7, 0.3, 0, 0.2},
  /*d*/{0.5, 0.6, 0.8, 0}
 };

float f(int n)
{
  int i;
  float ab_cd=0.1*0.2*0.3+0.1*0.8*0.5,
        ac_bd=0.3*0.4*0.1+0.3*0.6*0.5,
        ad_bc=0.5*0.7*0.1+0.5*0.3*0.3;
  float E_a=0,P;
  for(i=0;i<n;i++)
  {
    switch(random(3))
    {
      case 0:E_a+=ab_cd;break;
      case 1:E_a+=ac_bd;break;
      case 2:E_a+=ad_bc;break;
    }
  }
  P=E_a/n;
  return P;
}

int main()
{
  srand((int)time(NULL));
  float P=f(TMS);
  printf("P=%5.3f\n",P);
  return 1;
}
