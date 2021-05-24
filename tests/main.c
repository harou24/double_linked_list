#include "doubly_linked_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	print_node_content(void *str)
{
	printf("%s\n", (char *)str);
}

void	print_list(t_list *list)
{
	printf("---List contains : ---\n");
	list_iter(list, print_node_content);
}

void	print_node(void *_node)
{
	t_node *node;

	node = (t_node *)_node;
	printf("\n\n---Node---\n");
	print_node_content(node->content);
	printf("Prev->%p\n",node->prev);
	printf("Next->%p\n", node->next);
}

void	remove_and_print(t_list *list, t_node *node)
{
	printf("\n---Remove node and print : ---\n");
	list_delete_item(list, node, free);
	print_list(list);
}

int main(void)
{
	printf("---Double linked list unitests---\n");
	
	char *str = strdup("hello");
	char *str2 = strdup("world");
	char *str3 = strdup("test");
	char *str4 = strdup("linked_list");
	
	t_node *n = node_create(str);
	t_node *n2 = node_create(str2);
	t_node *n3 = node_create(str3);
	t_node *n4 = node_create(str4);

	t_list *list = list_create();
	
	list_add_front(list, n);
	list_add_front(list, n2);
	list_add_front(list, n3);
	list_add_front(list, n4);
	
	printf("SIZE=%zu\n\n",list_size(list));
	print_list(list);
	remove_and_print(list, n4);
	remove_and_print(list, n);
	remove_and_print(list, n2);
	list_destroy(list, free);
	return (0);
}
