#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(): Form("Shrubbery Creation Form", false, 145, 137) {}
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
	virtual ~ShrubberyCreationForm() {}
	std::string const & getTarget() const;
	virtual void execute(Bureaucrat const & exec) const;
};

#endif