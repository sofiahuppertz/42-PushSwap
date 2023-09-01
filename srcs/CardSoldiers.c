/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QueenOfHeartSort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:57 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/29 11:36:26 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void rearrange_stack(t_data **stack_a, int size)
{
	int min_val;

	min_val = get_min_idx(stack_a);
	if (min_val < size / 2)
		while (min_val > 0)
		{
			rotate_a(stack_a, 1);
			min_val -= 1;
		}
	else
		while (min_val < size)
		{
			reverse_rotate_a(stack_a, 1);
			min_val += 1;
		}
	return;
}

int	get_max(t_data **stack)
{
	t_data *current;
	int max;

	current = *stack;
	max = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content > max)
		{
			max = *(int *)current->content;
		}
		current = current->next;
	}
	return (max);
}

int		get_min(t_data **stack)
{
	t_data	*ptr;
	int		min;

	ptr = *stack;
	min = *(int *)ptr->content;
	while (ptr)
	{
		if (*(int *)ptr->content < min)
			min = *(int *)ptr->content;
		ptr = ptr->next;
	}
	return (min);
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

void set_holds(int *first_hold, int *last_hold, int *index, t_data **ptr, t_data **stack_a, int bound)
{
	set_inital_params(index, first_hold, last_hold, ptr, stack_a);
	while (*ptr)
	{
		if (*(int *)(*ptr)->content < bound)
		{
			if (*first_hold == -1)
				*first_hold = *index;
			*last_hold = *index;
		}
		*index += 1;
		*ptr = (*ptr)->next;
	}
}






