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

/**
 * -    join `string1` and `string2`
 * 
 * -    make free for `string1` if exists
 * @return new malloc len `string1` + `string2` + `1`
 * -- NULL if not malloc and make free for `string1`
 */
char	*ft_strjoin(char *s1, char *s2);

#endif