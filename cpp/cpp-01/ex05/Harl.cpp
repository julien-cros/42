#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func_ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*func_ptr[i])();
			break;
		}
	}
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	
}

void Harl::info()
{
	std::cout << "[ ERROR ]" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
}

