#include "Karen.hpp"

int	main(void)
{
	Karen	karen;

	std::cout << "DEBUG: ";
	karen.complain("DEBUG");
	std::cout << "INFO: ";
	karen.complain("INFO");
	std::cout << "WARNING: ";
	karen.complain("WARNING");
	std::cout << "ERROR: ";
	karen.complain("ERROR");
	std::cout << "NOTHING: ";
	karen.complain("WOPARK");
	return (0);
}