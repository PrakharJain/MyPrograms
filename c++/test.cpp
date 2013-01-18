#include <iostream>
using namespace std;

class Foo
{
public:
  // single parameter constructor, can be used as an implicit conversion
  Foo (int foo) : m_foo (foo) 
  {
  }

  int GetFoo () { return m_foo; }

private:
  int m_foo;
};

void DoBar (Foo foo)
{
	cout << "inside DoBar " << endl;
  int i = foo.GetFoo ();
}

int main ()
{
  DoBar (42);
}
