#include <stdio.h>
#define LEN 14；
typedef struct{
	int x[LEN];
	int y[LEN];
	int item[LEN];
	int accounter;
}S_WATCHER ;
int main()
{
	//init() start
	S_WATCHER task_watcher[LEN];
	task_watcher[0]=
	{
		{0},
		{8},
		{7},
		{1}
	};
	task_watcher[1]=
	{
		{1},
		{6},
		{4},
		{1}
	};
	//init() end
	int cnt_num[LEN/2]={0,0,0,2,0,0,2};	
	int task_arr[LEN]={7,4,0,0,0,0,4,0,7,0,0,0,0,0};
	//get() start
	int i,j;
	for(i=0;i<LEN;i++)
	{	
		if(task_arr[i]!=0)
			continue;
		for(j=0;j<LEN/2;j++)
		{
			if(cnt_num[j]==0 && task_arr[i+j+1]==0)
			{
				task_watcher[].x[task_watcher.accounter]=i;
				task_watcher.y[task_watcher.accounter]=i+j+1;
				task_watcher.item[task_watcher.accounter]=j+1;
				task_watcher.accounter++;
			}
		}
	}
	//get() end
	//show() start
	for(;task;)
	//show() end
	
	return 0;
}