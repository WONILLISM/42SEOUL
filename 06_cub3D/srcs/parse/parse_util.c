#include "../../includes/cub3d.h"

int		get_col_size(t_list *lst)
{
	int		ret;
	int		size;

	ret = 0;
	while (lst)
	{
		size = ft_strlen(lst->content);
		if (ret < size)
			ret = size;
		lst = lst->next;
	}
	return (ret);
}

char	**lst2arr(t_gamedata *d, t_list *lst)
{
	char	**ret;
	int		i;

	d->scrn.col_size = get_col_size(lst);
	d->scrn.row_size = ft_lstsize(lst);
	ret = (char **)malloc(sizeof(char *) * (d->scrn.row_size + 1));
	if (!ret)
		return (0);	// malloc error
	i = 0;
	while (lst)
	{
		ret[i] = (char *)malloc(sizeof(char) * d->scrn.col_size + 1);
		if (!ret[i])
		{
			free_split(ret);
			return (0); // malloc error
		}
		ft_strlcpy(ret[i], lst->content, d->scrn.col_size + 1);
		i++;
		lst = lst->next;
	}
	ret[i] = 0;
	return (ret);
}

void	free_split(char **res)
{
	char	**tmp;

	if (!res)
		return ;
	tmp = res;
	while (*tmp)
		free(*tmp++);
	free(res);
}

void	free_gamedata(t_gamedata *d)
{
	free(d->north_img);
	free(d->south_img);
	free(d->west_img);
	free(d->east_img);
	free(d->scrn.sprite);
	free(d->scrn.ZBuffer);
	free_split(d->scrn.map_arr);
}
