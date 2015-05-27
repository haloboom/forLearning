typedef struct node{
  int Id=-1;
  struct node *lnode=NULL;
  struct node *rnode=NULL;
}Node,*LinkNode;

void inits(LinkNode head,int n);
void getout(LinkNode tar);
void Joseph(LinkNode head,int n,int m);//n=start,m=step
