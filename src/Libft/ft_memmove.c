#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	unsigned char		*src_ptr;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if ((len != 0) && (dst != src))
	{
		if (dst < src)
		{
			while (len-- != 0)
				*dst_ptr++ = *src_ptr++;
		}
		else
		{
			dst_ptr += len - 1;
			src_ptr += len - 1;
			while (len-- != 0)
				*dst_ptr-- = *src_ptr--;
		}
	}
	return (dst);
}
