#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE	10
# endif

# define _SUC_READ		1
# define _EOF			0
# define _ERROR			-1

int		get_next_line(int fd, char **line);

char	*gnl_strchr(const char *s, int c);
char	*gnl_strndup(const char *src, size_t n);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *s);
void	*gnl_memcpy(void *dst, const void *src, size_t n);
#endif
