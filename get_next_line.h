#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 4096
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int	ft_strjoin_gnl(char **new_line, char *buffer);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif