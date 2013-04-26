#include<iostream>
using namespace std;
template <class T>
class SmartPointer
{
	public:
		T* ptr;
		int * count;

		SmartPointer(T* p)
		{
			cout << "Inside Constructor " << endl;
			count = new int;
			*count = 1;
			ptr = p;
		}

		SmartPointer( SmartPointer& s)
		{
			cout << "Inside copy constructor " << endl;
			count = s.count;
			IncreaseRef();
			ptr = s.ptr;
		}

		SmartPointer& operator=(SmartPointer & s)
		{
			cout << "Inside operator = " << endl;
			DecreaseRef();
			ptr = s.ptr;
			count = s.count;
			IncreaseRef();
		}

		T& operator*()
		{
			return *ptr;
		}

		T* operator->()
		{
			return ptr;
		}
		
		~SmartPointer()
		{
		DecreaseRef();
		}
			

	private:
		void DecreaseRef()
		{
			int &c = *count;
			c--;
			if(c == 0)
			{
				cout << "Deleting Pointer" << endl;
				delete ptr;
				ptr =  NULL;
				delete count;
				count = NULL;
			}
		}

		void IncreaseRef()
		{
			if(!count)
			{
			count = new int;
			*count = 0;
			}
			(*count)++;
		}

};

template <class T>
void MyCallByValueFunc(SmartPointer<T> p)
	{
	(*p)++;
	cout << *p << endl;
	}


int main()
{
SmartPointer<int> sptr(new int);

*sptr = 0;
cout << *sptr<< endl;
SmartPointer<int> sptr1 = sptr;
(*sptr1)++;
cout <<*sptr1<<endl;
cout << *sptr << endl;
MyCallByValueFunc(sptr);
cout <<*sptr << endl;


SmartPointer<int> sptr3 (new int);
sptr3 = sptr1;

}
