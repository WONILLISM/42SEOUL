#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Form 
{
private:
	std::string	const _name;
	bool	_isSigned;
	const int	_signGrade;
	const int	_execGrade;
	Form(): _isSigned(false), _signGrade(0), _execGrade(0) {}

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
	class NotSignedException: public std::exception
	{
	public:
		NotSignedException() {}
		virtual ~NotSignedException() throw() {}
		virtual const char* what() const throw();
	};

	Form(std::string name, bool isSigned, int sign, int exec);
	Form(const Form& copy);
	Form& operator=(const Form& copy);
	~Form() {}
	std::string const & getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void setSigned(bool b);
	void beSigned(Bureaucrat& bc);
	virtual void execute(Bureaucrat const & exec) const = 0;
};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif