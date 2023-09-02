/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoreCardSoldiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:26:53 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/02 20:14:19 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	rotate_stack(t_data **stack, int big, int small,
		void (*rotate_func)(t_data **, int))
{
	while (big > small)
	{
		rotate_func(stack, 1);
		big -= 1;
	}
}

void	set_inital_params(int *first_hold, int *last_hold)
{
	*first_hold = -1;
	*last_hold = -1;
}

int	partition(int *arr, int low, int high)
{
	int	pivotal;
	int	i;
	int	j;

	pivotal = arr[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivotal)
		{
			swap(&(arr[i]), &(arr[j]));
			i++;
		}
		j++;
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
