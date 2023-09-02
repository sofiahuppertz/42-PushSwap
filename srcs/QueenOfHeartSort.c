/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QueenOfHeartSort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:52 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/02 20:21:14 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	big_sort(t_data **stack_a, t_data **stack_b, int size)
{
	int	*sorted_copy;
	int	quantile_bounds[5];
	int	i;

	sorted_copy = NULL;
	sort_numbers(stack_a, stack_b, &sorted_copy, size);
	calculate_quantile_bounds(quantile_bounds, sorted_copy, size);
	insert_id(stack_a, sorted_copy, size);
	i = 0;
	while (i < 5)
	{
		bucket_sort(stack_a, stack_b, quantile_bounds[i]);
		i++;
	}
	free(sorted_copy);
	minimum_cost_sort(stack_a, stack_b);
	rearrange_stack(stack_a, size);
}

void	sort_numbers(t_data **stack_a, t_data **stack_b, int **sorted_copy,
		int size)
{
	t_data	*current;
	int		i;

	i = 0;
	*sorted_copy = malloc(sizeof(int) * size);
	if (!(*sorted_copy))
	{
		write(1, "It seems your out of space.", 28);
		delete_lst(stack_a, free);
		delete_lst(stack_b, free);
		exit(1);
	}
	current = *stack_a;
	while (current && i < size)
	{
		(*sorted_copy)[i] = *(int *)current->data;
		current = current->next;
		i += 1;
	}
	quicksort(*sorted_copy, 0, size - 1);
}

void	calculate_quantile_bounds(int quantile_bounds[5], int *sorted_copy,
		int size)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		quantile_bounds[i] = sorted_copy[size / 5 + i * (size / 5)];
		i++;
	}
	quantile_bounds[4] = sorted_copy[size - 1];
}

void	insert_id(t_data **stack_a, int *sorted, int size)
{
	t_data	*current;
	int		i;

	current = *stack_a;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (*(int *)current->data == sorted[i])
			{
				current->id = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	bucket_sort(t_data **stack_a, t_data **stack_b, int bound)
{
	int		len;
	int		first_hold;
	int		last_hold;

	len = get_size(*stack_a);
	while (len > 3)
	{
		set_holds(&first_hold, &last_hold, stack_a, bound);
		if (first_hold == -1)
			return ;
		else if (first_hold < len - last_hold)
			rotate_stack(stack_a, first_hold, 0, rotate);
		else
			rotate_stack(stack_a, len, last_hold, reverse_rotate);
		push_b(stack_a, stack_b);
		len -= 1;
	}
	push_swap(stack_a, stack_b);
}
