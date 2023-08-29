/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatChoice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:32 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/29 11:51:47 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_data **stack_a, t_data **stack_b)
{
	int	size;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	size = get_size(*stack_a);
	if (sorted(stack_a))
		return ;
	else if (size == 2)
		swap_a(stack_a, 1);
	else if (size == 3)
		trio_sort(stack_a);
	else if (size == 4)
		quartet_sort(stack_a, stack_b);
	else if (size == 5)
		quintet_sort(stack_a, stack_b);
	else
		gigantous_sort(stack_a, stack_b, size);
}

int	sorted(t_data **stack_a)
{
	t_data	*ptr;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	ptr = *stack_a;
	while (ptr->next)
	{
		if (*(int *)ptr->content > *(int *)ptr->next->content)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	get_min_idx(t_data **stack_a)
{
	t_data *ptr;
	int min;
	int index;
	int index_min;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (-1);
	ptr = *stack_a;
	min = *(int *)ptr->content;
	index = 0;
	index_min = 0;
	while (ptr)
	{
		if (*(int *)ptr->content < min)
		{
			min = *(int *)ptr->content;
			index_min = index;
		}
		index += 1;
		ptr = ptr->next;
	}
	return (index_min);
}