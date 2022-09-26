#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << this->_type << " is born.\n";
	this->brain = new Brain();
}

Dog::Dog(const Dog& copy)
{
	this->brain = new Brain(*copy.getBrain());
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		this->~Dog();
		this->brain = new Brain(*copy.getBrain());
		this->Animal::operator=(copy);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << this->_type << " is dead.\n";
	delete this->brain;
}

void	Dog::makeSound() const
{
	std::cout << "Bow! Wow!\n";
}

Brain* Dog::getBrain() const
{
	return this->brain;
}