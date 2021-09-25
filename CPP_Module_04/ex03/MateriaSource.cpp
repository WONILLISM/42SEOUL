#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy){
	for (int i = 0; i < 4; i++)
		this->_materia[i] = copy._materia[i]->clone();
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++){
		if (this->_materia[i] != NULL){
			delete this->_materia[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* materia){
	for (int i = 0; i < 4; i++){
		if (this->_materia[i] == NULL){
			this->_materia[i] = materia;
			break;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const & type){
	if (type != "ice" && type != "cure")
		return 0;
	for (int i = 0; i < 4; i++)
		if (this->_materia[i] && !this->_materia[i]->getType().compare(type))
			return this->_materia[i]->clone();
	return 0;
}