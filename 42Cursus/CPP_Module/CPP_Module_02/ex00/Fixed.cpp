#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->fp_value = 0;
}

Fixed::Fixed(Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

/*
**	연산자 오버로딩
**	(=) : 할당 연산자 (assignment Operator)
**	우측에 할당한 내용을 상수 참조로 받음
**	왼쪽만 변경하고 오른쪽은 변경하지 않음
*/
Fixed&	Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Assignment operator called\n";
	this->fp_value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return this->fp_value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->fp_value = raw;
}
