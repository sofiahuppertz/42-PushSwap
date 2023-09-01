/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:54:01 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/28 16:41:06 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char *argv[])
{
    t_data *stack_a;
    t_data *stack_b;

    if  (argc < 2)
        exit(0);
    stack_a = NULL;
    stack_b = NULL;
    parse(argc, argv, &stack_a);
    push_swap(&stack_a, &stack_b);
    delete_lst(&stack_a, free);
    delete_lst(&stack_b, free);
}