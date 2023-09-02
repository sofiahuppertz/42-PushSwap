/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CardSoldiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:57 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/02 20:21:14 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rearrange_stack(t_data **stack_a, int size)
{
	int	min_val;

	min_val = get_min_idx(stack_a);
	if (min_val < size / 2)
	{
		while (min_val > 0)
		{
			rotate(stack_a, 1);
			min_val -= 1;
		}
	}
	else
	{
		while (min_val < size)
		{
			reverse_rotate(stack_a, 1);
			min_val += 1;
		}
	}
	return ;
}

int	get_max(t_data **stack)
{
	t_data	*current;
	int		max;

	current = *stack;
	max = *(int *)current->data;
	while (current)
	{
		if (*(int *)current->data > max)
		{
			max = *(int *)current->data;
		}
		current = current->next;
	}
	return (max);
}

int	get_min(t_data **stack)
{
	t_data	*ptr;
	int		min;

	ptr = *stack;
	min = *(int *)ptr->data;
	while (ptr)
	{
		if (*(int *)ptr->data < min)
			min = *(int *)ptr->data;
		ptr = ptr->next;
	}
	return (min);
}

int	get_min_idx(t_data **stack_a)
{
	t_data	*ptr;
	int		min;
	int		index;
	int		index_min;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (-1);
	ptr = *stack_a;
	min = *(int *)ptr->data;
	index = 0;
	index_min = 0;
	while (ptr)
	{
		if (*(int *)ptr->data < min)
		{
			min = *(int *)ptr->data;
			index_min = index;
		}
		index += 1;
		ptr = ptr->next;
	}
	return (index_min);
}

void	set_holds(int *first_hold, int *last_hold, t_data **stack_a, int bound)
{
	int		index;
	t_data	*ptr;

	ptr = *stack_a;
	index = 0;
	set_inital_params(first_hold, last_hold);
	while (ptr)
	{
		if (*(int *)(ptr)->data < bound)
		{
			if (*first_hold == -1)
				*first_hold = index;
			*last_hold = index;
		}
		index += 1;
		ptr = (ptr)->next;
	}
}
