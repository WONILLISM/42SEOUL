#include "phonebook.hpp"

void	Phonebook::set_firstname(std::string first_name)
{
	this->first_name = first_name;
}

void	Phonebook::set_lastname(std::string last_name)
{
	this->last_name = last_name;
}

void	Phonebook::set_nickname(std::string nick_name)
{
	this->nick_name = nick_name;
}

void	Phonebook::set_phonenumber(std::string phone_number)
{
	this->phone_number = phone_number;
}

void	Phonebook::set_darkestsecret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

void	Phonebook::push_contact(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "first name : ";
	std::cin >> first_name;
	this->set_firstname(first_name);
	std::cout << "last name : ";
	std::cin >> last_name;
	this->set_firstname(last_name);
	std::cout << "nick name : ";
	std::cin >> nick_name;
	this->set_firstname(nick_name);
	std::cout << "phone number : ";
	std::cin >> phone_number;
	this->set_firstname(phone_number);
	std::cout << "darkest secret : ";
	std::cin >> darkest_secret;
	this->set_firstname(darkest_secret);
}
