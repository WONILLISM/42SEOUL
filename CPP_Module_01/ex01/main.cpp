#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);
int main(void)
{
	Zombie	*zbs = zombieHorde(5, "wopark");
	for(int i = 0; i < 5; i++)
		zbs[i].announce();
	delete[] zbs;
	return (0);
}