/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:46 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/08 15:53:49 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int read_input(int argc, char *argv[], t_list **stack)
{
    int total_numbers;
    t_list *cache;

    cache = NULL;
    total_numbers = build_cache_and_count(argc, argv, &cache);
    if (total_numbers <= 0)
        exit(0);
    fill_up_stack(&cache, stack);
    clear(&cache);
    return (total_numbers);
}

int build_cache_and_count(int argc, char *argv[], t_list **char_args)
{
    t_list *node;
    char **temp;
    int size;
    int i;

    size = 0;
    i = 1;
    while (i < argc)
    {
        temp = ft_split((const char *)argv[i], ' ');
        size += str_array_length((const char **)temp);
        node = ft_lstnew((void *)temp);
        if(!node)
        {
            ft_error(char_args, NULL);
        }
        ft_lstadd_back(char_args, node);
        i += 1;
    }
    return (size);
}

void fill_up_stack(t_list **args_char, t_list **head)
{
    int index;
    int *num;
    char **str_array;
    t_list *current;


    if (!args_char || !(*args_char))
        return;
    current = *args_char;
    while (current)
    {
        index = 0;
        str_array = (char **)current->content;
        num = NULL;
        while (str_array[index])
        {
            add_number(num, str_array[index], head, args_char);
            index += 1;
        }
        current = current->next;
    }
}

void add_number(int *num, char *str_num, t_list **head, t_list **char_args)
{
    t_list *new;

    num = (int *)malloc(sizeof(int));
    if (!num || !(is_numeric(str_num)))
    {
        ft_error(head, char_args);
    }
    *num = safe_atoi(str_num, head, char_args);
    check_duplicates(num, head, char_args);
    new = ft_lstnew((void *)num);
    if (!new)
        ft_error(head, char_args);
    ft_lstadd_back(head, new);
}