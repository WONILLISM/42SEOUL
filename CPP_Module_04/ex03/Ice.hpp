#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice() : AMateria("ice") {}
	Ice(const Ice& copy): AMateria(copy) {}
	Ice& operator=(const Ice& copy);
	virtual ~Ice() {}
	virtual AMateria* clone() const;
	virtual void	use(ICharacter& target);
};
#endif