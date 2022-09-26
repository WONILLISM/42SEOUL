#include "Dog.hpp"
#include "Cat.hpp"
#include <string>
#define ANIAMLNUM	4

int	main(void)
{
	std::cout << "=======================================\n\n";
	std::cout << "                CPP04 TEST             \n\n";
	std::cout << "=======================================\n";

	std::cout << "CREATE TEST:\n\n";
	Animal *Animals[ANIAMLNUM];
	for (int i = 0; i < ANIAMLNUM; i++){
		if (i % 2 == 0)
			Animals[i] = new Cat();
		else
			Animals[i] = new Dog();
	}

	for (int i = 0;  i < ANIAMLNUM; i++)
		Animals[i]->makeSound();

	std::cout << "----------------------------------------\n\n";

	for (int i = 0; i < ANIAMLNUM; i++)
		delete Animals[i];

	std::cout << "----------------------------------------\n\n";
	std::cout << "ABSTRACT CLASS TEST:\n\n";

	Dog* dog = new Dog();
	Cat* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
	system("leaks ex02");

	return (0);
}