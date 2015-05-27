void bubble(int arr[],int n,short choice)
{
  short i,j;
  int tmp;
  printf("and then:%d\n",arr);
  for(i=n-1;i>0;i--)
    for(j=0;j<i;j++)
      if(choice?arr[j+1]<arr[j]:arr[j]<arr[j+1])
      {
        tmp = arr[j+1];
        arr[j+1]=arr[j];
        arr[j]=tmp;
      }
}
