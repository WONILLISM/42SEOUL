#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// Animal class 인스턴스화
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound(); //will output the cat sound!
	cat->makeSound();
	meta->makeSound();

	const WrongAnimal* wrongCat = new WrongCat();

	wrongCat->makeSound();

	delete meta;
	delete dog;
	delete cat;
	delete wrongCat;
	return (0);
}