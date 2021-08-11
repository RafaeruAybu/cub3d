#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*ptr;
	size_t				count;

	count = 0;
	ptr = s;
	if (n != 0)
	{
		while (count < n)
		{
			*ptr = '\0';
			ptr++;
			count++;
		}
	}
}
