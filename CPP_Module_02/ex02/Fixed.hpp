#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int		fp_value;						// fixed point value
	static int	const	fractional_bit = 8;	// frational_bit (소수 비트)
public:
	Fixed();								// 생성자
	Fixed(int const int_val);				// 정수 초기화 생성자
	Fixed(float const float_val);			// 소수 초기화 생성자
	Fixed(const Fixed &copy);				// 복사 생성자
	~Fixed();								// 소멸자
	/*
	**		대입 연산자 오버로딩
	*/
	Fixed&				operator=(const Fixed &copy);
	/*
	**		사칙 연산자 오버로딩
	*/
	Fixed				operator+(const Fixed &src) const;
	Fixed				operator-(const Fixed &src) const;
	Fixed				operator*(const Fixed &src) const;
	Fixed				operator/(const Fixed &src) const;
	/*
	**		전위 연산자 오버로딩
	*/
	Fixed&				operator++(void);
	Fixed&				operator--(void);
	/*
	**		전위 연산자 오버로딩
	*/
	Fixed				operator++(int tmp);
	Fixed				operator--(int tmp);
	/*
	**		비교 연산자 오버로딩
	*/
	bool				operator>(const Fixed &src) const;
	bool				operator<(const Fixed &src) const;
	bool				operator>=(const Fixed &src) const;
	bool				operator<=(const Fixed &src) const;
	bool				operator==(const Fixed &src) const;
	bool				operator!=(const Fixed &src) const;

	int					getRawBits(void) const;			// 원시 고정 소수점 값 반환
	void				setRawBits(int const raw);		// 원시 고정 소수점 설정
	float				toFloat(void) const;			// 고정 소수점을 부동소수점으로 변환
	int					toInt(void) const;				// 고정 소수점을 정수로 변환
	static Fixed&		min(Fixed& f1, Fixed& f2);
	static const Fixed&	min(const Fixed& f1, const Fixed& f2);
	static Fixed&		max(Fixed& f1, Fixed& f2);
	static const Fixed&	max(const Fixed& f1, const Fixed& f2);
};
std::ostream& operator<<(std::ostream& outStream, const Fixed& src);
#endif