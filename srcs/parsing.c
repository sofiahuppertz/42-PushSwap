/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:46 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/28 18:50:25 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void parse(int argc, char *argv[], t_data **stack)
{
    char **temp;
    int *num;
    int i;
    int j;


    if (!stack)
        error(stack);
    i = 1;
    num = NULL;
    while (i < argc)
    {
        temp = ft_split((const char *)argv[i], ' ');
        j = 0;
        while (temp[j])
        {
            insert_num(num, temp[j], stack);
            j += 1;
        }
        delete_str_arr(temp);           
        i += 1;
    }
}

void insert_num(int *num, char *temp, t_data **stack)
{
    t_data *new;

    num = (int *)malloc(sizeof(int));
    if (!num)
        error(stack);
    if (!is_numeric(temp))
    {
        free(num);
        error(stack);
    }
    *num = safe_atoi(temp, stack);
    check_duplicates(num, stack);
    new = create_node((void *)num);
    if (!new)
        error(stack);
    insert_node(stack, new);
}


