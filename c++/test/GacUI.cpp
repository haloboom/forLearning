#include<iostream>
using namespace std;
class A{};
class B:public A{};
class C:public A{};
class D:public B, public C{};
class E:virtual public A{};
class F:virtual public A{};
class G:public E, public F{};
     
int main()
{
  D d;
  A& da1=static_cast<B&>(d);
  A& da2=static_cast<C&>(d);
  TEST_ASSERT(&da1!=&da2);
  G g;
  A& ga1=static_cast<E&>(g);
  A& ga2=static_cast<F&>(g);
  TEST_ASSERT(&ga1==&ga2);
  return 0;
}
