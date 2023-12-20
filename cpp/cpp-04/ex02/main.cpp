#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "Brain.hpp"

int main() {
	// Animal *animal = new Animal();
	Dog *dog = new Dog();
	Cat *cat = new Cat();
	WrongAnimal *wrong = new WrongAnimal();
	WrongAnimal* wrongDog = new WrongDog();
	WrongAnimal* wrongCat = new WrongCat();


	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();

	wrong->makeSound();
	wrongDog->makeSound();
	wrongCat->makeSound();

	delete dog;
	delete cat;
	delete wrong;
	delete wrongDog;
	delete wrongCat;
	return 0;
}