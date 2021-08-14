#include "pbqueue.hpp"

void	PB_queue::show_contacts(void)
{
	std::cout << "Phonebook List\n";
	std::cout << " INDEX |  FIRST NAME  |  LAST NAME  |  NICK NAME  \n";
	std::cout << "=================================================\n";
	for (int i = 0; i < this->r - this->l; i++)
	{
		std::cout.width(6);
		std::cout << i << " |";
		std::cout.width(13);
		std::cout << this->pb[this->l + i].get_firstname() << " |";
		std::cout.width(12);
		std::cout << this->pb[this->l + i].get_lastname() << " |";
		std::cout.width(11);
		std::cout << this->pb[this->l + i].get_nickname() << "\n";
	}
}

void	PB_queue::search_contact(void)
{
	int	idx;

	if (l == r)
	{
		std::cout << "Empty Phonebook\n";
		return ;
	}
	else
	{
		this->show_contacts();
		while (1)
		{
			std::cout << "\nInput Index : ";
			std::cin >> idx;
			if (this->l + idx >= this->l && this->l + idx < this->r)
			{
				std::cout << "=================================================\n";
				std::cout << "first name : ";
				std::cout << this->pb[this->l + idx].get_firstname() << "\n";
				std::cout << "last name : ";
				std::cout << this->pb[this->l + idx].get_lastname() << "\n";
				std::cout << "nick name : ";
				std::cout << this->pb[this->l + idx].get_nickname() << "\n";
				std::cout << "phone number : ";
				std::cout << this->pb[this->l + idx].get_phonenumber() << "\n";
				std::cout << "darkest secret : ";
				std::cout << this->pb[this->l + idx].get_darkestsecret() << "\n";
				std::cout << "=================================================\n";
				break;
			}
			std::cout << "Wrong Index, can't find this Index.\n";
		}
	}
}

void	PB_queue::pop_contact(void)
{
	if (this->r == this->l)
		std::cout << "Empty Book\n";
	this->pb[this->l++].init_phonebook();
}

void	PB_queue::push_contact(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

	if (this->r >= MAX_SIZE)
		this->pop_contact();
	std::cout << "first name : ";
	std::cin >> first_name;
	this->pb[this->r].set_firstname(first_name);
	std::cout << "last name : ";
	std::cin >> last_name;
	this->pb[this->r].set_lastname(last_name);
	std::cout << "nick name : ";
	std::cin >> nick_name;
	this->pb[this->r].set_nickname(nick_name);
	std::cout << "phone number : ";
	std::cin >> phone_number;
	this->pb[this->r].set_phonenumber(phone_number);
	std::cout << "darkest secret : ";
	std::cin >> darkest_secret;
	this->pb[this->r].set_darkestsecret(darkest_secret);
	this->r++;
}