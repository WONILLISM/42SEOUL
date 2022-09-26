#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "";
	}
	std::cout << "Brain Constructor is called\n";
}

Brain::Brain(const Brain& copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.getIdea(i);
}

Brain& Brain::operator=(const Brain& copy)
{
	if (this != &copy) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = copy.getIdea(i);
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor is called\n";
}

std::string const &Brain::getIdea(int idx) const
{
	return this->ideas[idx];
}

void	Brain::setIdea(int idx, std::string idea)
{
	this->ideas[idx] = idea;
}
