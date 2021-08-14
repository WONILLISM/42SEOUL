#ifndef PBQUEUE_HPP
# define PBQUEUE_HPP
# define MAX_SIZE	8
# include "phonebook.hpp"

class PB_queue
{
private:
	int l;
	int r;
	Phonebook pb[MAX_SIZE];

public:
	PB_queue()
	{
		l = 0;
		r = 0;
	}
	void	push_contact(void);
	void	pop_contact(void);
};

#endif
