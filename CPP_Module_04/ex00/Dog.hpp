#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog: public Animal    // inherit Animal class
{
public:
	Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog& copy);
	virtual ~Dog();
	virtual void	makeSound() const;
};
#endif