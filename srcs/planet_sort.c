/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:54 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/08 15:52:55 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void trio_sort(t_data **stack_a)
{
    t_data *first;
    t_data *second;
    t_data *third;

    first = *stack_a;
    second = first->next;
    third = second->next;
    if (sorted(stack_a))
        return ;
    if (*(int *)first->content > *(int *)second->content && *(int *)first->content < *(int *)third->content)
        swap_a(stack_a, 1);
    else if (*(int *)first->content > *(int *)second->content && *(int *)first->content > *(int *)third->content)
    {
        rotate_a(stack_a);
        if (!sorted(stack_a))
            swap_a(stack_a, 1);
    }
    else if (*(int *)first->content < *(int *)second->content && *(int *)first->content > *(int *)third->content)
        reverse_rotate_a(stack_a);
    else if (*(int *)first->content < *(int *)second->content && *(int *)first->content < *(int *)third->content)
    {
        swap_a(stack_a, 1);
        rotate_a(stack_a);
    }
}

void    quartet_sort(t_data **stack_a, t_data **stack_b)
{
    //push smallest to stack_b
    if (get_min_idx(stack_a) < 2)
    {
        while (get_min_idx(stack_a) != 0)
        {
            rotate_a(stack_a);
        }
            
    }
    else
    {
        while (get_min_idx(stack_a) != 0)
        {
            reverse_rotate_a(stack_a);
        }
            
    }
    push_b(stack_a, stack_b);
    //sort stack a with 3 elements
    trio_sort(stack_a);
    //push smallest back to stack_a
    push_a(stack_b, stack_a);
}

void quintet_sort(t_data **stack_a, t_data **stack_b)
{
    if (get_min_idx(stack_a) < 2)
    {
        while (get_min_idx(stack_a) != 0)
            rotate_a(stack_a);
    }
    else
    {
        while (get_min_idx(stack_a) != 0)
            reverse_rotate_a(stack_a);
    }
    push_b(stack_a, stack_b);
    quartet_sort(stack_a, stack_b);
    push_a(stack_b, stack_a);
}