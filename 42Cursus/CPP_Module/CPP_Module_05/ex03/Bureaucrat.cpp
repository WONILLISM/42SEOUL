#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	this->_grade = grade;
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

void Bureaucrat::signForm(Form& form)
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
		form.setSigned(true);

	}
	catch(const std::exception& e) {
		std::cerr << "Sign grade is too low.\n";
		std::cerr << this->getName() << " can't sign " << form.getName() << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form) {
	try
	{
		form.execute(*this);
		std::cout << this->_name << " execute " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " can't execute " << form.getName() << std::endl;
		std::cerr << e.what() << '\n';
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