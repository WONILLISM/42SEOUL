#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << this->_type << " is born.\n";
}

Dog::Dog(const Dog& copy)
{
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
	this->Animal::operator=(copy);
	return *this;
}

Dog::~Dog()
{
	std::cout << this->_type << " is dead.\n";
}

void	Dog::makeSound() const
{
	std::cout << "Bow! Wow!\n";
}