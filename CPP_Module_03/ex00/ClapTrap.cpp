#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor is called\n";
	this->_hp = 10;
	this->_mp = 10;
	this->_dmg = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor that initializes name is called\n";
	_name = name;
	this->_hp = 10;
	this->_mp = 10;
	this->_dmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "ClapTrap copy constructor is called\n";
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "ClapTrap assignation operator is called\n";
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_mp = copy._mp;
	this->_dmg = copy._dmg;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor is called\n";
}

void	ClapTrap::attack(std::string const& target)
{
	std::cout << "ClapTrap " << this->_name << "attacks " << target << ", causing " << this->_dmg << "points of damage!\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << "is taken " << amount << "points of damage!\n";
	this->_hp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << "is repaired " << amount << "points of hp!\n";
	this->_hp += amount;
}