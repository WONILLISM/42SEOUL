#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fp_value = 0;
	std::cout << "Call Default Constructor\n";
}

Fixed::Fixed(Fixed &copy)
{
	*this = copy;
	std::cout << "Call Copy Constructor\n";
}

/*
**	연산자 오버로딩
**	(=) : 할당 연산자 (assignment Operator)
**	우측에 할당한 내용을 상수 참조로 받음
**	왼쪽만 변경하고 오른쪽은 변경하지 않음
*/
Fixed&	Fixed::operator=(const Fixed& fixed)
{
	this->fp_value = fixed.getRawBits();
	std::cout << "Call Assignment Operator\n";
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Call Destructor\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "Call getRawBits member function\n";
	return this->fp_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->fp_value = raw;
	std::cout << "Call setRawBits member function\n";
}
