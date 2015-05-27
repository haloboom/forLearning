#include<stdio.h>
#include<math.h>
int f(int n, int a[], int idx)
{
	if(n==0) return 1;  // 填空1
	if(idx==4)  return 0;

	for(int i=(int)sqrt(n); i>=1; i--)
	{
		a[idx] = i;

		if(f(n-i*i,a,idx+1))  return 1;  // 填空2
	}

	return 0;
}

int main(int argc, char* argv[])
{
	for(;;)
	{
		int number;
		printf("输入整数(1~10亿)：");
		scanf("%d",&number);
		
		int a[] = {0,0,0,0};

		int r = f(number, a, 0);

		printf("%d: %d %d %d %d\n", r, a[0], a[1], a[2], a[3]);
		
	}

	return 0;
}
