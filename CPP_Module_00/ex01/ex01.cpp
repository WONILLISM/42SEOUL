#include "phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook[MAX_SIZE];
	std::string	cmd;
	int			l;
	int			r;

	l = r = 0;
	while (!std::cin.eof())
	{
		std::cout << "Input Command (EXIT, ADD, SEARCH):" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.compare("ADD") == 0)
		{
			std::cout<<l<<" "<<r<<std::endl;
			if (r >= MAX_SIZE)
				l++;
			phonebook[r % MAX_SIZE].push_contact();
			r++;
		}
		// else if (cmd.compare("SEARCH") == 0)
		// {

		// }
	}
	return (0);
}
