#include "phonebook.hpp"

void	Phonebook::init_phonebook(void)
{
	this->first_name = "";
	this->last_name = "";
	this->nick_name = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

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

std::string	Phonebook::get_firstname()
{
	return this->first_name;
}

std::string	Phonebook::get_lastname()
{
	return this->last_name;
}

std::string	Phonebook::get_nickname()
{
	return this->nick_name;
}

std::string	Phonebook::get_phonenumber()
{
	return this->phone_number;
}

std::string	Phonebook::get_darkestsecret()
{
	return this->darkest_secret;
}
