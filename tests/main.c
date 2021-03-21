#include "double_linked_list.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("---Double linked list unitests---\n");
	char *str = strdup("hello");
	char *str2 = strdup("world");
	char *str3 = strdup("double");
	char *str4 = strdup("linked");
	char *str5 = strdup("list");
	char *str6 = strdup("test");

	t_doubly_linked_node *n = node_create(str);
	t_doubly_linked_node *n2 = node_create(str2);
	t_doubly_linked_node *n3 = node_create(str3);
	t_doubly_linked_node *n4 = node_create(str4);
	t_doubly_linked_node *n5 = node_create(str5);
	t_doubly_linked_node *n6 = node_create(str6);

	t_doubly_linked_list *list = list_create();
	list_add_front(list, n);
	list_add_front(list, n2);
	list_add_front(list, n3);
	list_add_front(list, n4);
	list_add_front(list, n5);
	list_add_front(list, n6);

	printf("SIZE=%zu\n",list_size(list));
	return (0);
}
