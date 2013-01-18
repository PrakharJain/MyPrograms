#include <iostream>
using namespace std;




class base
{
	public:
		void fun()
		{
			cout << " Fun frm base" << endl;
		}

		void run()
		{
			fun();
		}
};

class derived : public base
{
	public:
		void fun()
		{
			cout << "Inside Derived Fun() " << endl;
		}
};

int main()
{
derived d;
d.run();
}
