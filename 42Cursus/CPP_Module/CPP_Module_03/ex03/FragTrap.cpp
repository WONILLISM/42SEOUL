#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor is called\n";
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hp = 100;
	this->_mp = 100;
	this->_dmg = 30;
	std::cout << "FragTrap constructor that initializes name is called\n";
}

FragTrap::FragTrap(const FragTrap& copy)
{
	std::cout << "FragTrap copy constructor is called\n";
	*this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	std::cout << "FragTrap assignation operator is called\n";
	this->ClapTrap::operator=(copy);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor is called\n";
}

void	FragTrap::highFiveGuys()
{
	std::cout << "FragTrap" << this->_name << ": Let's high-five guys\n";
}
