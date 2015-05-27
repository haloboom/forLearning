unsigned invertbits(unsigned x,int p,int n)
{
  unsigned x_need=getbits(x,p,n);
  int need_bits=p-n+1;
  return (x&~(x_need<<need_bits))|~(x_need<<need_bits);
}
