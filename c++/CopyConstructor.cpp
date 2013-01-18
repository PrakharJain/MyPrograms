#include<iostream>
using namespace std;

class base
{
	public:
		base(int i)
		{
			cout << "Inside Constructor " << endl;
			m_i = i;
		}
		base( base& b)
		{
			cout << "Inside Copy constructor " ;
			m_i = b.m_i;
		}

	private:
		int m_i;
};


int myfunc(base b)
{
cout << "Inside myfunc " ;
}


int main()
{
//base c(25);
base c = 25;
myfunc(2);
return 0;
}
