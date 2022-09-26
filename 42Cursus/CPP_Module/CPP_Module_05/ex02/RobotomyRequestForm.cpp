#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", false, 72, 45)
{
  this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy)
{
  this->_target = copy.getTarget();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
  this->Form::operator=(copy);
  this->_target = copy.getTarget();
  return *this;
}

std::string const &RobotomyRequestForm::getTarget() const
{
  return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &exec) const
{
  if (this->getSigned() == false)
    throw NotSignedException();
  else if (exec.getGrade() > this->getExecGrade())
    throw GradeTooLowException();
  std::cout << "DDDDZZZZZZZZZ!!! DDZZZZZZZZZ!!!" << std::endl;
	if (std::rand() % 2 == 0)
  	std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
	else
		std::cout << this->_target << ", It's a failure." << std::endl;
}