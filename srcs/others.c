#include "../push_swap.h"

//GET STACK: stack can be passed in a single argument or many. 
//List where first arg is the top of the stack
void make_stacks(int argc, char *argv[], t_list **head)
{
    int size;
    char **args;

    size = get_size(argc, argv, &args);
    load_stack(argc, args, head, size);

}

int get_size(int argc, char *argv[], char ***args)
{
    int size;

    size = 0;
    if (argc == 2)
    {
        *args = ft_split((const char *)argv[1], ' ');
        size = str_array_length((const char **)args);
    }
    else
    {
        *args = argv;
        while ((*args)[size])
        {
            size += 1;
        }
        size = size - 1; //arg[0] isn't a number
    }
    return(size);
}


void load_stack(int argc, char **args, t_list **head, int size)
{
    int index;
    int *content;
    t_list *new;

    index = 0;
    while (index < size)
    {
        content = (int *)malloc(sizeof(int));
        if (!content)
            memory_error(head);
        *content = (argc == 2) ? ft_atoi(args[index]): ft_atoi(args[index + 1]);
        new = ft_lstnew((void *)content);
        if (!new)
            memory_error(head);
        ft_lstadd_back(head, new);
        index += 1;
    }
    if (argc == 2)
    {
        while (size-- >= 0)
            free(args[size]);
        free(args);
    }
}

void    memory_error(t_list **head)
{
    ft_printf("Memory allocation error\n");
    ft_lstclear(head, free);
    exit(1);
}

