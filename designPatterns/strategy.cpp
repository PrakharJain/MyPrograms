/* Startegy pattern is used to switch startegies (algorithms at run time.
 * Here we implement a player (context) who switches the weapon(strategy) at run time.
 */


#include <iostream>
#include <cstdlib>
using namespace std;

class Weapon // startegy interface 
{
	public:
		virtual void use() = 0;
};


class Player // represents the context
{

	public:
		Player(Weapon * w)
		{
			weapon = w;
		}
		void useWeapon()
		{
			weapon->use();
		}
		void setWeapon(Weapon * w)
		{
			weapon = w;
		}
	private:
		Weapon * weapon;
};


class Gun : public Weapon // concrete stratey
{
	public:

		void use() // algorithm for using gun implemented here.
		{
			cout << "Using a gun " <<endl;
		}
};

class Sword : public Weapon
{
	public:
		void use() // algorithm for using a sword implemented here.
		{
			cout << "Using a sword" << endl;
		}
};



class Knife : public Weapon
{
	public:
		void use()
		{
			cout << "Using Knife " << endl;
		}
};



int main()
{
	Knife * k = new Knife();
	Sword * s = new Sword();
	Gun * g = new Gun();
	char ch;
	Player p(k);

	while(true)
	{
		cout << "1.Knife  2.Sword  3.Gun 4.Exit " << endl;
		cin >> ch; 
		switch(ch)
		{
			case '1':p.setWeapon(k); 
				 break;
			case '2':p.setWeapon(s);
				 break;
			case '3':p.setWeapon(g);
				 break;
			case '4':delete s;
				 delete k;
				 delete g;
				 exit(0);
			default: p.setWeapon(k);
				 break;
		}
		p.useWeapon();
	}
	delete k;
	delete s;
	delete g;
	return 0;
}
