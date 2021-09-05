#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor is called\n";
}
ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor that initializes name is called\n";
	this->_name = name;
	this->_hp = 100;
	this->_mp = 50;
	this->_dmg = 20;
}
ScavTrap::ScavTrap(const ScavTrap& copy)
{
	std::cout << "ScavTrap copy constructor is called\n";
	*this = copy;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	std::cout << "ScavTrap assignation operator is called\n";
	this->ClapTrap::operator=(copy);
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor is called\n";
}
void	ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_dmg << " points of damage!\n";
}
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode.\n";
}