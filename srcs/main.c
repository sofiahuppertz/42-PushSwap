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


//TODO: PARSING: check if arguments passed include only numbers.
//TODO: not print extra instructions when I do ss or rr or rrr.
//Optimize the smaller sorts.
int main(int argc, char *argv[])
{
    t_list *stack_a;
    t_list *stack_b;

    if  (argc < 2)
    {
        return 0;
    }
    stack_a = NULL;
    stack_b = NULL;
    make_stacks(argc, argv, &stack_a);
    //Sort the stack.
    sort(&stack_a, &stack_b);
    t_list *node;
    node = stack_a;
    ft_printf("Stack after sorting:\n");
    while (node)
    {
        ft_printf("%d\n", *(int *)node->content);
        node = node->next;
    }

}



