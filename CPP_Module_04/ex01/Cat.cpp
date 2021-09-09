#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << this->_type << " is born.\n";
	this->brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	this->brain = new Brain(*copy.getBrain());
}

Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
	{
		this->~Cat();
		this->brain = new Brain(*copy.getBrain());
		this->Animal::operator=(copy);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << this->_type << " is dead.\n";
	delete this->brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow ~ \n";
}

Brain* Cat::getBrain() const
{
	return this->brain;
}