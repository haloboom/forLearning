#include<iostream>
using namespace std;
#define MAN 1
#define WOMEN 0
#define GOOD 1
#define BAD -1
#define FINE 0
#define ALIVE 1
#define DEAD 0
class Person
{
  public:
    Person()
    {
      cout<<"A Person Borned"<<endl;
    }
    Person(int isAlive)
    {
      this->isAlive=isAlive;
      if(isAlive)
        cout<<"Alive"<<endl;
      else
        cout<<"DEAD"<<endl;

    }
    ~Person()
    {
      cout<<"A Person Dispeared"<<endl;
    }
    virtual void talk()
    {
      cout<<"The Person is talking"<<endl;
    }
  private:
    int isAlive;
};
class Army:public Person
{
  public:
    Army()
    {
      cout<<"A Army Borned"<<endl;
    }
    Army(int isAlive):Person(isAlive)
    {
      cout<<"A Person turned to Army"<<endl;
    }
    ~Army()
    {
      cout<<"A Army Dispeared"<<endl;
    }
    virtual void talk()
    {
      cout<<"A Army is talking"<<endl;
    }
    void allowkill()
    {
      this->kill();
    }
  private:
    virtual void run()
    {
     cout<<"Army is runing"<<endl;
    }
    virtual void kill()
    {
      cout<<"Army is killing"<<endl;
    }
};
class Genal:private Army
{
  public:
    Genal()
    {
      cout<<"A Genal Borned"<<endl;
    }
    Genal(int isAlive):Army(isAlive)
    {
      cout<<"A Army turned to Genal"<<endl;
    }
    ~Genal()
    {
      cout<<"A Genal is Dispeared"<<endl;
    }
    void allowtalk()
    {
      this->talk();
    }
    void walk()
    {
      cout<<"Genal is walking"<<endl;
    }
  protected:
    int testValue;
};
int main()
{
  Person lry(ALIVE);
  lry.talk();
  Army tArmy(ALIVE);
  tArmy.allowkill();
  Genal aGenal(ALIVE);
  aGenal.allowtalk();
  return 0;
}
