#include <iostream>
using namespace std;


class base1
{
	public:
		base1()
		{
			cout << "Inside base 1 constructor " << endl;
		}

		~base1()
		{

			cout << " Inside Base1 Destrucor " << endl;
		}
};

class base2
{
	public:
		base2()
		{
			cout << "Inside base2 constructor" << endl;
		}

		~base2()
		{
			cout << " Inside Base 2 Destructor " << endl;
		}
};

class Derived : public base1,base2
{
	public:
		Derived()
		{
			cout <<  " Inside derived constructor " << endl;
		}

		~Derived()
		{
			cout << "Inside Derived Destructor" << endl;
		}
};

int main()
{
	Derived d;
	return 0;
}
