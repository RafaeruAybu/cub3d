#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

t_list			*ft_create_elem(void *data);
t_list			*ft_list_last(t_list *begin_list);
void			ft_list_push_back(t_list **begin_list, void *data);
void			ft_list_clear(t_list *begin_list);
void			print_list(t_list *begin_list);

#endif
