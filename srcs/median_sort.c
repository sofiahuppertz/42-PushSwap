/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:52 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/08 16:49:51 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    median_sort(t_list **stack_a, t_list **stack_b, const int n)
{
    int stack_size;
    int max_value;
    int median;

    stack_size = n;
    max_value = get_max(stack_a);
    while (stack_size > 3)
    {
        if (sorted(stack_a))
            break;
        median = calculate_median(stack_a, stack_size);
        extract_lower_bound(stack_a, stack_b, median, stack_size);
        stack_size = ft_lstsize(*stack_a);
    }
    if (!(sorted(stack_a)))
    {
        if (stack_size == 3)
            sort_3(stack_a);
        if (stack_size == 2)
        {
            if (rev_top_two(stack_b))
                swap_a_and_b(stack_a, stack_b);
            else
                swap_a(stack_a);
        }
    }
    fit_back(stack_a, stack_b, max_value);
}


void fit_back(t_list **stack_a, t_list **stack_b, int max_value)
{
    t_list *iter;
    t_list *top_b;
    t_list *top_a;
    t_list *bottom_a;

    
    while (*stack_b)
    {
        iter = *stack_a;
        top_a = iter;
        while (iter)
        {
            bottom_a = iter;
            iter = iter->next;
        }
        top_b = *stack_b;
        if (*(int *)top_b->content > *(int *)top_a->content)
            rotate_a(stack_a);
        else if (*(int *)top_b->content < *(int *)bottom_a->content && *(int *)bottom_a->content != max_value)
            reverse_rotate_a(stack_a);
        else
            push_a(stack_b, stack_a);     
    }
    
}

void extract_lower_bound(t_list **stack_a, t_list **stack_b, int median, const int size)
{
    int n;
    t_list *top;

    n = size;
    top = *stack_a;
    while (n > 0)
    {
        if(sorted(stack_a))
            break;
        if (*(int *)top->content < median)
        {
            push_b(stack_a, stack_b);
        }
        else
        {
            rotate_a(stack_a);
        }
        n--;
    }       
}

int rev_top_two(t_list **stack)
{
    t_list *first;
    t_list *next;

    first = *stack;
    next = first->next;

    if (*(int *)first->content < *(int *)next->content)
        return (1);
    else
        return (0); 
    
}
