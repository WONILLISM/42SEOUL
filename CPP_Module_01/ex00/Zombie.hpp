#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
private:
	std::string _name;

public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	
	void		announce(void);
	void		set_name(std::string name);
	std::string	get_name(void);
};
#endif