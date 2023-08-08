/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:24 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/08 16:50:38 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "42-Libft/libft/ft_printf.h"
# include "42-Libft/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

int		calculate_median(t_list **stack_a, int n);
void	extract_lower_bound(t_list **stack_a, t_list **stack_b, int median,
			const int size);
int		find_min(t_list **stack_a);
void	fit_back(t_list **stack_a, t_list **stack_b, int max_value);
int		get_max(t_list **stack);
int		get_size(int argc, char *argv[], char ***args);
void	load_stack(int argc, char **args, t_list **head, int size);
int		make_stacks(int argc, char *argv[], t_list **head);
void	memory_error(t_list **head);
void	median_sort(t_list **stack_a, t_list **stack_b, const int n);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	swap(int *a, int *b);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a_and_b(t_list **stack_a, t_list **stack_b);
int		partition(int **arr, int low, int high);
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
void	quicksort(int **arr, int low, int high);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
int		rev_top_two(t_list **stack);
void	sort(t_list **stack_a, t_list **stack_b);
int		sorted(t_list **stack_a);

#endif