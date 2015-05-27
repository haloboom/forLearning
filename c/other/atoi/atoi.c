short check(const char *c)
{
  if(*c>='0'&&*c<='9')
    return 1;
  else if(*c=='-')
    return -1;
  else
    return 0;
}
long atoi(const char *arry)
{
  short i,flag=1;
  long ans=0;
  for(i=0;*(arry+i)!='\0';i++)
  {
    switch(check(arry+i))
    {
      case 1:ans=(*(arry+i)-'0')+10*ans;break;
      case -1:flag=-flag;break;
      defaults:continue;
    }
  }
  return flag*ans;
}
