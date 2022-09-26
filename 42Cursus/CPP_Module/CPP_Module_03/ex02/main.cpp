#include "FragTrap.hpp"

int main(void)
{
	FragTrap	wopark("wopark");
	FragTrap	wopark2("wopark2");
	FragTrap	me;

	me = wopark;
	me.setAttackDamage(20);
	me.attack(wopark2.getName());
	wopark2.takeDamage(me.getAttackDamage());
	wopark2.beRepaired(20);
	me.highFiveGuys();
	return (0);
}