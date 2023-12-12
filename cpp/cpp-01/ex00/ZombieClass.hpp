#include <iostream>

class ZombieClass {
private:

	std::string name;
public:

	ZombieClass(std::string name);
	~ZombieClass();
	void announce();
};

ZombieClass *newZombie(std::string name);

void randomChump(std::string name);

