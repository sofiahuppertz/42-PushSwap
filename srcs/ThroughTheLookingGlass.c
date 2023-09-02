/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ThroughTheLookingGlass.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:31:36 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/02 19:36:34 by shuppert         ###   ########.fr       */
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
