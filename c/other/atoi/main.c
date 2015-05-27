#include <stdio.h>
#include "getstring.c"
#include "atoi.c"
#define LEN 12
int main()
{
  long ans;
  int value;
  char arry[LEN];
  printf("Please enter a string:");
  short size=getstring(arry,LEN);
  printf("String's real length is:%d\n",size);
  printf("And the string is:%s\n",arry);
  printf("Now,it will converted all of the numeric characters to digital number~\n");
  if((ans=atoi(arry))<2147483648 && ans>-2147483648)
  {
    printf("The number which u inputed is:%ld\n",ans);
    value=0;
  }
  else
  {
    printf("Sorry! *(>(@)<)* the number is overflowed.\n");
    value=-1;
  }
  printf("Just knock \"RETURN/ENTER to end this program...\"");
  getchar();
  return value;
}
