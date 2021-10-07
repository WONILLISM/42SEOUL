#include "Form.hpp"

Form::Form(
	std::string name, 
	bool isSigned, 
	int signGrade, 
	int execGrade
): _name(name),  _isSigned(isSigned), _signGrade(signGrade), _execGrade(execGrade) {}

Form::Form(
	const Form& copy
): _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
	*this = copy;
}

Form& Form::operator=(const Form& copy) {
	this->_isSigned = copy._isSigned;
	return *this;
}

std::string const & Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_isSigned;
}

int Form::getSignGrade() const{
	return this->_signGrade;
}

int Form::getExecGrade() const {
	return this->_execGrade;
}

void Form::setSigned(bool b) {
	this->_isSigned = b;
}

void Form::beSigned(Bureaucrat& bc) {
	if (bc.getGrade() > this->_signGrade)
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "The grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "The grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Form& src) {
	out << src.getName() << std::endl;
	out << "Sign Grade: " << src.getSignGrade() << std::endl;
	out << "Execute Grade is " << src.getExecGrade() << std::endl;
	if (src.getSigned())
		out << "is signed" << std::endl;
	else
		out << "is not signed" << std::endl;
	return out;
}