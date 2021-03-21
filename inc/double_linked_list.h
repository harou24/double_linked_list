#ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H

#include <stddef.h>

typedef struct	s_doubly_linked_node
{
	void	*content;
	struct	s_doubly_linked_node	*next;
	struct	s_doubly_linked_node	*prev;
}		t_doubly_linked_node;

typedef struct	s_doubly_linked_list
{
	t_doubly_linked_node	*first;
	t_doubly_linked_node	*last;
}		t_doubly_linked_list;

t_doubly_linked_list	*list_create();
t_doubly_linked_node	*node_create(void *content);
void			list_add_front(t_doubly_linked_list *list, t_doubly_linked_node *to_add);
size_t			list_size(t_doubly_linked_list *_list);
t_doubly_linked_node	*list_get_last(t_doubly_linked_list *list);
void			list_add_back(t_doubly_linked_list *list, t_doubly_linked_node *to_add);
void 			list_iter(t_doubly_linked_list *list, void (*function)(void *));
void			list_delete_item(t_doubly_linked_node *to_delete, void (*ft_delete)(void*));
void			list_clear(t_doubly_linked_list *list, void (*_ft_delete)(void*));
void 			list_destroy(t_doubly_linked_list *list, void (*ft_delete)(void *));

#endif
