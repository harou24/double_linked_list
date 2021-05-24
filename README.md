# doubly_linked_list
Doubly linked list implementation in C.

[![linux](https://github.com/harou24/double_linked_list/workflows/Linux/badge.svg)](https://github.com/harou24/double_linked_list/actions?workflow=Linux)
[![macos](https://github.com/harou24/double_linked_list/workflows/MacOS/badge.svg)](https://github.com/harou24/double_linked_list/actions?workflow=MacOS)


# Node

````c
typedef struct	s_node
{
	void		*data;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;
````


Functionalities :
````c
t_node		*node_create(void *content);
````

# List
````c
typedef struct	s_list
{
	t_node	*first;
	t_node	*last;
} t_list;
````

Functionalities :
````c
t_list		*list_create();
void		list_add_front(t_list *list, t_node *to_add);
void		list_add_back(t_list *list, t_node *to_add);
size_t		list_size(t_list *list);
t_node		*list_get_last(t_list *list);
void 		list_iter(t_list *list, void (*ft_iter)(void *));
void		list_delete_item(t_list *list, t_node *to_delete, void (*ft_delete)(void*));
void		list_clear(t_list *list, void (*ft_delete)(void*));
void 		list_destroy(t_list *list, void (*ft_delete)(void *));

````

