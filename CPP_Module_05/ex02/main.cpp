#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void testForm(Form &form, Bureaucrat &jieun, Bureaucrat &IU) {
  std::cout << "\n=================================" << std::endl;
  jieun.signForm(form);
  std::cout << form << std::endl;

  std::cout << "---------------------------------" << std::endl;
  std::cout << form << std::endl;
  IU.executeForm(form);

  std::cout << "---------------------------------" << std::endl;
  IU.signForm(form);
  std::cout << form << std::endl;

  std::cout << "---------------------------------" << std::endl;
  std::cout << form << std::endl;
  jieun.executeForm(form);

  std::cout << "---------------------------------" << std::endl;

  std::cout << form << std::endl;
  IU.executeForm(form);

  std::cout << "=================================" << std::endl;
}

Bureaucrat *newBureaucrat(std::string name, int grade) {
  try {
    return new Bureaucrat(name, grade);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return NULL;
  }
}

int main() {
  Bureaucrat IU("IU", 1);
  Bureaucrat jieun("jieun", 150);

  ShrubberyCreationForm sform("shrubbery creation form");
  RobotomyRequestForm rform("robotomy request form");
  PresidentialPardonForm pform("presidential pardon form");

  testForm(sform, jieun, IU);
  // testForm(rform, jieun, IU);
  // testForm(pform, jieun, IU);
  return (0);
}