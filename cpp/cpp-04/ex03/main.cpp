#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;
	std::cout << "========== MY TEST ==============" << std::endl;
	std::cout << std::endl;
	
	IMateriaSource	*source = new MateriaSource();
	AMateria		*temp;
	ICharacter		*boby = new Character("Boby");

	source->learnMateria(new Cure());
	source->learnMateria(new Ice());

	temp = source->createMateria("ice");
	boby->equip(temp);
	temp = source->createMateria("cure");
	boby->equip(temp);
	temp = source->createMateria("ice");
	boby->equip(temp);

	boby->use(0, *boby);
	boby->use(1, *boby);
	boby->use(2, *boby);
	boby->use(3, *boby);

	boby->unequip(1);
	
	boby->use(0, *boby);
	boby->use(1, *boby);
	boby->use(2, *boby);

	source->getMemory();

	delete source;
	delete boby;
	return 0;
}	