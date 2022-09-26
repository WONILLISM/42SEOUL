#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "Wrong Animal";
	std::cout << this->_type << " is born.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->_type = copy.getType();
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << this->_type << " is dead.\n";\
}

std::string const &WrongAnimal::getType() const
{
	return this->_type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "......\n";
}
