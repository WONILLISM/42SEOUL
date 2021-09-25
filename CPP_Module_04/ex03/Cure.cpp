#include "Cure.hpp"

Cure& Cure::operator=(const Cure& copy){
	if (this != &copy)
		AMateria::operator=(copy);
	return *this;
}
AMateria* Cure::clone() const {
	return new Cure();
}
void	Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds\n";
}