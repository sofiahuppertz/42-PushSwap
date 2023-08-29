
#include "../push_swap.h"

void	insert_node(t_data **lst, t_data *new_lst)
{
	t_data	*node;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			node = *lst;
			while (node->next)
				node = node->next;
			node->next = new_lst;
		}
		else
		{
			*lst = new_lst;
		}
	}
}

void delete_lst(t_data **lst, void (*del)(void *))
{
	t_data	*node;

	node = *lst;
	if (lst)
	{
		while (node != NULL)
		{
			*lst = node->next;
			if (node != NULL && node->content != NULL)
			{
				(del)(node->content);
				free(node);
				node = NULL;
			}
			node = *lst;
		}
	}
}



int	get_size(t_data *lst)
{
	int		count;
	t_data	*node;

	count = 0;
	node = lst;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}

t_data	*create_node(void *content)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
