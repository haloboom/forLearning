short getstring(char *arry,const short len)
{
  short i;
  for(i=0;(*(arry+i)=getchar())!=EOF && *(arry+i)!='\n';i++)
  {
    if(i==len-1)
    {
      printf("Sorry,the buffer would be overflowing,some characters has to droped.\n");
      setbuf(stdin,NULL);
      //rewind(stdin);
      break;
    }
  }
  *(arry+i)='\0';
  return i+1;
}
