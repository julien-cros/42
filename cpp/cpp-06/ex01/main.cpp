#include "serialize.hpp"

int main()
{
	Data data;
	data._string = "Hello, World!";
	data._int = 42;

	uintptr_t raw = Serialize::serialize(&data);
	Data *ptr = Serialize::deserialize(raw);

	std::cout << ptr->_string << std::endl;
	std::cout << ptr->_int << std::endl;

	return 0;
}