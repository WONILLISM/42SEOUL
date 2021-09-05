#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	wopark("wopark");
	ScavTrap	wopark2("wopark2");
	ScavTrap	me;

	me = wopark;
	me.setAttackDamage(20);
	me.attack(wopark2.getName());
	wopark2.takeDamage(me.getAttackDamage());
	wopark2.beRepaired(20);
	me.guardGate();
	return (0);
}