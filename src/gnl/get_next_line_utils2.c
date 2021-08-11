#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	general_size;
	char	*ptr;
	char	*save_ptr;

	if (!s1 || !s2)
		return (0);
	general_size = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(general_size + 1);
	if (!ptr)
		return (ptr);
	save_ptr = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (save_ptr);
}

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			count;

	count = 0;
	ptr = dst;
	if (n != 0)
	{
		while (count < n)
		{
			*ptr = (unsigned char)c;
			ptr++;
			count++;
		}
	}
	return (dst);
}

int	ft_memdel(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
