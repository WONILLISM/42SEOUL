#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>

class Phonebook
{
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

public:
	void		init_phonebook(void);
	void		set_firstname(std::string first_name);
	void		set_lastname(std::string last_name);
	void		set_nickname(std::string nick_name);
	void		set_phonenumber(std::string phone_number);
	void		set_darkestsecret(std::string darkest_secret);
	std::string	get_firstname();
	std::string	get_lastname();
	std::string	get_nickname();
	std::string	get_phonenumber();
	std::string	get_darkestsecret();
};

#endif