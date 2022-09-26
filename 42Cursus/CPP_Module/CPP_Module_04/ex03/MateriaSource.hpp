#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	AMateria* _materia[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& copy);
	MateriaSource& operator=(const MateriaSource& copy);
	virtual ~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif