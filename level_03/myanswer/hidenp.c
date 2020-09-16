#include <unistd.h>

int main(int argc, char **argv)
{
	char *s1;
	char *s2;
	
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];

		while (*s2 && *s1)
		{
			if (*s1 == *s2)
				s1++;
			s2++;
		}
		if (!*s1) 
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}