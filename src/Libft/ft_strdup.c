#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*ptr;
	char	*tmp;

	size = ft_strlen(s1);
	ptr = malloc(size + 1);
	tmp = ptr;
	if (ptr == 0)
		return (ptr);
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (tmp);
}
