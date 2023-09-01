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

void rotate_stack(t_data **stack, int big, int small, void(*rotate_func)(t_data **, int))
{
	while (big > small)
	{
		rotate_func(stack, 1);
		big -= 1;
	}
}

void set_inital_params(int *index, int *first_hold, int *last_hold, t_data **ptr, t_data **stack_a)
{
	*index = 0;
	*first_hold = -1;
	*last_hold = -1;	
	*ptr = *stack_a;
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