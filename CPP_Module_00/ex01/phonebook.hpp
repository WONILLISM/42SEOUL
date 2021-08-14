#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define MAX_SIZE	8
# include <iostream>
# include <string>

class Phonebook
{
private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

public:
	void	push_contact(void);
	void	set_firstname(std::string first_name);
	void	set_lastname(std::string last_name);
	void	set_nickname(std::string nick_name);
	void	set_phonenumber(std::string phone_number);
	void	set_darkestsecret(std::string darkest_secret);
};

#endif