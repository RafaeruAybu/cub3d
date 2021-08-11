NAME =		libft.a

GCC =		gcc

CFLAGS =	-Wall -Wextra -Werror

RM =		/bin/rm -rf

LIBSRCS =	ft_bzero.c\
			ft_memccpy.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_calloc.c\
			ft_strchr.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_atoi.c\
			ft_substr.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c

OBJS =		$(LIBSRCS:.c=.o)

ARRC =		ar rc

.c.o:
			$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o) -I .

$(NAME):	$(OBJS)
			$(ARRC) $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

