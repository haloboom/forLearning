#include <stdio.h>
#define N 100000
int choice(int m,int n)
{
	if(m>n) return 0;
	else if(m==0) return 1;
	else if(m<0) return 0;
	return choice(m-1,n-1)+choice(m,n-1);
}
int main()
{
	int i_total;
	int i_current;
	int i_tmp;
	int v_i;
	int v_j;
	int v_k;
	int sum=0;
	int a_query[N];
	//get data start
	scanf("%d",&i_total);
	for(v_i=0;v_i<i_total-1;v_i++)
		scanf("%d",a_query+v_i);
	//get data end
	//core code start
	for(v_j=1;v_j<=i_total;v_j++)
	{
		//get i_current start
		i_current=1;
		for(v_k=v_j-1;v_k<v_i;v_k++)
		{
			if(a_query[v_k]!=v_j)
				i_current++;
		}
		i_tmp=i_current;
		//get i_current end
		if(i_tmp==0)
			sum+=1;
		else
		while(i_tmp--)
			sum+=choice(i_tmp,i_current-1);//this is answer
	}
	printf("%d\n",sum);
	//core code end
	return 0;
}