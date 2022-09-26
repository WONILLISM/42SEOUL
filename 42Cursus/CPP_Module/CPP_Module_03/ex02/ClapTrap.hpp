#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <iostream>

class ClapTrap
{
protected:
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
	virtual void	attack(std::string const& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			setName(std::string name);
	void			setHitPoints(unsigned int amount);
	void			setEnergyPoints(unsigned int amount);
	void			setAttackDamage(unsigned int amount);
	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergePoints() const;
	unsigned int	getAttackDamage() const;
};

#endif