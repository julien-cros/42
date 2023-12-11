#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie();
	void changeName(std::string name);
	void announce();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);
Zombie *zombieHorde(int N, std::string name);
