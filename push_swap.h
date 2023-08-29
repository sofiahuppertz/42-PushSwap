/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:24 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/29 13:06:55 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "TeaParty/MadHatter/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void			*content;
	struct s_data	*next;
	int				idx;
	int				pos;
	int				assoc_pos;
	int				cost;
}					t_data;

void				insert_num(int *num, char *temp, t_data **stack);
void				check_duplicates(int *num, t_data **list);
void				delete_lst(t_data **lst, void (*del)(void *));
void				delete_str_arr(char **str_arr);
void				error(t_data **list);
void				extract_lower_bound(t_data **stack_a, t_data **stack_b,
						int median, int size);
void				gigantous_sort(t_data **stack_a, t_data **stack_b,
						int size);
void				insert_node(t_data **lst, t_data *new_lst);
void				group_by_median(t_data **stack_a, t_data **stack_b,
						int size);
void				swap(int *a, int *b);
void				swap_a(t_data **stack_a, int print);
void				swap_a_and_b(t_data **stack_a, t_data **stack_b);
void				swap_b(t_data **stack_b, int print);
void				parse(int argc, char *argv[], t_data **stack);
void				push_a(t_data **stack_b, t_data **stack_a);
void				push_b(t_data **stack_a, t_data **stack_b);
void				push_swap(t_data **stack_a, t_data **stack_b);
void				quartet_sort(t_data **stack_a, t_data **stack_b);
void				quicksort(int *arr, int low, int high);
void				quintet_sort(t_data **stack_a, t_data **stack_b);
void				reverse_rotate_a(t_data **stack_a);
void				rotate_a(t_data **stack_a);
void				trio_sort(t_data **stack_a);

int					calculate_median(t_data **stack_a, int n);
int					check_reversed_top(t_data **stack);
int					get_max(t_data **stack);
int					get_min_idx(t_data **stack_a);
int					get_size(t_data *lst);
int					is_numeric(char *str);
int					partition(int *arr, int low, int high);
int					safe_atoi(char *str, t_data **list);
int					sorted(t_data **stack_a);

t_data				*create_node(void *content);

#endif

//todo: faire le menage