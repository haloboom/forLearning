unsigned setbit(unsigned x,int p,int n,unsigned y)
{
  unsigned x_need=getbits(x,p,n),
            y_need=getbits(y,p,n);
  int need_bits=p-n+1;
  return (x&~(x_need<<need_bits))|y_need<<need_bits;
}
