#include <stdlib.h>
typedef float datatype;
#define QUE_LEN 12
typedef struct{
short last,
      tail;
datatype map[QUE_LEN];
}CircularQueue;
void push(CircularQueue *que,datatype op);
datatype pop(CircularQueue *que);
short isempty(CircularQueue *que);
short isfull(CircularQueue *que);
short isdigit(CircularQueue *que);
void getistream(CircularQueue *digque,CircularQueue *opque,char *instream);
datatype rpncal(CircularQueue *digque,CircularQueue *opque);
void prtqueue(CircularQueue *que);
void prtqueue(CircularQueue *que)
{
  short i;
  for(i=que->last-1;(i%=QUE_LEN)!=que->tail;i--)
    printf("queue.map[%d]:%f,",i,que->map[i]);
  printf("queue.map[%d]:%f\n",i,que->map[i]);
}
short isempty(CircularQueue *que)
{
 return (que->last==que->tail);
}
short isfull(CircularQueue *que)
{
  return ((que->last+1)%QUE_LEN==que->tail);
}
void push(CircularQueue *que,datatype op)
{
  short i=0;
  if(!isfull(que))
  {
    do
    {
      que->map[(que->last-i+1)%QUE_LEN]=que->map[(que->last-i)%QUE_LEN];
    }while((que->last-i++)%QUE_LEN!=que->tail);
    que->last+=1;
    que->map[que->tail]=op;
  }
  else return;
}
datatype pop(CircularQueue *que)
{
  if(!isempty(que))
  {
    datatype tmp=que->map[que->last-1];
    que->last=(que->last-1)%QUE_LEN;
    return tmp;
  }
  else return -1;
}
void getistream(CircularQueue *digque,CircularQueue *opque,char *instream)
{
  short i;
  for(i=0;instream[i]!='\0';i++)
    if(instream[i]>='0'&&instream[i]<='9')
      push(digque,instream[i]-'0');
    else
      push(opque,instream[i]);
}
datatype rpncal(CircularQueue *digque,CircularQueue *opque)
{
  char op;
  while((digque->tail+1)%QUE_LEN!=digque->last)
  {
    op=(char)pop(opque);
    switch(op)
    {
      case '+':push(digque,pop(digque)+pop(digque));break;
      case '-':push(digque,pop(digque)-pop(digque));break;
      case '*':push(digque,pop(digque)*pop(digque));break;
      case '/':push(digque,pop(digque)/pop(digque));break;
      defaults:exit(-1);
    }
  }
  return digque->map[digque->tail];
}
