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
	free(sorted_copy);
}

void	minimum_cost_sort(t_data **stack_a, t_data **stack_b)
{
	t_data	*current;
	int size_a;
	int size_b;
	t_data	*min_cost_value;

	while (*stack_b)
	{
		current = *stack_b;
		while (current)
		{
			size_a = get_size(*stack_a);
			size_b = get_size(*stack_b);
			set_info(current, stack_a, stack_b);
			current->cost = calculate_cost(current, size_a, size_b);
			current = current->next;
		}
		min_cost_value = get_min_cost_value(*stack_b);
		do_cheapest_move(stack_a, stack_b, min_cost_value);
	}	
}

void do_cheapest_move(t_data **stack_a, t_data **stack_b, t_data *min_cost_value)
{
	if (min_cost_value->cost == 0)
	{
		push_a(stack_b, stack_a);
		return;
	}
	perform_rotations(stack_a, stack_b, min_cost_value->moves_a, min_cost_value->moves_b);
	push_a(stack_b, stack_a);
	return;
}

void perform_rotations(t_data **stack_a, t_data **stack_b, int moves_a, int moves_b)
{

	if (moves_a >= 0 && moves_b >= 0)
	{
		if (moves_a < moves_b)
		{
			while (moves_a > moves_b)
			{
				rotate_a(stack_a, 1);
				moves_a -= 1;
			}	
			while (moves_b > 0)
			{
				rotate_a_and_b(stack_a, stack_b);
				moves_b -= 1;
			}
				
		}
		else
		{
			while (moves_b > moves_a)
			{
				rotate_b(stack_b, 1);
				moves_b += 1;
			}	
			while (moves_a > 0)
			{
				rotate_a_and_b(stack_a, stack_b);
				moves_a -= 1;
			}	
		}	
	}
	else if (moves_a <= 0  && moves_b <= 0)
	{
		if (moves_a < moves_b)
		{
			while (moves_a < moves_b)
			{
				reverse_rotate_a(stack_a, 1);
				moves_a += 1;
			}
			while (moves_b < 0)
			{
				reverse_rotate_a_and_b(stack_a, stack_b);
				moves_b += 1;
			}
		}
		else
		{
			while (moves_a > moves_b)
			{
				reverse_rotate_b(stack_b, 1);
				moves_b += 1;
			}
			while (moves_b < 0)
			{
				reverse_rotate_a_and_b(stack_a, stack_b);
				moves_b += 1;
			}
		}
	}
	else 
	{
		while (moves_a > 0)
		{
			rotate_a(stack_a, 1);
			moves_a -= 1;
		}
		while (moves_a < 0)
		{
			reverse_rotate_a(stack_a, 1);
			moves_a += 1;
		}
		while (moves_b > 0)
		{
			rotate_a(stack_a, 1);
			moves_b -= 1;
		}
		while (moves_b < 0)
		{
			reverse_rotate_a(stack_a, 1);
			moves_b += 1;
		}
	}
}

t_data 	*get_min_cost_value(t_data *stack_b)
{
	t_data *min_cost_value;
	t_data *ptr;
	ptr = stack_b;
	min_cost_value = ptr;
	while (ptr)
	{
		if (ft_abs(ptr->cost) < ft_abs(min_cost_value->cost))
			min_cost_value = ptr;
		ptr = ptr->next;
	}
	return (min_cost_value);
}

int 	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int calculate_cost(t_data *current, int size_a, int size_b)
{
	int cost;

	if (current->pos > size_b / 2)
		current->moves_b = -1 * (size_b - current->pos);
	else
		current->moves_b = current->pos;
	
	if (current->assoc_pos > size_a / 2)
		current->moves_a = -1 * (size_a - current->assoc_pos);
	else
		current->moves_a = current->assoc_pos;
	if (current->moves_b <= 0 && current->moves_a <= 0)
	{
		if (current->moves_a < current->moves_b)
			cost = current->moves_a;
		else
			cost = current->moves_b;
	}
	else if (current->moves_b >= 0 && current->moves_b >= 0)
		if (current->moves_a < current->moves_b)
			cost = current->moves_b;
		else
			cost = current->moves_a;
	else
		cost = abs(current->moves_a) + abs(current->moves_b);
	return (cost);
}

void set_info(t_data *current, t_data **stack_a, t_data **stack_b)
{
	int i;
	int min_a;
	t_data *previous;
	t_data *ptr;


// 1. Set pos.
	ptr = *stack_b;
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
// 2. Set assoc_pos.
	i = 0;
	min_a = get_min(stack_a);
	if (min_a > *(int *)current->content)
		current->assoc_pos = get_min_idx(stack_a);
	else
	{
		i = 0;
		while (ptr)
		{
			previous = ptr;
			ptr = ptr->next;
			if (*(int *)ptr->content > *(int *)current->content && *(int *)previous->content < *(int *)current->content)
			{
				current->assoc_pos = i;
				break;
			}
			i += 1;
		}
	}	
}

int		get_min(t_data **stack)
{
	t_data	*ptr;
	int		min;

	ptr = *stack;
	min = *(int *)ptr->content;
	while (ptr)
	{
		if (*(int *)ptr->content < min)
			min = *(int *)ptr->content;
		ptr = ptr->next;
	}
	return (min);
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

