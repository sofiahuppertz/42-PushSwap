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


void sort_3(t_list **stack_a)
{
    t_list *first;
    t_list *second;
    t_list *third;

    first = *stack_a;
    second = first->next;
    third = second->next;
    if (sorted(stack_a))
        return ;
    if (*(int *)first->content > *(int *)second->content && *(int *)first->content < *(int *)third->content)
        swap_a(stack_a);
    else if (*(int *)first->content > *(int *)second->content && *(int *)first->content > *(int *)third->content)
    {
        rotate_a(stack_a);
        if (!sorted(stack_a))
            swap_a(stack_a);
    }
    else if (*(int *)first->content < *(int *)second->content && *(int *)first->content > *(int *)third->content)
        reverse_rotate_a(stack_a);
    else if (*(int *)first->content < *(int *)second->content && *(int *)first->content < *(int *)third->content)
    {
        swap_a(stack_a);
        rotate_a(stack_a);
    }
}

void    sort_4(t_list **stack_a, t_list **stack_b)
{
    //push smallest to stack_b
    if (find_min(stack_a) < 2)
    {
        while (find_min(stack_a) != 0)
        {
            rotate_a(stack_a);
        }
            
    }
    else
    {
        while (find_min(stack_a) != 0)
        {
            reverse_rotate_a(stack_a);
        }
            
    }
    push_b(stack_a, stack_b);
    //sort stack a with 3 elements
    sort_3(stack_a);
    //push smallest back to stack_a
    push_a(stack_b, stack_a);
}

void sort_5(t_list **stack_a, t_list **stack_b)
{
    if (find_min(stack_a) < 2)
    {
        while (find_min(stack_a) != 0)
            rotate_a(stack_a);
    }
    else
    {
        while (find_min(stack_a) != 0)
            reverse_rotate_a(stack_a);
    }
    push_b(stack_a, stack_b);
    sort_4(stack_a, stack_b);
    push_a(stack_b, stack_a);
}