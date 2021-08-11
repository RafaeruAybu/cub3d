#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		ch;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	if (n != 0)
	{
		while (n-- != 0)
		{
			if (*ptr++ == ch)
				return ((void *)(ptr - 1));
		}
	}
	return (0);
}
