#include <stdio.h>
#include "../atoi/getstring.c"
#include "rpn.c"
#define LEN 12
int main()
{
  char str[12];
  CircularQueue digque,
                opque;
  digque.last=digque.tail=opque.last=opque.tail=0;
  getstring(str,LEN);
  getistream(&digque,&opque,str);
  printf("str:%s\n",str);
  prtqueue(&digque);
  prtqueue(&opque);
  printf("%f\n",rpncal(&digque,&opque));
  prtqueue(&digque);
  return 0;
}
