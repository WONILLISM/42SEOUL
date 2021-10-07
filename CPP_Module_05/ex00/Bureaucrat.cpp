#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	this->_grade = grade;
	if (this->_grade < 1)
		throw GradeTooHighException();
	else if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name) {
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
	this->_grade = copy._grade;
	return *this;
}

std::string const & Bureaucrat::getName() const {
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incGrade() {
	if (--(this->_grade) < 1) {
		this->_grade++;
		throw GradeTooHighException();
	}
}

void Bureaucrat::decGrade() {
	if (++(this->_grade) > 150) {
		this->_grade--;
		throw GradeTooLowException();
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Can't increase it any more.\n this grade: 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Can't decrease it any more.\n this grade: 150";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src) {
	out << src.getName() << ", grade : "<< src.getGrade() << "\n";
	return out;
}