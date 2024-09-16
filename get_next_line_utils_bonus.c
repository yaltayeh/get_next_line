/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:35:16 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/09/16 11:35:18 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	while (i < len && size && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	return (len);
}

static int	ft_strjoin_gnl_help(char **new_line_p, char *buffer, \
									size_t i1, size_t i2)
{
	char	*new_line;
	size_t	len;
	char	*left;

	left = buffer + i2;
	len = i1 + i2;
	new_line = malloc(len + 1);
	if (!new_line)
	{
		if (*new_line_p)
			free(*new_line_p);
		*new_line_p = NULL;
		return (0);
	}
	new_line[len] = '\0';
	while (i2--)
		new_line[--len] = buffer[i2];
	while (i1--)
		new_line[--len] = *new_line_p[i1];
	if (*new_line_p)
		free(*new_line_p);
	*new_line_p = new_line;
	ft_strlcpy(buffer, left, BUFFER_SIZE  + 1);
	return (1);
}

int	ft_strjoin_gnl(char **new_line, char *buffer)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	if (*new_line)
		i1 = ft_strlen(*new_line);
	while (buffer[i2] != '\n' && buffer[i2] != '\0')
		i2++;
	i2 += !!buffer[i2];
	return (ft_strjoin_gnl_help(new_line, buffer, i1, i2));
}
