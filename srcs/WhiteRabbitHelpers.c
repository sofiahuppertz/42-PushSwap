/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WhiteRabbitHelpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:01:02 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/02 20:21:14 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_duplicates(int *num, t_data **list)
{
	t_data	*current;

	if (!list || !(*list))
		return ;
	current = *list;
	while (current)
	{
		if (*(int *)current->data == *num)
		{
			free(num);
			error(list);
		}
		current = current->next;
	}
	return ;
}

void	delete_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i += 1;
	}
	free(str_arr);
}

void	error(t_data **list)
{
	write(1, "It seems your out of space.\n", 28);
	if (list)
		delete_lst(list, free);
	exit(1);
}

int	is_numeric(char *str)
{
	int	i;

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

int	safe_atoi(char *str, t_data **list)
{
	int			i;
	long int	neg;
	long int	num;

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
	if (num > INT_MAX || num < INT_MIN)
		error(list);
	return ((int)num);
}
