#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

void	HumanB::attack(void)
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " cannot attack.\n";
	else
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << "\n";
}

void	HumanB::setWeapon(Weapon &wp)
{
	this->_weapon = &wp;
}