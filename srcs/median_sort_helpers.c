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


int check_reversed_top(t_list **stack)
{
    t_list *first;
    t_list *next;

    if (!stack || !(*stack) || !(*stack)->next)
        return (0);
    first = *stack;
    next = first->next;
    if (*(int *)first->content < *(int *)next->content)
        return (1);
    else
        return (0);     
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

void	quicksort(int *arr, int low, int high)
{
	int	pivotal;

	if (low < high)
	{
		pivotal = partition(arr, low, high);
		quicksort(arr, low, pivotal - 1);
		quicksort(arr, pivotal + 1, high);
	}
}

int	partition(int *arr, int low, int high)
{
	int	pivotal;
	int	i;

	pivotal = arr[high];
	i = low;
	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivotal)
		{
			swap(&(arr[i]), &(arr[j]));
			i++;
		}
	}
	swap(&(arr[high]), &(arr[i]));
	return (i);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

