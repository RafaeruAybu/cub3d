#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*dst_ptr;
	const char	*src_ptr;
	size_t		count;

	dst_ptr = dst;
	src_ptr = src;
	count = dstsize;
	if ((count != 0) && (dst != 0) && (src != 0))
	{
		while (--count != 0)
		{
			*dst++ = *src++;
			if ((*dst) == '\0')
				break ;
		}
	}
	if (count == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - src_ptr - 1);
}
