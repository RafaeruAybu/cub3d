#include "libft.h"

static int	is_char_oneofset(char const *set, char c)
{
	if (ft_strchr(set, (int)c))
		return (1);
	return (0);
}

static char	*get_first_pos(char const *s1, char const *set)
{
	while (*s1)
	{
		if (is_char_oneofset(set, *s1))
		{
			s1++;
			continue ;
		}
		break ;
	}
	return ((char *)s1);
}

static char	*get_last_pos(char const *s1, char const *set)
{
	char	*save_s1;

	save_s1 = (char *)s1;
	if (*s1)
	{
		while (*s1)
			s1++;
		s1--;
	}
	while (s1 >= save_s1 && *s1)
	{
		if (is_char_oneofset(set, *s1))
		{
			s1--;
			continue ;
		}
		break ;
	}
	return ((char *)s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*first_pos;
	char	*last_pos;

	ptr = 0;
	if (!s1 || !set)
		return (0);
	first_pos = get_first_pos(s1, set);
	if (*first_pos == '\0')
	{
		ptr = (char *)malloc(1);
		*ptr = '\0';
		return (ptr);
	}
	last_pos = get_last_pos(s1, set);
	ptr = ft_substr(s1, first_pos - s1, (last_pos - first_pos + 1));
	if (!ptr)
		return (ptr);
	return (ptr);
}
