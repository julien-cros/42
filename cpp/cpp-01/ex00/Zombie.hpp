#include <iostream>

// cppcheck-suppress passedByValue
class Zombie {
private:

	std::string name;
public:
	
	explicit Zombie(std::string name);
	~Zombie();
	void announce();
};

Zombie *newZombie(std::string name);

void randomChump(std::string name);

