/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:52 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/28 17:38:22 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	median_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	median;

	while (size > 3)
	{
		if (sorted(stack_a))
			return ;
		median = calculate_median(stack_a, size);
		extract_lower_bound(stack_a, stack_b, median, size);
		size = ft_lstsize(*stack_a);
	}
	if (size == 3)
		sort_3(stack_a);
	if (size == 2 && !(sorted(stack_a)))
	{
		if (check_reversed_top(stack_b))
			swap_a_and_b(stack_a, stack_b);
		else
			swap_a(stack_a, 1);
	}
}

void	rearrange_stack_a(t_list **stack_a, t_list **stack_b, int max_value)
{
	t_list	*curr;
	t_list	*top_b;
	t_list	*top_a;
	t_list	*bottom_a;

	if (!stack_b || !*stack_b || !stack_a || !*stack_a)
		return ;
	while (*stack_b)
	{
		curr = *stack_a;
		get_top_and_bottom(curr, &top_a, &bottom_a);
		top_b = *stack_b;
		if (top_b->content && top_a->content)
		{
			if (*(int *)top_b->content > *(int *)top_a->content)
				rotate_a(stack_a);
			else if (*(int *)top_b->content < *(int *)bottom_a->content
					&& *(int *)bottom_a->content != max_value)
				reverse_rotate_a(stack_a);
			else
				push_a(stack_b, stack_a);
		}
	}
	while (!sorted(stack_a))
		rotate_a(stack_a);
}

void	extract_lower_bound(t_list **stack_a, t_list **stack_b, int median,
		const int size)
{
	int		n;
	t_list	*top;

	n = size;
	while (n > 0)
	{
		if (sorted(stack_a))
			return ;
		top = *stack_a;
		if (*(int *)top->content < median) //find lower cost value under median
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		n--;
	}
}


int	calculate_median(t_list **stack_a, int n)
{
	int		*copy_stack;
	t_list	*current;
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

void	get_top_and_bottom(t_list *stack, t_list **top, t_list **bottom)
{
	*top = stack;
	*bottom = stack;
	if (!stack)
		return ;
	while (stack->next)
	{
		stack = stack->next;
		*bottom = stack;
	}
}
