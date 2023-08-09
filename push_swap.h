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
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

void	arrange_numbers(t_list **stack_a, t_list **stack_b);
int		calculate_median(t_list **stack_a, int n);
void check_forbidden(int *num, t_list **head, t_list **char_args);
int		check_reversed_top(t_list **stack);
void	clear(t_list **head);
void	extract_lower_bound(t_list **stack_a, t_list **stack_b, int median,
			const int size);
int		find_min(t_list **stack_a);
void   ft_error(t_list **head_1, t_list **head_2);
int		get_max(t_list **stack);
void    init(int argc, t_list **stack_a, t_list **stack_b);
int build_cache_and_count(int argc, char *argv[], t_list **char_args);
void get_top_and_bottom(t_list *stack, t_list **top, t_list **bottom);
int is_numeric(char *str);
void fill_up_stack(t_list **args_char, t_list **head);
int read_input(int argc, char *argv[], t_list **stack);
void	median_sort(t_list **stack_a, t_list **stack_b, int size);
int safe_atoi(char *str, t_list **head, t_list **char_args);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	swap(int *a, int *b);
void	swap_a(t_list **stack_a, int print);
void	swap_b(t_list **stack_b, int print);
void 	swap_a_and_b(t_list **stack_a, t_list **stack_b);
int		partition(int *arr, int low, int high);
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
void	quicksort(int *arr, int low, int high);
void rearrange_stack_a(t_list **stack_a, t_list **stack_b, int max_value);
void	rotate_a(t_list **stack_a);
void	reverse_rotate_a(t_list **stack_a);
int		sorted(t_list **stack_a);

#endif