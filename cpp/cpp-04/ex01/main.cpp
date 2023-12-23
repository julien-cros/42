#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "Brain.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongDog = new WrongDog();
	const WrongAnimal* wrongCat = new WrongCat();


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
		
	wrong->makeSound();
	wrongDog->makeSound();
	wrongCat->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrongDog;
	delete wrongCat;

	int index = 0;
	Animal *array[100];

	while (index < 50)
		array[index++] = new Dog();
	while (index < 100)
		array[index++] = new Cat();

	index = 0;
	while (index < 100)
		delete array[index++];

	return 0;
}