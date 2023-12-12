#include <iostream>
#include <string>

#include "Zombie.hpp"

int main(){
	
	Zombie *zombie1 = newZombie("Zombie1");
	Zombie *zombie2 = newZombie("Zombie2");


	
	zombie1->announce();
	zombie2->announce();
	delete zombie1;
	delete zombie2;
	randomChump("NewZombie1");
	randomChump("NewZombie2");
	return 0;
}
