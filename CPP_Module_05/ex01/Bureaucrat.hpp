#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Form;

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
	Bureaucrat() {}

public:
	class GradeTooHighException: public std::exception
	{
	public:
		GradeTooHighException() {}
		virtual ~GradeTooHighException() throw() {}
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		GradeTooLowException() {}
		virtual ~GradeTooLowException() throw() {}
		virtual const char* what() const throw();
	};

	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	~Bureaucrat() {}
	std::string const & getName() const;
	int getGrade() const;
	void incGrade();
	void decGrade();
	void signForm(Form& form);
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& src);

#endif