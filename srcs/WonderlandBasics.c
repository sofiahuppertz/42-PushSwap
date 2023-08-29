/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WonderlandBasics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:54:08 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/29 11:45:16 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_data **stack_a, int print)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*stack_a = second;
	if (print)
		write(1, "sa\n", 3);
}

void	swap_b(t_data **stack_b, int print)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*stack_b = second;
	if (print)
		write(1, "sb\n", 3);
}

void	swap_a_and_b(t_data **stack_a, t_data **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	write(1, "ss\n", 3);
}

void	push_a(t_data **stack_b, t_data **stack_a)
{
	t_data	*first;
	t_data	*second;

	if (!stack_b || !(*stack_b))
		return ;
	first = *stack_b;
	second = first->next;
	first->next = *stack_a;
	*stack_a = first;
	*stack_b = second;
	write(1, "pa\n", 3);
}

void	push_b(t_data **stack_a, t_data **stack_b)
{
	t_data	*first;
	t_data	*second;

	if (!stack_a || !(*stack_a))
		return ;
	first = *stack_a;
	second = first->next;
	first->next = *stack_b;
	*stack_b = first;
	*stack_a = second;
	write(1, "pb\n", 3);
}

void	rotate_a(t_data **stack_a)
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
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_data **stack_a)
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
	write(1, "rra\n", 4);
}
