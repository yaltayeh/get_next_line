#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char *new_line;
	ssize_t	bytes_read;
	char *tmp;

	new_line = NULL;
	if (fd > FOPEN_MAX || fd < 0)
		return (NULL);
	if (!buf[fd][0])
	{
		bytes_read = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes_read == -1)
		{
			buf[fd][0] = '\0';
			return (NULL);
		}
		buf[fd][bytes_read] = '\0';
	}
	else
		bytes_read = strlen(buf[fd]);
	while (bytes_read)
	{
		new_line = ft_strjoin(new_line, buf[fd]);
		if (!new_line)
			return (NULL);
		tmp = strchr(new_line, '\n');
		if (tmp)
		{
			tmp++;
			strlcpy(buf[fd], tmp, BUFFER_SIZE + 1);
			*tmp = '\0';
			return (new_line);
		}
		bytes_read = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes_read == -1)
		{
			buf[fd][0] = '\0';
			if (new_line)
				free(new_line);
			return (NULL);
		}
		buf[fd][bytes_read] = '\0';
	}
	return (new_line);
}