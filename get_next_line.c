#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char *new_line;
	ssize_t	bytes_read;
	char *tmp;

	new_line = NULL;
	if (fd > FOPEN_MAX || fd < 0)
		return (NULL);
	if (!buffer[fd][0])
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read == -1)
		{
			buffer[fd][0] = '\0';
			return (NULL);
		}
		buffer[fd][bytes_read] = '\0';
	}
	else
		bytes_read = ft_strlen(buffer[fd]);
	while (bytes_read)
	{
		new_line = ft_strjoin_gnl(&new_line, buffer[fd]);
		if (!new_line)
			return (NULL);
		tmp = strchr(new_line, '\n');
		if (tmp)
		{
			tmp++;
			strncpy(buffer[fd], tmp, BUFFER_SIZE + 1);
			*tmp = '\0';
			return (new_line);
		}
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read == -1)
		{
			buffer[fd][0] = '\0';
			if (new_line)
				free(new_line);
			return (NULL);
		}
		buffer[fd][bytes_read] = '\0';
	}
	return (new_line);
}