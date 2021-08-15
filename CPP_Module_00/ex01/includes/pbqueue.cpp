#include "pbqueue.hpp"

int		check_eof(std::string *ci)
{
	std::cin >> *ci;
	if (std::cin.eof())
		return (1);
	return (0);
}

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
			if (std::cin.eof())
				return ;
			if (idx >= 0 && idx < 8 && this->l + idx >= this->l && this->l + idx < this->r)
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
			else
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
	std::string	contact_item;

	if (this->r >= MAX_SIZE)
		this->pop_contact();
	std::cout << "first name : ";
	if (check_eof(&contact_item))
		return ;
	this->pb[this->r].set_firstname(contact_item);
	std::cout << "last name : ";
	if (check_eof(&contact_item))
		return ;
	this->pb[this->r].set_lastname(contact_item);
	std::cout << "nick name : ";
	if (check_eof(&contact_item))
		return ;
	this->pb[this->r].set_nickname(contact_item);
	std::cout << "phone number : ";
	if (check_eof(&contact_item))
		return ;
	this->pb[this->r].set_phonenumber(contact_item);
	std::cout << "darkest secret : ";
	if (check_eof(&contact_item))
		return ;
	this->pb[this->r].set_darkestsecret(contact_item);
	this->r++;
}