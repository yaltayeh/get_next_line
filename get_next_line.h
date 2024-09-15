#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 4096
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int	ft_strjoin_gnl(char **new_line, char *buffer);

#endif