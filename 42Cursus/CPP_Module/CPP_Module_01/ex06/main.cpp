#include "Karen.hpp"

enum	e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	Karen			karen;
	std::string		level = argv[1];
	int				idx = -1;

	(!level.compare("DEBUG")) && (idx = DEBUG);
	(!level.compare("INFO")) && (idx = INFO);
	(!level.compare("WARNING")) && (idx = WARNING);
	(!level.compare("ERROR")) && (idx = ERROR);

	switch (idx)
	{
	case DEBUG:
		std::cout << "[DEBUG]\n";
		karen.complain("DEBUG");
	case INFO:
		std::cout << "[INFO]\n";
		karen.complain("INFO");
	case WARNING:
		std::cout << "[WARNING]\n";
		karen.complain("WARNING");
	case ERROR:
		std::cout << "[ERROR]\n";
		karen.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
	
	return (0);
}