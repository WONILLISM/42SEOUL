#ifndef AMateria_HPP
# define AMateria_HPP
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	_type;
public:
	AMateria() {}
	AMateria(std::string const & type);
	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria& copy);
	virtual ~AMateria() {}
	std::string	const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif