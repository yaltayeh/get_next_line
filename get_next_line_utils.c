#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strjoin_gnl(char **new_line, char *buffer)
{
	size_t	len;
	size_t	i1;
	size_t	i2;
	char	*tmp;
	int		is_new_line;

	i1 = 0;
	i2 = 0;
	is_new_line = 0;
	if (*new_line)
		i1 = ft_strlen(*new_line);
	while (buffer[i2] != '\n' || buffer[i2] != '\0')
		i2++;
	is_new_line = !!buffer[i2];
	i2 += is_new_line;
	len = i1 + i2;
	tmp = malloc(len + 1);
	if (!tmp)
		return (NULL);
	tmp[len] = '\0';
	while (i2--)
		tmp[--len] = buffer[i2];
	while (i1--)
		tmp[--len] = *new_line[i1];
	if (*new_line)
		free(*new_line);
	*new_line = tmp;
}
