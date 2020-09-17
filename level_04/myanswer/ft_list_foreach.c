#include "ft_list.h"

void print_data(void *data)
{
	printf("%s\n", (char *)data);
}

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list)
		return ;
	(*f)(begin_list->data);
	ft_list_foreach(begin_list->next, f);
}

int main(void)
{
	t_list *root;
	// char *str;

	root = (t_list *)malloc(sizeof(t_list));
	root->data = "hi";
	// str = root->data;
	// printf("%s", str);
	root->next = (t_list *)malloc(sizeof(t_list));
	root->next->data = "hello";
	// str = root->next->data;
	// printf("%s", str);
	root->next->next = (t_list *)malloc(sizeof(t_list));
	root->next->next->data = "안녕";
	// str = root->next->next->data;
	// printf("%s", str);
	ft_list_foreach(root, print_data);
	return (0);
}