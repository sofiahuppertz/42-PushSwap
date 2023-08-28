/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:40 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/28 17:16:37 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// TODO: break into smaller stacks
// Calculate median of stack a and send every value smaller than the median to stack b.
// Repeat until stack a has 3 or less elements. Optimize when I can do ss(instead of rotate)
// Find minimum cost number from stack b to stack a.
// place it sorted to stack a.
//Keep track of value on bottom of stack a, if it's bigger than top of stack b, rra and then pb
//If top of stack a is smaller than top of stack b, rotate a and the pb.
void selection_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int index_min;
    int i;
    int j;

    i = size;
    while (i > 0)
    {
        if (sorted(stack_a))
            break ;
        index_min = find_min(stack_a);
        if (index_min <= i / 2)
        {
            if (index_min == 1)
            {
                swap_a(stack_a, 1);
            }
            else
            {
                while (find_min(stack_a) > 0)
                {
                    rotate_a(stack_a);
                }
            }
        }
        else if (index_min > i / 2)
        {
            while (find_min(stack_a) > 0)
            {
                reverse_rotate_a(stack_a);
            }
        }
        push_b(stack_a, stack_b);
        i -= 1;
    }
    //Push back all elements from stack_b to stack_a.
    j = 0;
    while (j < size - i)
    {
        push_a(stack_b, stack_a);
        j += 1;
    }
}
