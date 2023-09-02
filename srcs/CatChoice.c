/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatChoice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:32 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/02 20:21:14 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_data **stack_a, t_data **stack_b)
{
	int	size;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	size = get_size(*stack_a);
	if (sorted(stack_a))
		return ;
	else if (size == 2)
		swap_a(stack_a, 1);
	else if (size == 3)
		trio_sort(stack_a);
	else if (size == 4)
		quartet_sort(stack_a, stack_b);
	else if (size == 5)
		quintet_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, size);
}

int	sorted(t_data **stack_a)
{
	t_data	*ptr;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	ptr = *stack_a;
	while (ptr->next)
	{
		if (*(int *)ptr->data > *(int *)ptr->next->data)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
