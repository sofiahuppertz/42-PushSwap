/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WonderlandBasics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:54:08 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/02 19:50:35 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_data **stack_a, int print)
{
	t_data	*first;
	t_data	*last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = first;
	while (last->next)
		last = last->next;
	last->next = first;
	*stack_a = first->next;
	first->next = NULL;
	if (print)
	{
		if (print == 1)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void	rotate_and_b(t_data **stack_a, t_data **stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_data **stack_a, int print)
{
	t_data	*previous;
	t_data	*last;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	previous = *stack_a;
	last = previous->next;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	previous->next = NULL;
	if (print)
	{
		if (print == 1)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_and_b(t_data **stack_a, t_data **stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	write(1, "rrr\n", 4);
}
