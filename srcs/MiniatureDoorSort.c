/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniatureDoorSort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:54 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/02 20:21:14 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	trio_sort(t_data **stack_a)
{
	t_data	*first;

	first = *stack_a;
	if (sorted(stack_a))
		return ;
	if (*(int *)first->data > *(int *)first->next->data
		&& *(int *)first->data < *(int *)first->next->next->data)
		swap_a(stack_a, 1);
	else if (*(int *)first->data > *(int *)first->next->data
		&& *(int *)first->data > *(int *)first->next->next->data)
	{
		rotate(stack_a, 1);
		if (!sorted(stack_a))
			swap_a(stack_a, 1);
	}
	else if (*(int *)first->data < *(int *)first->next->data
		&&*(int *)first->data > *(int *)first->next->next->data)
		reverse_rotate(stack_a, 1);
	else if (*(int *)first->data < *(int *)first->next->data
		&& *(int *)first->data < *(int *)first->next->next->data)
	{
		swap_a(stack_a, 1);
		rotate(stack_a, 1);
	}
}

void	quartet_sort(t_data **stack_a, t_data **stack_b)
{
	if (get_min_idx(stack_a) < 2)
	{
		while (get_min_idx(stack_a) != 0)
		{
			rotate(stack_a, 1);
		}
	}
	else
	{
		while (get_min_idx(stack_a) != 0)
		{
			reverse_rotate(stack_a, 1);
		}
	}
	push_b(stack_a, stack_b);
	trio_sort(stack_a);
	push_a(stack_b, stack_a);
}

void	quintet_sort(t_data **stack_a, t_data **stack_b)
{
	if (get_min_idx(stack_a) < 2)
	{
		while (get_min_idx(stack_a) != 0)
			rotate(stack_a, 1);
	}
	else
	{
		while (get_min_idx(stack_a) != 0)
			reverse_rotate(stack_a, 1);
	}
	push_b(stack_a, stack_b);
	quartet_sort(stack_a, stack_b);
	push_a(stack_b, stack_a);
}
