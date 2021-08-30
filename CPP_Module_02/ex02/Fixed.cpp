#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fp_value = 0;
}

Fixed::Fixed(int const int_val)
{
	this->fp_value = int_val << this->fractional_bit;
}

Fixed::Fixed(float const float_val)
{
	this->fp_value = (int)roundf(float_val * (1 << this->fractional_bit));
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}


Fixed::~Fixed(){}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	this->fp_value = fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &src) const
{
	Fixed	ret;

	ret.setRawBits(this->fp_value + src.fp_value);
	return ret;
}

Fixed	Fixed::operator-(const Fixed &src) const
{
	Fixed	ret;

	ret.setRawBits(this->fp_value - src.fp_value);
	return ret;
}

Fixed	Fixed::operator*(const Fixed &src) const
{
	Fixed	ret;

	ret.setRawBits((this->fp_value * src.fp_value) / (1 << src.fractional_bit));
	return ret;
}

Fixed	Fixed::operator/(const Fixed &src) const
{
	Fixed	ret;

	ret.setRawBits((this->fp_value / src.fp_value) * (1 << src.fractional_bit));
	return ret;
}

Fixed&	Fixed::operator++(void)
{
	this->fp_value++;
	return *this;
}

Fixed&	Fixed::operator--(void)
{
	this->fp_value--;
	return *this;
}

Fixed	Fixed::operator++(int tmp)
{
	Fixed	ret = *this;

	(void)tmp;
	this->fp_value++;
	return ret;
}

Fixed	Fixed::operator--(int tmp)
{
	Fixed	ret = *this;

	(void)tmp;
	this->fp_value--;
	return ret;
}

bool	Fixed::operator>(const Fixed &src) const
{
	return this->fp_value > src.fp_value;
}

bool	Fixed::operator<(const Fixed &src) const
{
	return this->fp_value < src.fp_value;
}
bool	Fixed::operator>=(const Fixed &src) const
{
	return this->fp_value >= src.fp_value;
}
bool	Fixed::operator<=(const Fixed &src) const
{
	return this->fp_value <= src.fp_value;
}
bool	Fixed::operator==(const Fixed &src) const
{
	return this->fp_value == src.fp_value;
}
bool	Fixed::operator!=(const Fixed &src) const
{
	return this->fp_value != src.fp_value;
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

std::ostream& operator<<(std::ostream& outStream, const Fixed& src)
{
	outStream << src.toFloat();
	return outStream;
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}