# doubly_linked_list
Doubly linked list implementation in C

[![linux](https://github.com/harou24/double_linked_list/workflows/Linux/badge.svg)](https://github.com/harou24/double_linked_list/actions?workflow=Linux)
[![macos](https://github.com/harou24/double_linked_list/workflows/MacOS/badge.svg)](https://github.com/harou24/double_linked_list/actions?workflow=MacOS)

Functionalities :

t_list	*list_create(void *content);
void	list_add_front(t_list **_list, t_list *_to_add);
size_t	list_size(t_list *_list);
t_list	*list_get_last(t_list *_beggining);
void	list_add_back(t_list **_list, t_list *_to_add);
void	list_delete_item(t_list *_to_free, void (*_ft_delete)(void*));
void	list_clear(t_list **_list, void (*_ft_delete)(void*));
void 	list_iter(t_list *_element, void (*_ft_iterator)(void *));
