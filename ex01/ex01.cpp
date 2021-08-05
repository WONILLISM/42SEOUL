#include "phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook[8];
	std::string	cmd;
	int	book_idx;

	book_idx = 0;
	while (!std::cin.eof())
	{
		std::cout << "Input Command (EXIT, ADD, SEARCH):" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.compare("ADD") == 0)
		{
			if (book_idx < 8)
			{
				book_idx++;
			}
		}
		else if (cmd.compare("SEARCH") == 0)
		{

		}
	}
	return (0);
}
