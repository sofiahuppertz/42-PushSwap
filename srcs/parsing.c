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

int make_stacks(int argc, char *argv[], t_list **head)
{
    int size;
    t_list *char_args;

    char_args = NULL;
    size = get_size(argc, argv, &char_args);
    if (size == 0)
        exit(0);
    load_stack(&char_args, head);
    return (size);
}

int get_size(int argc, char *argv[], t_list **char_args)
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
            ft_error(char_args);
        ft_lstadd_back(char_args, node);
        i += 1;
    }
    return (size);
}

//TODO: check Errors: if there is a duplicate number, if there is a non-numeric argument, bigger or smaler than int type.
void load_stack(t_list **args_char, t_list **head)
{
    int size;
    int index;
    int *num;
    char **str_array;
    t_list *current;
    t_list *new;

    if (!args_char || !(*args_char))
        return;
    current = *args_char;
    while (current)
    {
        index = 0;
        str_array = (char **)current->content;
        size = str_array_length((const char **)str_array);
        while (index < size)
        {
            num = (int *)malloc(sizeof(int));
            if (!num || !(is_numeric(str_array[index])))
                ft_error(head);
            *num = ft_atoi(str_array[index]);
            check_forbidden(num, head);
            new = ft_lstnew((void *)num);
            if (!new)
                ft_error(head);
            ft_lstadd_back(head, new);
            index += 1;
        }
        current = current->next;
    }
    ft_lstclear(args_char, free);

}


void check_forbidden(int *num, t_list **head)
{
    t_list *current;

    if (*num < -2147483648 || *num > 2147483647)
    {
        free(num);
        ft_error(head);
    }
    if (!head || !(*head))
        return ;
    current = *head;
    while (current)
    {
        if (*(int *)current->content == *num)
        {
            free(num);
            ft_error(head);
        }
        current = current->next;
    }
    return ;
}


void   ft_error(t_list **head)
{
    ft_printf("Error\n");
    ft_lstclear(head, free);
    exit(1);
}

int is_numeric(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-')
        i += 1;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i += 1;
    }
    return (1);
}
