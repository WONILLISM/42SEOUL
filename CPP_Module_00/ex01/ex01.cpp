#include "includes/ex01.hpp"

int	main(void)
{
	PB_queue	pb_queue;
	std::string	cmd;

	while (!std::cin.eof())
	{
		std::cout << "Input Command (EXIT, ADD, SEARCH):" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
			break;
		else if (cmd.compare("ADD") == 0)
		{
			pb_queue.push_contact();
		}
		// else if (cmd.compare("SEARCH") == 0)
		// {

		// }
	}
	return (0);
}
