#include "AMateria.hpp"

AMateria::AMateria(std::string const & type){
	this->_type = type;
}

AMateria::AMateria(const AMateria& copy){
	*this = copy;
}
AMateria& AMateria::operator=(const AMateria& copy){
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}
std::string	const & AMateria::getType() const{
	return this->_type;
}
void AMateria::use(ICharacter& target){
	(void)target;
	std::cout << "AMateria use\n";
}