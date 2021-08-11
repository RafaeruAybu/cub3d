#include "libft.h"

size_t	ft_strlen(const char *string)
{
	const char		*ptr;
	size_t			counter;

	ptr = string;
	counter = 0;
	while (*ptr)
	{
		ptr++;
		counter++;
	}
	return (counter);
}
