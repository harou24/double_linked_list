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
	int	index;

	index = 0;
	while (list)
	{
		index++;
		list = list->next;
	}
}
