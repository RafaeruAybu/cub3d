#include "libft.h"

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
