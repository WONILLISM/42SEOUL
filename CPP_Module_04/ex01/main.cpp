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
	std::cout << "CAT/DOG DEEP COPY TEST:\n\n";

	Dog dog;
	for (int i = 0; i < 100; i++)
		dog.getBrain()->setIdea(i, std::to_string(i));
	Dog tmp_dog = dog;

	for (int i = 0; i < 100; i++)
	{
		std::cout << dog.getBrain()->getIdea(i) << "	";
		std::cout << tmp_dog.getBrain()->getIdea(i) << "\n";
	}
	std::cout << "\n";
	for (int i = 0; i < 100; i++)
	{
		tmp_dog.getBrain()->setIdea(i, std::to_string(i + 100));
		std::cout << dog.getBrain()->getIdea(i) << "	";
		std::cout << tmp_dog.getBrain()->getIdea(i) << "\n";
	}
	// system("leaks ex01");

	return (0);
}