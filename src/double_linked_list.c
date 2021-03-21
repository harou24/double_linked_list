#include "double_linked_list.h"
#include <stdlib.h>

t_list	*list_create(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	list_add_front(t_list **list_head, t_list *to_add)
{
	to_add->next = *list_head;
	to_add->prev = NULL;
	*list_head = to_add;
}

size_t	list_size(t_list *list)
{
	int	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

t_list	*list_get_last(t_list *list)
{
	while (list)
	{
		list = list->next;
	}
	return (list);
}

void	list_add_back(t_list **list, t_list *to_add)
{
	t_list	*last;

	last = list_get_last(*list);
	to_add->prev = last;
	last->next = to_add;
	to_add->next = NULL;
}

void	list_delete_item(t_list *to_delete, void (*ft_delete)(void*))
{
	if (to_delete->next != NULL)
		to_delete->prev->next = to_delete->next;
	else
		to_delete->prev->next = NULL;
	if (to_delete->prev != NULL)
		to_delete->next->prev = to_delete->prev;
	else
		to_delete->next->prev = NULL;
	ft_delete(to_delete->content);
}

void	list_clear(t_list **list, void (*ft_delete)(void*))
{
	while (*list)
	{
		list_delete_item(*list, ft_delete);
		*list = (*list)->next;
	}
}

void	list_iter(t_list *list, void (*function)(void*))
{
	while (list)
	{
		function(list->content);
		list = list->next;
	}
}
