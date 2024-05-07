#ifndef SERILIZE_HPP
#define SERILIZE_HPP

#include <iostream>

typedef struct Data
{
	std::string _string;
	int _int;
} Data;

class Serialize
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif