#include "pbqueue.hpp"

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
	this->pb[this->r].set_firstname(last_name);
	std::cout << "nick name : ";
	std::cin >> nick_name;
	this->pb[this->r].set_firstname(nick_name);
	std::cout << "phone number : ";
	std::cin >> phone_number;
	this->pb[this->r].set_firstname(phone_number);
	std::cout << "darkest secret : ";
	std::cin >> darkest_secret;
	this->pb[this->r].set_firstname(darkest_secret);
	this->r++;
}