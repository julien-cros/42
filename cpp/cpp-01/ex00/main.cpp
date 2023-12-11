#include <iostream>
#include <string>

#include "ZombieClass.hpp"

int main(){
	
	ZombieClass *zombie1 = newZombie("Zombie1");
	ZombieClass *zombie2 = newZombie("Zombie2");


	
	zombie1->announce();
	zombie2->announce();
	delete zombie1;
	delete zombie2;
	randomChump("NewZombie1");
	randomChump("NewZombie2");
	return 0;
}
