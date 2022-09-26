#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int		fp_value;						// fixed point value
	static int	const	fractional_bit = 8;	// frational_bit (소수 비트)
public:
	Fixed();								// 생성자
	Fixed(Fixed &fixed);					// 고정 소수점 값을 0으로 초기화하는 기본 생성자.
	Fixed& operator=(const Fixed &copy);	// 복사 생성자
	~Fixed();								// 소멸자
	int		getRawBits(void) const;			// 원시 고정 소수점 값 반환
	void	setRawBits(int const raw);		// 원시 고정 소수점 설정
};
#endif