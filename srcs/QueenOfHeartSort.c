/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QueenOfHeartSort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:52 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/29 13:16:39 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	gigantous_sort(t_data **stack_a, t_data **stack_b, int size)
{
	insert_final_idx(stack_a);
	group_by_median(stack_a, stack_b, size);
	//at this time everything in stack a is bigger than anything in stack b.
	minimum_cost_sort(stack_a, stack_b, size);
}

void	group_by_median(t_data **stack_a, t_data **stack_b, int size)
{
	int	median;

	while (size > 3)
	{
		if (sorted(stack_a))
			return ;
		median = calculate_median(stack_a, size);
		extract_lower_bound(stack_a, stack_b, median, (const int)size);
		size = get_size(*stack_a);
	}
	if (size == 3)
		trio_sort(stack_a);
	if (size == 2 && !(sorted(stack_a)))
	{
		if (check_reversed_top(stack_b))
			swap_a_and_b(stack_a, stack_b);
		else
			swap_a(stack_a, 1);
	}
}

// index est la position finale de la valeur dans la pile triee
// ou est la valeur est actuellement dans B
// ou est la valeur associee dans A a la valeur presente dans B
// par rapport au milieu des piles (ra rra)
// cout est le calcul des valeurs relatives entre la posA et posB
//combien de instructions pour deplacer pos a et pos b en haut de leurs stacks
// 1 (push_a), et en supprimant les repetitions car rr ou rrr
void	minimum_cost_sort(t_data **stack_a, t_data **stack_b, int size)
{
	t_data	*current;
	t_data	*min_cost_value;

	while (*stack_a)
	{
		current = *stack_b;
		min_cost_value = current; //the minimum movements is 1 and that is pa
		min_cost_value->cost = calculate_cost(min_cost_value);
		while (current)
		{
			current->cost = calculate_cost(current);
			if (current->cost < min_cost_value->cost)
				min_cost_value = current;
			current = current->next;
		}
		send_mcv(stack_a, stack_b, min_cost_value);
	}
}

int calculate_cost()

void	extract_lower_bound(t_data **stack_a, t_data **stack_b, int median, int size)
{
	int		n;
	t_data	*top;

	n = size;
	while (n > 0)
	{
		if (sorted(stack_a))
			return ;
		top = *stack_a;
		if (*(int *)top->content < median)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		n--;
	}	
}


int	calculate_median(t_data **stack_a, int n)
{
	int		*copy_stack;
	t_data	*current;
	int		i;
	int		median;

	current = *stack_a;
	copy_stack = malloc(sizeof(int) * n);
	if (!copy_stack)
		exit(EXIT_FAILURE);
	i = 0;
	while (current)
	{
		copy_stack[i] = *(int *)current->content;
		current = current->next;
		i++;
	}
	quicksort(copy_stack, 0, n - 1);
	median = copy_stack[n / 2];
	free(copy_stack);
	return (median);
}
