#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	wopark("wopark");
	ClapTrap	me = wopark;

	wopark.attack("mki");
	wopark.takeDamage(2);
	wopark.beRepaired(2);

	me.attack("mki");
	me.takeDamage(5);
	me.beRepaired(3);
	return (0);
}