#ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H

#include <stddef.h>

typedef struct	s_list
{
	void	*content;
	struct	s_list	*next;
	struct	s_list	*prev;
}		t_list;

t_list	*list_create(void *content);
void	list_add_front(t_list **_list, t_list *_to_add);
size_t	list_size(t_list *_list);
t_list	*list_get_last(t_list *_beggining);
void	list_add_back(t_list **_list, t_list *_to_add);
void	list_delete_item(t_list *_to_free, void (*_ft_delete)(void*));
void	list_clear(t_list **_list, void (*_ft_delete)(void*));
void 	list_iter(t_list *_element, void (*_ft_iterator)(void *));

#endif
