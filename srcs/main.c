/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:54:01 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/08 15:54:04 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char *argv[])
{
    t_list *stack_a;
    t_list *stack_b;

    init(argc, &stack_a, &stack_b);
    read_input(argc, argv, &stack_a);
    arrange_numbers(&stack_a, &stack_b);
    t_list *node;
    node = stack_a;
    ft_printf("Stack after sorting:\n");
    while (node)
    {
        ft_printf("%d\n", *(int *)node->content);
        node = node->next;
    }
    ft_lstclear(&stack_a, free);
}






void    init(int argc, t_list **stack_a, t_list **stack_b)
{
    if  (argc < 2)
        exit(0);
    *stack_a = NULL;
    *stack_b = NULL;
}


