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
	int i;

	sorted_copy = NULL;
	sort_copy(stack_a, stack_b, sorted_copy, size);
	insert_idx(stack_b, sorted_copy, size);
	calculate_quantile_bounds(quantile_bounds, sorted_copy, size);
	i = 0;
	while (i < 5)
	{
		extract_per_bound(stack_a, stack_b, quantile_bounds[i], size);
		i++;
	}
	minimum_cost_sort(stack_a, stack_b);

	free(sorted_copy);
}

void calculate_quantile_bounds(int quantile_bounds[5], int *sorted_copy, int size)
{
	int quantile;
	int i;

	i = 1;
	while (i < 6)
	{
		quantile = (size -1) * (i / 5);
		quantile_bounds[i - 1] = sorted_copy[quantile];
		i++;
	}
}


void sort_copy(t_data **stack_a, t_data **stack_b, int *sorted_copy, int size)
{
	t_data	*current;
	int i;
	
	i = 0;
	sorted_copy = malloc(sizeof(int) * size);
	if (!sorted_copy)
	{
		delete_lst(stack_a, free);
		delete_lst(stack_b, free);
		exit(1);
	}
		current = *stack_b;
	while (current)
	{
		sorted_copy[i] = *(int *)current->content;
		current = current->next;
		i += 1;
	}
	quicksort(sorted_copy, 0, size - 1);
}

void insert_idx(t_data **stack_b, int *sorted, int size)
{
	t_data	*current;
	int i;

	current = *stack_b;
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

void	minimum_cost_sort(t_data **stack_a, t_data **stack_b)
{
	t_data	*current;
	t_data	*min_cost_value;

	while (*stack_a)
	{
		current = *stack_b;
		min_cost_value = current;
		min_cost_value->cost = calculate_cost(min_cost_value, *stack_a, *stack_b);
		while (current)
		{
			set_info(current, stack_a, stack_b);
			current->cost = calculate_cost(current, *stack_a, *stack_b);
			if (current->cost < min_cost_value->cost)
				min_cost_value = current;
			current = current->next;
		}
		do_cheapest_move(stack_a, stack_b, min_cost_value);
	}
}

void do_cheapest_move(t_data **stack_a, t_data **stack_b, t_data *min_cost_value)
{
	int size_a;
	int size_b;
	int cost_a;
	int cost_b;

	size_a = get_size(*stack_a);
	size_b = get_size(*stack_b);

	if (min_cost_value->pos < size_b / 2)
	{
		cost_b = -(size_b - min_cost_value->pos);
	}
	else
	{
		cost_b = size_b - min_cost_value->pos;
	}
	if (min_cost_value->assoc_pos < size_a / 2)
		cost_a = -(size_a - min_cost_value->assoc_pos);
	else
		cost_a = size_a - min_cost_value->assoc_pos;
	

	int i = 0;
	if (cost_b < 0 && cost_b < 0)
	{
		if (cost_a < cost_b)
		{
			while (i < -(cost_b))
			{
				reverse_rotate_a_and_b(stack_a, stack_b);
				i += 1;
			}
			while (i < cost_a)
			{
				reverse_rotate_a(stack_a, 1);
				i += 1;
			}
			push_a(stack_b, stack_a);	
		}
		else
		{
			while (i < -(cost_a))
			{
				reverse_rotate_a_and_b(stack_a, stack_b);
				i += 1;
			}
			while (i < cost_b)
			{
				reverse_rotate_b(stack_a, 1);
				i += 1;
			}
			push_a(stack_b, stack_a);	
		}
			
	} 
	else if (cost_b > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
		{
			while (i < cost_b)
			{
				rotate_a_and_b(stack_a, stack_b);
				i += 1;
			}
			while (i < cost_a)
			{
				rotate_a(stack_a, 1);
				i += 1;
			}
			push_a(stack_b, stack_a);	
		}
		else
		{
			while (i < cost_a)
			{
				rotate_a_and_b(stack_a, stack_b);
				i += 1;
			}
			while (i < cost_b)
			{
				rotate_b(stack_a, 1);
				i += 1;
			}
			push_a(stack_b, stack_a);
		}
	}
	else
	{
		if (cost_a < 0)
		{
			while (i < -(cost_a))
			{
				reverse_rotate_a(stack_a, 1);
				i += 1;
			}
		}
		else
		{
			while (i < cost_a)
			{
				rotate_a(stack_a, 1);
				i += 1;
			}
		}
		i = 0;
		if (cost_b < 0)
		{
			while (i < -(cost_b))
			{
				reverse_rotate_b(stack_b, 1);
				i += 1;
			}
		}
		else 
		{
			while (i < cost_b)
			{
				rotate_b(stack_b, 1);
				i += 1;
			}
		}
		push_a(stack_b, stack_a);
	}

}

int calculate_cost(t_data *current, t_data *stack_a, t_data  *stack_b)
{
	int cost;
	int cost_b;
	int cost_a;
	int size_a;
	int size_b;

	size_a = get_size(stack_a);
	size_b = get_size(stack_b);

	if (current->pos < size_b / 2)
		cost_b = -(size_b - current->pos);
	else
		cost_b = size_b - current->pos;
	
	if (current->assoc_pos < size_a / 2)
		cost_a = -(size_a - current->assoc_pos);
	else
		cost_a = size_a - current->assoc_pos;
	if (cost_b < 0 && cost_b < 0)
		cost = cost_b > cost_a ? cost_a : cost_b; //smalles is biggest in negatives
	else if (cost_b > 0 && cost_b > 0)
		cost = cost_b < cost_a ? cost_a : cost_b;
	else
		cost = abs(cost_a) + abs(cost_b);
	return (cost + 1); //+1 for the pa.
}

void set_info(t_data *current, t_data **stack_a, t_data **stack_b)
{
	int i;
	int j;
	t_data *ptr;
	t_data *first_b;

	ptr = *stack_a;
	i = 0;
	while (ptr)
	{
		if (ptr->id == current->id)
		{
			current->pos = i;
			break ;
		}
		i++;
		ptr = ptr->next;
	}
	current->assoc_pos = -1;
	first_b = *stack_b;
	ptr = *stack_b;
	j = 0;
	while (ptr)
	{
		if (ptr->id < current->id)
		{
			if (ptr->next->id > current->id)	
			{
				current->assoc_pos = j + 1;
				break ;
			}
			else if (ptr->next == NULL && first_b->id > current->id)
			{
				current->assoc_pos = 1;
				break ;
			}
			ptr = ptr->next;
			j++;
		}	
	}
	if (current->assoc_pos == -1)
		current->assoc_pos = get_min_idx(stack_b);
}

void	extract_per_bound(t_data **stack_a, t_data **stack_b, int bound, int size)
{
	int		n;
	t_data	*top;

	n = size;
	while (n > 3)
	{
		if (sorted(stack_a))
			return ;
		top = *stack_a;
		if (*(int *)top->content < bound)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a, 1);
		n--;
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


