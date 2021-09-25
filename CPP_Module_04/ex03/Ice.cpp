#include "Ice.hpp"

Ice& Ice::operator=(const Ice& copy){
	if (this != &copy)
		AMateria::operator=(copy);
	return *this;
}
AMateria* Ice::clone() const {
	return new Ice();
}
void	Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << "\n";
}