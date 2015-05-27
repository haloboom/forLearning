#include <iostream>
using namespace std;
template <class T>
T fmax(T p1,T p2)
{
  return p1>p2?p1:p2;
}
int main()
{
  cout<<fmax(10,20)<<endl;
  return 0;
}
