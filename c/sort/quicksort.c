void swap(int *a,int *b)
{
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}

void quicksort(int *arry,short left,short right)
{
  short last_smaller,last_bigger;
  if(left<=right)
  {
    int key=arry[left];
    last_smaller=left;
    last_bigger=right;
    short i;
    for(i=left+1;i<=right;i++)
      if(arry[i]<key)
        last_smaller++;
      else
      {
        while(arry[last_bigger]>key&&last_bigger>i)
          last_bigger--;
        if(arry[last_bigger]<=key)
        {
          swap(arry+last_bigger,arry+i);
          last_smaller++;
        }
      }
    arry[left]=arry[last_smaller];
    arry[last_smaller]=key;
  }
  else return;
  quicksort(arry,left,last_smaller-1);
  quicksort(arry,last_smaller+1,right);
}
