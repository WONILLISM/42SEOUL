#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential Pardon Form", false, 25, 5) {
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): Form(copy) {
	this->_target = copy.getTarget();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	this->Form::operator=(copy);
	this->_target = copy.getTarget();
	return *this;
}

std::string const & PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const & exec) const {
	if (this->getSigned() == false)
		throw NotSignedException();
	else if (exec.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}