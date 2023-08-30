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

void	big_sort(t_data **stack_a, t_data **stack_b, int size)
{
	int *sorted_copy;
	int quantile_bounds[5];
	int top_val;
	int i;

	sorted_copy = NULL;
	sort_copy(stack_a, stack_b, &sorted_copy, size);
	insert_id(stack_a, sorted_copy, size);
	calculate_quantile_bounds(quantile_bounds, sorted_copy, size);
	i = 0;
	while (i < 5)
	{
		extract_per_bound(stack_a, stack_b, quantile_bounds[i]);
		i++;
	}
	minimum_cost_sort(stack_a, stack_b);
	top_val = get_min_idx(stack_a);
	if (top_val < size / 2)
		while (top_val > 0)
		{
			rotate_a(stack_a, 1);
			top_val -= 1;
		}
	else
		while (top_val < size)
		{
			reverse_rotate_a(stack_a, 1);
			top_val += 1;
		}
	free(sorted_copy);
}


void	extract_per_bound(t_data **stack_a, t_data **stack_b, int bound)
{
	int len;
	int index;
	int first_hold;
	int last_hold;
	t_data *ptr;

	index = 0;
	first_hold = -1;
	last_hold = -1;
	len = get_size(*stack_a);
	ptr = *stack_a;
	while (len > 3)
	{
		while (ptr)
		{
			if (*(int *)ptr->content < bound)
			{
				if (first_hold == -1)
					first_hold = index;
				last_hold = index;
			}
			index += 1;
			ptr = ptr->next;
		}
		if (first_hold == -1)
			return;
		else if (first_hold < len - last_hold)
		{
			while (first_hold > 0)
			{
				rotate_a(stack_a, 1);
				first_hold -= 1;
			}
		}
		else 
		{
			while (last_hold < len)
			{
				reverse_rotate_a(stack_a, 1);
				last_hold += 1;
			}
		}
		push_b(stack_a, stack_b);
		ptr = *stack_a;
		index = 0;
		first_hold = -1;
		last_hold = -1;
		len -= 1;
	}
	if (len == 3)
		trio_sort(stack_a);
	else if (len == 2 && !(sorted(stack_a)))
		swap_a(stack_a, 1);
}


void calculate_quantile_bounds(int quantile_bounds[5], int *sorted_copy, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		quantile_bounds[i] = sorted_copy[size / 5 + i * (size / 5)];
		i++;
	}
	quantile_bounds[4] = sorted_copy[size - 1];
}


void sort_copy(t_data **stack_a, t_data **stack_b, int **sorted_copy, int size)
{
	t_data	*current;
	int i;
	
	i = 0;
	*sorted_copy = malloc(sizeof(int) * size);
	if (!(*sorted_copy))
	{
		delete_lst(stack_a, free);
		delete_lst(stack_b, free);
		exit(1);
	}
	current = *stack_a;
	while (current && i < size)
	{
		(*sorted_copy)[i] = *(int *)current->content;
		current = current->next;
		i += 1;
	}
	quicksort(*sorted_copy, 0, size - 1);
}

void insert_id(t_data **stack_a, int *sorted, int size)
{
	t_data	*current;
	int i;

	current = *stack_a;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (*(int *)current->content == sorted[i])
			{
				current->id = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

