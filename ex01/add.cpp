#include "phonebook.hpp"

void	Phonebook::add_contact(void)
{
	std::string	items[5] = {
		"first_name",
		"last_name",
		"nick_name",
		"phone_number",
		"darkest_secret"
	};
	std::string	s;
	int	i;

	i = 0;
	while (i < 5)
	{
		std::cout << items[i] << ":" << std::endl;

		std::getline(std::cin, s);
		if (s.empty())
			std::cout << "input " << items[i] << ":" << std:::endl;

		i++;
	}
}
