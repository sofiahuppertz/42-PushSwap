/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:32 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/08 16:55:28 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    arrange_numbers(t_list **stack_a, t_list **stack_b)
{
    int size;

    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return ;
    size = ft_lstsize(*stack_a);
    if (sorted(stack_a))
        return ;
    else if (size == 2)
        swap_a(stack_a, 1);
    else if (size == 3)
        sort_3(stack_a);
    else if (size == 4)
        sort_4(stack_a, stack_b);
    else if (size == 5)
        sort_5(stack_a, stack_b);
    else
        median_sort(stack_a, stack_b, size);
        rearrange_stack_a(stack_a, stack_b, get_max(stack_a));
}

int sorted(t_list **stack_a)
{
    t_list *ptr;
    
    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return (0);
    ptr = *stack_a;
    while (ptr->next)
    {
        if (*(int *)ptr->content > *(int *)ptr->next->content)
            return (0);
        ptr = ptr->next;
    }
    return (1);
}

int find_min(t_list **stack_a)
{
    t_list *ptr;
    int min;
    int index;
    int index_min;

    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return (-1);
    ptr = *stack_a;
    min = *(int *)ptr->content;
    index = 0;
    index_min = 0;
    while (ptr)
    {
        if (*(int *)ptr->content < min)
        {
            min = *(int *)ptr->content;
            index_min = index;
        }
        index += 1;
        ptr = ptr->next;
    }
    return (index_min);
}