#include "ft_list.h"

int     ft_list_size(t_list *begin_list)
{
    if (begin_list->next == NULL)
        return (1);
    return (1 + ft_list_size(begin_list->next));
}

int     main(void)
{
    t_list *root;
    char *str;
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
    printf("%d\n", ft_list_size(root));
    return (0);
}