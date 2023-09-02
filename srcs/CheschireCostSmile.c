/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheschireCostSmile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:14:51 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/02 19:50:13 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_cost_operation(t_data **stack_a, t_data **stack_b,
		t_data *min_cost_value)
{
	if (min_cost_value->cost == 0)
	{
		push_a(stack_b, stack_a);
		return ;
	}
	perform_rotations(stack_a, stack_b, min_cost_value->moves_a,
		min_cost_value->moves_b);
	push_a(stack_b, stack_a);
	return ;
}

void	perform_rotations(t_data **stack_a, t_data **stack_b, int moves_a,
		int moves_b)
{
	if (moves_a > 0 && moves_b > 0)
	{
		handle_positive_moves(stack_a, stack_b, moves_a, moves_b);
	}
	else if (moves_a < 0 && moves_b < 0)
	{
		handle_negative_moves(stack_a, stack_b, moves_a, moves_b);
	}
	else
	{
		handle_mixed_moves(stack_a, stack_b, moves_a, moves_b);
	}
}

void	handle_positive_moves(t_data **stack_a, t_data **stack_b, int moves_a,
		int moves_b)
{
	if (moves_a > moves_b)
	{
		while (moves_a > 0)
		{
			if (moves_a > moves_b)
				rotate(stack_a, 1);
			else
				rotate_and_b(stack_a, stack_b);
			moves_a--;
		}
	}
	else
	{
		while (moves_b > 0)
		{
			if (moves_b > moves_a)
				rotate(stack_b, 2);
			else
				rotate_and_b(stack_a, stack_b);
			moves_b--;
		}
	}
}

void	handle_negative_moves(t_data **stack_a, t_data **stack_b, int moves_a,
		int moves_b)
{
	if (moves_a < moves_b)
	{
		while (moves_a < 0)
		{
			if (moves_a < moves_b)
				reverse_rotate(stack_a, 1);
			else
				reverse_rotate_and_b(stack_a, stack_b);
			moves_a++;
		}
	}
	else
	{
		while (moves_b < 0)
		{
			if (moves_b < moves_a)
				reverse_rotate(stack_b, 2);
			else
				reverse_rotate_and_b(stack_a, stack_b);
			moves_b++;
		}
	}
}

void	handle_mixed_moves(t_data **stack_a, t_data **stack_b, int moves_a,
		int moves_b)
{
	while (moves_a > 0)
	{
		rotate(stack_a, 1);
		moves_a--;
	}
	while (moves_a < 0)
	{
		reverse_rotate(stack_a, 1);
		moves_a++;
	}
	while (moves_b > 0)
	{
		rotate(stack_b, 2);
		moves_b--;
	}
	while (moves_b < 0)
	{
		reverse_rotate(stack_b, 2);
		moves_b++;
	}
}
