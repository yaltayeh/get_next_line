#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i1;
	size_t	i2;

	len = 1;
	if (s1)
		len += strlen(s1);
	if (s2)
		len += strlen(s2);
	char *ret = malloc(len);
	if (!ret)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	i1 = 0;
	if (s1)
	{
		while (s1[i1])
		{
			ret[i1] = s1[i1];
			i1 ++;
		}
		free(s1);
	}
	i2 = 0;
	if (s2)
		while (s2[i2])
		{
			ret[i1 + i2] = s2[i2];
			i2++;
		}
	// printf("i1: %zu, i2: %zu, len: %zu\n", i1, i2, len);
	ret[i1 + i2] = '\0';
	// printf("s1: %s\ns2: %s\nret: %s\n", s1, s2, ret);
	// printf("ret0: %d\n", ret[1]);
	return (ret);
}

char	*ft_substr();