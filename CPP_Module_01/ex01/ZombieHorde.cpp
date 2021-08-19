#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zbs = new Zombie[N];
	
	for(int i = 0; i < N; i++)
		zbs[i].set_name(name);
	return zbs;
}