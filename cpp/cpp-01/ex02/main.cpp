#include <iostream>
#include <string>

#include "Zombie.hpp"

using namespace std;

int main(void)
{
	string str = "HI THIS IS BRAIN";

	string *ptr = &str;
	string &ref = str;

	cout << &str << ": " << str << endl;
	cout << ptr << ": " << *ptr << endl;
	cout << &ref << ": " << ref << endl;

	return 0;
}