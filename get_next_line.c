#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char *new_line;
	ssize_t	bytes_read;
	int		ret;

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
		if (ft_strjoin_gnl(&new_line, buffer[fd]) == 1)
			return (new_line);
		if (!new_line)
		{
			buffer[fd][0] = '\0';
			return (NULL);
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