#ifndef ROBOTOMYYREQUESTFORM_HPP
# define ROBOTOMYYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
	std::string _target;
public:
	RobotomyRequestForm(): Form("Presidential Pardon Form", false, 72, 45) {}
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
	virtual ~RobotomyRequestForm() {}
	std::string const & getTarget() const;
	virtual void execute(Bureaucrat const & exec) const;
};

#endif