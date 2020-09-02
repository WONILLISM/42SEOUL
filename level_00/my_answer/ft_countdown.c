#include <unistd.h>

int main(void)
{
	write(1, "9876543210", 11);
	return (0);
}