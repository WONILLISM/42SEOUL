#include <iostream>
#include <fstream>
#include <string>

int	error_msg(int i)
{
	if (i == 0)
		std::cout << "Cannot open the file!\n";
	else if (i == 1)
		std::cout << "File is empty\n";
	else if (i == 2)
		std::cout << "s1 or s2 is empty\n";
	else if (i == 3)
		std::cout << "Failed to create new file!!\n";
	else if (i == 4)
		std::cout << "Wrong argument!!\n";
	return (1);
}
int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		std::ifstream	file(argv[1]);
		if (!file.is_open())
			return error_msg(0);
		if (file.peek() == EOF)
			return error_msg(1);
		std::string		line;
		std::string		s1 = argv[2];
		std::string		s2 = argv[3];
		if (s1.empty() || s2.empty())
			return error_msg(2);
		std::string		extention = ".replace";
		std::string		new_file = argv[1] + extention;
		std::ofstream	replace_file(new_file);
		if (!replace_file.is_open())
			return error_msg(3);
		int		iter;
		while (file)
		{
			getline(file, line);
			iter = 0;
			while (1)
			{
				iter = line.find(s1, iter);
				if (iter == -1)
				{
					replace_file << line;
					if (!file.eof())
						replace_file << "\n";
					break;
				}
				else
				{
					line = line.insert(iter, s2).erase(iter + s2.length(), s1.length());
					iter += s2.length();
				}
			}
		}
	}
	else
		return error_msg(4);
	return (0);
}