#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure: public AMateria
{
public:
	Cure() : AMateria("cure") {}
	Cure(const Cure& copy): AMateria(copy) {}
	Cure& operator=(const Cure& copy);
	virtual ~Cure() {}
	virtual AMateria* clone() const;
	virtual void	use(ICharacter& target);
};
#endif