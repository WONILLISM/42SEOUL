#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	this->_type = weapon;
}

void	Weapon::setType(std::string weapon)
{
	this->_type = weapon;
}

const std::string	&Weapon::getType(void)
{
	return this->_type;
}