#include <stdio.h>
#include <time.h>
int num_time[10]={0};  //num_time[10]用来得到0-9数字出现的个数
int sum[10][21]={(0,0)},sumc[10][21]={(0,0)};//sum数组用来计算出0-9的21次方。sumc用来计算数字出现次数*它的21次方
int count=0;   //计算得到几个水仙花数了，得到2个以后就结束程序

void initProgramm()  //这个函数用来获得0-9的21次方，存在sum数组里
{
    int i,j,k;
    for(i=0;i<10;i++)
        sum[i][20]=i;

    for(k=2;k<10;k++)
    {
        for(i=1;i<21;i++)
        {
            for(j=20;j>=0;j--)
            {
                sum[k][j]*=k;
            }
            for(j=20;j>0;j--)
            {
                sum[k][j-1]+=sum[k][j]/10;
                sum[k][j]%=10;
            }
        }
    }
}


void check(int i0,int i1,int i2,int i3,int i4,int i5,int i6,int i7,int i8,int i9) //检测数字是不是水仙花数
{
    int i,j;
    int getAdd[21]={0};

       for(j=0;j<21;j++)             //把数字出现次数*它的21次方
    {
           sumc[1][j]=sum[1][j]*i1;
           sumc[2][j]=sum[2][j]*i2;
        sumc[3][j]=sum[3][j]*i3;
        sumc[4][j]=sum[4][j]*i4;
        sumc[5][j]=sum[5][j]*i5;
        sumc[6][j]=sum[6][j]*i6;
        sumc[7][j]=sum[7][j]*i7;
        sumc[8][j]=sum[8][j]*i8;
        sumc[9][j]=sum[9][j]*i9;
    }

       for(i=0;i<10;i++)     //进位
        for(j=20;j>0;j--)
        {
            sumc[i][j-1]+=sumc[i][j]/10;
            sumc[i][j]%=10;
        } 

    for(i=0;i<10;i++)       //得到一个数每位的21次方的和，就是把sumc叠加起来
        for(j=20;j>=0;j--)
            getAdd[j]+=sumc[i][j];
   
    for(i=20;i>0;i--)    //进位
    {
        getAdd[i-1]+=getAdd[i]/10;
        getAdd[i]%=10;
    }
   
    int j1=0,j2=0,j3=0,j4=0,j5=0,j6=0,j7=0,j8=0,j9=0,j0=0; 
    for(i=20;i>=0;i--)          //用来判断和里面每个数字出现的次数
    {
        switch(getAdd[i])
        {
            case 0:j0++;break;
            case 1:j1++;break;
            case 2:j2++;break;
            case 3:j3++;break;
            case 4:j4++;break;
            case 5:j5++;break;
            case 6:j6++;break;
            case 7:j7++;break;
            case 8:j8++;break;
            case 9:j9++;break;
        }
    }
   
    //如果一个数字，和里0-9出现的次数与这个数字里0-9出现的次数相同，那么和就应该是水仙花数（第一位数字不能为0）。
    if((i0==j0)&&(i1==j1)&&(i2==j2)&&(i3==j3)&&(i4==j4)&&(i5==j5)&&(i6==j6)&&(i7==j7)&&(i8==j8)&&(i9==j9)&&(getAdd[0]!=0))
    {
        printf("\n");
        count++;
        for(i=0;i<21;i++)
            printf("%d",getAdd[i]);
        printf("\n");
    }
}

void main()
{
    int t,t1,t2;
    initProgramm();
    t1=time(NULL);
    int i0,i1,i2,i3,i4,i5,i6,i7,i8,i9;
    for(i9=0;i9<10;i9++)    //10层循环进行枚举，判断
    {
        for(i0=1;i0<22;i0++)
        {
            if(count==2)   //出现2个水仙花数以后break
                break;
            if(i9+i0==21)
            {    check(i0,0,0,0,0,0,0,0,0,i9);break;} //几个数字的出现次数和为21以后就break,因为后面的数字出现次数和一定大于21位
            for(i2=0;i2<22;i2++)
            {
                if(count==2)
                    break;
                if(i9+i0+i2==21)
                {    check(i0,0,i2,0,0,0,0,0,0,i9);break;}
                for(i3=0;i3<22;i3++)
                {
                    if(count==2)
                        break;
                    if(i9+i0+i2+i3==21)
                    {    check(i0,0,i2,i3,0,0,0,0,0,i9);break;}
                    for(i4=0;i4<22;i4++)
                    {
                        if(count==2)
                            break;
                        if(i9+i0+i2+i3+i4==21)
                        {    check(i0,0,i2,i3,i4,0,0,0,0,i9);break;}
                        for(i5=0;i5<22;i5++)
                        {
                            if(count==2)
                                break;
                             if(i9+i0+i2+i3+i4+i5==21)
                            {    check(i0,0,i2,i3,i4,i5,0,0,0,i9);break;}
                            for(i6=0;i6<22;i6++)
                            {
                                if(count==2)
                                    break;
                                if(i9+i0+i2+i3+i4+i5+i6==21)
                                {    check(i0,0,i2,i3,i4,i5,i6,0,0,i9);break;}
                                for(i7=0;i7<22;i7++)
                                {
                                    if(count==2)
                                        break;
                                    if(i9+i0+i2+i3+i4+i5+i6+i7==21)
                                    {    check(i0,0,i2,i3,i4,i5,i6,i7,0,i9);break;}
                                    for(i8=0;i8<22;i8++)
                                    {
                                        if(count==2)
                                            break;
                                        if(i9+i0+i2+i3+i4+i5+i6+i7+i8==21)
                                        {    check(i0,0,i2,i3,i4,i5,i6,i7,i8,i9);break;}
                                        for(i1=0;i1<22;i1++)
                                        {
                                            if(count==2)
                                                  break;
                                            if(i9+i0+i2+i3+i4+i5+i6+i7+i8+i1==21)
                                            {    check(i0,i1,i2,i3,i4,i5,i6,i7,i8,i9);break;}
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    t2=time(NULL);
    t=t2-t1;
    printf("\n%d s\n",t);
}
