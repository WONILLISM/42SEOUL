#include "Zombie.hpp"

Zombie::Zombie(void){}
Zombie::Zombie(std::string name): _name(name){}
Zombie::~Zombie(void)
{
	std::cout << this->_name << " GRRRRRRR....\n";
}
void	Zombie::announce(void)
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ... \n";
}
void	Zombie::set_name(std::string name)
{
	this->_name = name;
}
std::string	Zombie::get_name(void)
{
	return this->_name;
}