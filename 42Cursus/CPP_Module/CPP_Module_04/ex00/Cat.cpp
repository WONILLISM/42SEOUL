#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << this->_type << " is born.\n";
}

Cat::Cat(const Cat& copy)
{
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
	this->Animal::operator=(copy);
	return *this;
}

Cat::~Cat()
{
	std::cout << this->_type << " is dead.\n";
}

void	Cat::makeSound() const
{
	std::cout << "Meow ~ \n";
}