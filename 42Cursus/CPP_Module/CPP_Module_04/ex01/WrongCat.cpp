#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << this->_type << " is born.\n";
}

WrongCat::WrongCat(const WrongCat& copy)
{
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	this->WrongAnimal::operator=(copy);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << this->_type << " is dead.\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "Maw! Mow! \n";
}