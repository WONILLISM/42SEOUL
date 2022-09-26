#include "Character.hpp"

Character::Character(std::string const & name){
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

Character::Character(const Character& copy){
	this->_name = copy._name;
	for(int i = 0; i < 4; i++)
		this->_materia[i] = copy._materia[i]->clone();
}

Character& Character::operator=(const Character& copy){
	if (this != &copy){
		this->_name = copy._name;
		for (int i = 0; i < 4; i++)
			this->_materia[i] = copy._materia[i]->clone();
	}
	return *this;
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
}

std::string const & Character::getName() const{
	return this->_name;
}

void Character::equip(AMateria* materia){
	for (int i = 0; i < 4; i++){
		if (this->_materia[i] == NULL){
			this->_materia[i] = materia;
			break;
		}
	}
}

void Character::unequip(int idx){
	if (idx >= 0 && idx < 4)
		this->_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx < 4 && this->_materia[idx] != NULL)
		this->_materia[idx]->use(target);
}
