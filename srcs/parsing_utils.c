#include "../push_swap.h"


int safe_atoi(char *str, t_list **head, t_list **char_args)
{
    int	i;
    long int	neg;
	long int num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	num = num * neg;
    if (num > INT_MAX || num < INT_MIN) //30 minutes debugging because this '-' sign is encoded with Unicode and not
        ft_error(head, char_args);
    return ((int)num);
}

void check_duplicates(int *num, t_list **head, t_list **char_args)
{
    t_list *current;

    if (!head || !(*head))
        return ;
    current = *head;
    while (current)
    {
        if (*(int *)current->content == *num)
        {
            free(num);
            ft_error(head, char_args);
        }
        current = current->next;
    }
    return ;
}


void   ft_error(t_list **head_1, t_list **head_2)
{
    ft_printf("Error\n");
    ft_lstclear(head_1, free);
    ft_lstclear(head_2, free);
    exit(1);
}

int is_numeric(char *str)
{
    int i;

    i = 0;
    if (str[0] == '-' || str[0] == '+')
    {
        i = 1;
        if (!str[i])
            return (0); 
    }
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return (0);
        }       
        i += 1;
    }
    return (1);
}

void clear(t_list **head)
{
    t_list *current;
    t_list *next;
    char **temp;
    int i;

    if (!head || !(*head))
        return ;
    current = *head;
    while (current)
    {

        next = current->next;
        temp = (char **)current->content;
        i = 0;
        while(temp[i])
        {
            free(temp[i]);
            i += 1;
        }
        free(temp);
        free(current);
        current = next;
    }
    *head = NULL;
}