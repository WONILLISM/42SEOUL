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


int comp(void *data1, void *data2)
{
    char *s1;
    char *s2;

    s1 = data1;
    s2 = data2;
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *tmp;

    if (!*begin_list)
        return ;
    if (!cmp(data_ref, (*begin_list)->data))
    {
        tmp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(tmp);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
        ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
}

int main(void)
{
	t_list *root;
    t_list **root2;
	// char *str;
    root2 = &root;
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
    ft_list_remove_if(root2, "hello", comp);
    ft_list_foreach(root, print_data);
	return (0);
}