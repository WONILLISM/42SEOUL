#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat: public Animal    // inherit Animal class
{
public:
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& copy);
	virtual ~Cat();
	virtual void	makeSound() const;
};
#endif