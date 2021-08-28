#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->fp_value = 0;
}

Fixed::Fixed(int const int_val)
{
	std::cout << "Int constructor called\n";
	this->fp_value = int_val << this->fractional_bit;
}

Fixed::Fixed(float const float_val)
{
	std::cout << "Float constructor called\n";
	this->fp_value = (int)roundf(float_val * (1 << this->fractional_bit));
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

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
	return this->fp_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->fp_value = raw;
}

float	Fixed::toFloat(void) const
{
	return this->fp_value / (float)(1 << fractional_bit);
}

int	Fixed::toInt(void) const
{
	return (this->fp_value >> fractional_bit);
}

std::ostream& operator<<(std::ostream& o_stream, const Fixed& src)
{
	o_stream << src.toFloat();
	return o_stream;
}