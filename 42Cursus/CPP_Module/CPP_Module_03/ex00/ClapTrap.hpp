#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <iostream>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hp;
	unsigned int	_mp;
	unsigned int	_dmg;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& copy);
	~ClapTrap();
	void	attack(std::string const& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif