#include "philosophers.h"

long	microtomilli()
{
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	return (tmp.tv_sec * 1000L + tmp.tv_usec / 1000L);
}

void	ft_sleep(long t, long cur)
{
	long	res;
	long	tmp;

	res = cur + t;
	while (microtomilli() < res)
		usleep((long)((res - microtomilli())/2) * 1000L);
}
