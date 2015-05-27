#include <stdio.h>
#include <string.h>
#define MAX_N 10
#define MAX_S 51
int main()
{
	char string[MAX_N][MAX_S];
	int i,n,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",string[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<strlen(string[i]);j++)
		{
			switch((string[i][j]&0xff00)>>8)
			{
				case 0xb0:printf("%s",(string[i][j]&0x00ff)<0xc5?"A":"B");break;
				case 0xb2:printf("C");break;
				case 0xb4:printf("D");break;
				case 0xb6:printf("E");break;
				case 0xb7:printf("F");break;
				case 0xb8:printf("G");break;
				case 0xb9:printf("H");break;
				case 0xbb:printf("J");break;
				case 0xbf:printf("K");break;
				case 0xc0:printf("L");break;
				case 0xc2:printf("M");break;
				case 0xc4:printf("N");break;
				case 0xc5:printf("%s",(string[i][j]&0x00ff)<0xbe?"O":"P");break;
				case 0xc6:printf("Q");break;
				case 0xc8:printf("%s",(string[i][j]&0x00ff)<0xf6?"R":"S");break;
				case 0xcb:printf("T");break;
				case 0xcd:printf("W");break;
				case 0xce:printf("X");break;
				case 0xd1:printf("Y");break;
				case 0xd4:printf("Z");break;
				default:break;
			}
		}
		printf("\n");
	}
	return 0;
}
