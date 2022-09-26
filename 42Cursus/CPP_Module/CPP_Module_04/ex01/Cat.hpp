#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& copy);
/*
** 클래스 내부에서 메모리를 동적할당하는 경우 소멸자에서 메모리 해제를 해주는데,
** 상속받은 부모의 소멸자가 가상 소멸자가 아닌 경우 객체 생성시 실제 객체의 클래스가 아닌,
** 생성된 포인터 자료형에 따라 소멸자가 호출된다.
** 결국 부모 클래스의 소멸자만 호출되고 메모리 누수가 발생한다. 
** 하여 다형성을 지원할 수 있는 기본 클래스의 경우 소멸자를 가상함수로 지정해 놓아야한다.
*/
	virtual ~Cat();
	virtual void	makeSound() const;
	Brain* getBrain() const;
};
#endif