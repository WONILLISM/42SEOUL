#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	wopark("wopark");
	DiamondTrap	wopark2("wopark2");
	DiamondTrap	me;

	me = wopark;
	me.attack(wopark2.getName());
	wopark2.takeDamage(me.getAttackDamage());
	wopark2.beRepaired(10);
	me.guardGate();
	me.highFiveGuys();
	me.whoAmI();
	wopark2.whoAmI();
	return (0);
}