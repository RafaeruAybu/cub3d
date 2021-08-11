#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_ptr;
	unsigned char		*src_ptr;
	unsigned char		ch;
	void				*ret_ptr;
	size_t				count;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	ch = (unsigned char)c;
	ret_ptr = dst;
	count = 0;
	if (n != 0)
	{
		while (count < n)
		{
			*dst_ptr++ = *src_ptr++;
			if ((*dst_ptr) == ch)
				return (dst_ptr);
			ret_ptr++;
			count++;
		}
	}
	return (0);
}
