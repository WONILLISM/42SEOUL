#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor is called\n";
	this->_hp = FragTrap::_hp;
	this->_mp = ScavTrap::_mp;
	this->_dmg = FragTrap::_dmg;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap::ClapTrap(name), ScavTrap::ScavTrap(name), FragTrap::FragTrap(name)
{
	std::cout << "DiamondTrap constructor that initializes name is called\n";
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_mp = ScavTrap::_mp;
	this->_dmg = FragTrap::_dmg;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
{
	std::cout << "DiamondTrap copy constructor is called\n";
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	std::cout << "DiamondTrap assignation operator is called\n";
	this->ClapTrap::operator=(copy);
	this->_name = copy._name;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor is called\n";
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << this->_name << "\n";
	std::cout << "ClapTrap name is " << ClapTrap::_name << "\n";
}
