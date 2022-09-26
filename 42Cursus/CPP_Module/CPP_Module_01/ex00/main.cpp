#include "Zombie.hpp"

void	randomCump(std::string name);
Zombie	*newZombie(std::string name);
int main(void)
{
	Zombie	zb1 = Zombie("wopark1");
	zb1.announce();

	Zombie	*zb2 = newZombie("wopark2");
	zb2->announce();
	delete zb2;
	randomCump("stack_zb");
	return (0);
}