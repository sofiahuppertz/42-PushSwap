/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:57 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/08 16:55:01 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculate_median(t_list **stack_a, int n)
{
	int		*copy_stack;
	t_list	*current;
	int		i;
	int		median;

	current = *stack_a;
	copy_stack = malloc(sizeof(int) * n);
	if (!copy_stack)
	{
		ft_printf("Memory allocation failed\n");
		return (-1);
	}
	i = 0;
	while (current)
	{
		copy_stack[i] = *(int *)current->content;
		current = current->next;
		i++;
	}
	quicksort(&copy_stack, 0, n - 1);
	median = copy_stack[n / 2];
	free(copy_stack);
    return median;
}

void	quicksort(int **arr, int low, int high)
{
	int	pivotal;

	if (low < high)
	{
		pivotal = partition(arr, low, high);
		quicksort(arr, low, pivotal - 1);
		quicksort(arr, pivotal + 1, high);
	}
}

int	partition(int **arr, int low, int high)
{
	int	pivotal;
	int	i;

	pivotal = *arr[high];
	i = low;
	for (int j = low; j < high; j++)
	{
		if (*arr[j] <= pivotal)
		{
			swap(&(*arr[i]), &(*arr[j]));
			i++;
		}
	}
	swap(&(*arr[high]), &(*arr[i]));
	return (i);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	get_max(t_list **stack)
{
	t_list *current;
	int max;

	current = *stack;
	max = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content > max)
		{
			max = *(int *)current->content;
		}
		current = current->next;
	}
	return (max);
}