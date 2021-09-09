#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "Animal";
	std::cout << this->_type << " is born.\n";
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
	this->_type = copy.getType();
	return *this;
}

Animal::~Animal()
{
	std::cout << this->_type << " is dead.\n";
}

std::string const	& Animal::getType() const
{
	return this->_type;
}

void	Animal::makeSound() const
{
	std::cout << "KRRRR....\n";
}