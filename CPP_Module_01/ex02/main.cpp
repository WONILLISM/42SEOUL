#include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR;
	std::string	&stringREF = str;

	stringPTR = &str;
	std::cout << "string : " << &str << "\n";
	std::cout << "stringOrigin : " << str << "\n";
	std::cout << "stringPTR : " << stringPTR << "\n";
	std::cout << "stringOrigin : " << *stringPTR << "\n\n";
	std::cout << "stringREF : " << &stringREF << "\n";
	std::cout << "stringOrigin : " << stringREF << "\n\n";
	return (0);
}