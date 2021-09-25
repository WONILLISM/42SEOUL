#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	Animal(const Animal& copy);
	Animal& operator=(const Animal& copy);
	virtual ~Animal();
	std::string const	&getType() const;
/*
** 추상클래스는 함수를 재정의하지 않으면 코드상에서 오류로 판단한다.
** 일반적인 가상함수도 재정의가 가능하지만 무조건적이지 않아 실수를 할 수 있다.
*/
	virtual void		makeSound() const = 0;
};

#endif