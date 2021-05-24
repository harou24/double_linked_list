#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

#include <stddef.h>

typedef struct	s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_list
{
	t_node	*first;
	t_node	*last;
}				t_list;

t_list		*list_create();
t_node		*node_create(void *content);
void		list_add_front(t_list *list, t_node *to_add);
size_t		list_size(t_list *list);
t_node		*list_get_last(t_list *list);
void		list_add_back(t_list *list, t_node *to_add);
void 		list_iter(t_list *list, void (*ft_iter)(void *));
void		list_delete_item(t_list *list, t_node *to_delete, void (*ft_delete)(void*));
void		list_clear(t_list *list, void (*ft_delete)(void*));
void 		list_destroy(t_list *list, void (*ft_delete)(void *));

#endif
