#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(
	std::string target
): Form("Shrubbery Creation Form", false, 145, 137) {
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): Form(copy) {
	this->_target = copy.getTarget();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	this->Form::operator=(copy);
	this->_target = copy.getTarget();
	return *this;
}

std::string const & ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & exec) const {
	if (this->getSigned() == false)
		throw NotSignedException();
	else if (exec.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	
	std::ofstream f;
	f.open(this->_target + "_shrubbery");
	f << "          \%\%\%,\%\%\%\%\%\%\%" << std::endl;
  f << "        ,\'\%\% \\\\-*\%\%\%\%\%\%\%" << std::endl;
  f << "  ;\%\%\%\%\%*\%   _\%\%\%\%\"" << std::endl;
  f << "  ,\%\%\%       \\(_.*\%\%\%\%." << std::endl;
  f << "  \% *\%\%, ,\%\%\%\%*(    \'" << std::endl;
  f << "\%^     ,*\%\%\% )\\%|,\%\%*\%,_" << std::endl;
  f << "      *\%    \\/ #).-\"*\%\%*" << std::endl;
  f << "          _.) ,/ *\%," << std::endl;
  f << "  _________/)#(_____________" << std::endl;
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}