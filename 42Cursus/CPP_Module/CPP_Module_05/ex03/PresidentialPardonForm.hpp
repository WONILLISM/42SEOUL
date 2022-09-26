#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
	std::string _target;
public:
	PresidentialPardonForm(): Form("Presidential Pardon Form", false, 25, 5) {}
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
	virtual ~PresidentialPardonForm() {}
	std::string const & getTarget() const;
	virtual void execute(Bureaucrat const & exec) const;
};

#endif