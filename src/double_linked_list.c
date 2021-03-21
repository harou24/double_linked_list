#include "double_linked_list.h"
#include <stdlib.h>

t_doubly_linked_list	*list_create()
{
	t_doubly_linked_list	*list;

	list = (t_doubly_linked_list *)malloc(sizeof(t_doubly_linked_list));
	if (!list)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	return (list);
}

t_doubly_linked_node	*node_create(void *content)
{
	t_doubly_linked_node	*node;

	node = (t_doubly_linked_node *)malloc(sizeof(t_doubly_linked_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	list_add_front(t_doubly_linked_list *list, t_doubly_linked_node *to_add)
{
	to_add->next = list->first;
	to_add->prev = NULL;
	list->first = to_add;
}

size_t	list_size(t_doubly_linked_list *list)
{
	int			size;
	t_doubly_linked_node	*node;

	size = 0;
	node = list->first;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

t_doubly_linked_node	*list_get_last(t_doubly_linked_list *list)
{
	return (list->last);
}

void	list_add_back(t_doubly_linked_list *list, t_doubly_linked_node *to_add)
{
	t_doubly_linked_node	*last;

	last = list_get_last(list);
	to_add->prev = last;
	last->next = to_add;
	to_add->next = NULL;
}

void	list_iter(t_doubly_linked_list *list, void (*function)(void*))
{
	t_doubly_linked_node	*node;

	node = list->first;
	while (node)
	{
		function(node->content);
		node = node->next;
	}
}

void	list_delete_item(t_doubly_linked_node *to_delete, void (*ft_delete)(void*))
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

void	list_clear(t_doubly_linked_list *list, void (*ft_delete)(void*))
{
	list_iter(list, ft_delete);
}

void	list_destroy(t_doubly_linked_list *list, void (*ft_delete)(void*))
{
	list_clear(list, ft_delete);
	free(list);
}
