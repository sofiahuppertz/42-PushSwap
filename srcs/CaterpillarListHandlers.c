/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CaterpillarListHandlers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:28:27 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/02 20:21:14 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insert_node(t_data **lst, t_data *new_node)
{
	t_data	*current;

	if (!lst || !new_node)
	{
		return ;
	}
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	current = *lst;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new_node;
}

void	delete_lst(t_data **lst, void (*del_func)(void *))
{
	t_data	*current;

	if (!lst || !*lst || !del_func)
	{
		return ;
	}
	while (*lst)
	{
		current = *lst;
		*lst = current->next;
		del_func(current->data);
		free(current);
	}
}

int	get_size(t_data *lst)
{
	int		count;
	t_data	*current;

	count = 0;
	current = lst;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_data	*create_node(void *data)
{
	t_data	*new_node;

	new_node = (t_data *)malloc(sizeof(t_data));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}
