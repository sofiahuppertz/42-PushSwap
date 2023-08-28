/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:54:08 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/08 15:54:11 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void    swap_a(t_data **stack_a, int print)
{
    t_data *first;
    t_data *second;
    t_data *third;

    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return ;
    
    first = *stack_a;
    second = first->next;
    third = second->next;
    first->next = third;
    second->next = first;
    *stack_a = second;
    if (print)
        ft_printf("sa\n");
}

void swap_b(t_data **stack_b, int print)
{
    t_data *first;
    t_data *second;
    t_data *third;

    if (!stack_b || !(*stack_b) || !(*stack_b)->next)
        return ;
    first = *stack_b;
    second = first->next;
    third = second->next;
    first->next = third;
    second->next = first;
    *stack_b = second;
    if (print)
        ft_printf("sb\n");
}

void    swap_a_and_b(t_data **stack_a, t_data **stack_b)
{
    swap_a(stack_a, 0);
    swap_b(stack_b, 0);
    ft_printf("ss\n");
}

void push_a(t_data **stack_b, t_data **stack_a)
{
    t_data *first;
    t_data *second;

    if (!stack_b || !(*stack_b))
        return ;
    first = *stack_b;
    second = first->next;
    first->next = *stack_a;
    *stack_a = first;
    *stack_b = second;
    ft_printf("pa\n");
}

void push_b(t_data **stack_a, t_data **stack_b)
{
    t_data *first;
    t_data *second;

    if (!stack_a || !(*stack_a))
        return ;
    first = *stack_a;
    second = first->next;
    first->next = *stack_b;
    *stack_b = first;
    *stack_a = second;
    ft_printf("pb\n");
}

void rotate_a(t_data **stack_a)
{
    t_data *first;
    t_data *last;

    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return ;
    
    first = *stack_a;
    last = first;
    while (last->next)
        last = last->next;
    last->next = first;
    *stack_a = first->next;
    first->next = NULL;
    ft_printf("ra\n");
}

void reverse_rotate_a(t_data **stack_a)
{
    t_data *previous;
    t_data *last;

    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return ;
    previous = *stack_a;
    last = previous->next;
    while (last->next)
    {

        previous = last;
        last = last->next;
    }
    last->next = *stack_a;
    *stack_a = last;
    previous->next = NULL;
    ft_printf("rra\n");
}

