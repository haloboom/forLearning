unsigned rightrot(unsigned x,int n)
{
  unsigned y=x;
  int N;
  for(N=0;y!=0;y>>=1,N++);
  printf("N:%d\n",N);
  return ( ~(~0<<N) & x<<(N-n) ) | (x>>n);
}
