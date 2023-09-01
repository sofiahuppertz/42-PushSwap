/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:24 by shuppert          #+#    #+#             */
/*   Updated: 2023/08/28 19:01:33 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "42-Libft/libft/ft_printf.h"
# include "42-Libft/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void			*content;
	struct s_data	*next;
	int id;
	int pos; 
	int assoc_pos; 
	int moves_a;
	int moves_b;
	int cost;	
}					t_data; 

// index est la position finale de la valeur dans la pile triee
// ou est la valeur est actuellement dans B
// ou est la valeur associee dans A a la valeur presente dans B
// par rapport au milieu des piles (ra rra)
// cout est le calcul des valeurs relatives entre la posA et posB
//combien de instructions pour deplacer pos a et pos b en haut de leurs stacks + 1 (push_a), et en supprimant les repetitions car rr ou rrr.

void    big_sort(t_data **stack_a, t_data **stack_b, int size);
void	bucket_sort(t_data **stack_a, t_data **stack_b, int bound);
void calculate_quantile_bounds(int quantile_bounds[5], int *sorted_copy, int size);
void check_duplicates(int *num, t_data **list);
void delete_lst(t_data **lst, void (*del)(void *));
void delete_str_arr(char **str_arr);
void   error(t_data **list);
void handle_mixed_moves(t_data **stack_a, t_data **stack_b, int moves_a, int moves_b);
void handle_negative_moves(t_data **stack_a, t_data **stack_b, int moves_a, int moves_b);
void handle_positive_moves(t_data **stack_a, t_data **stack_b, int moves_a, int moves_b);
void insert_id(t_data **stack_a, int *sorted, int size);
void	insert_node(t_data **lst, t_data *new_lst);
void insert_num(int *num, char *temp, t_data **stack);
void iterate_and_set_cost(t_data **stack_a, t_data **stack_b); 
void min_cost_operation(t_data **stack_a, t_data **stack_b, t_data *min_cost_value);
void	minimum_cost_sort(t_data **stack_a, t_data **stack_b);
void parse(int argc, char *argv[], t_data **stack);
void perform_rotations(t_data **stack_a, t_data **stack_b, int moves_a, int moves_b);
void push_a(t_data **stack_b, t_data **stack_a);
void push_b(t_data **stack_a, t_data **stack_b);
void    push_swap(t_data **stack_a, t_data **stack_b);
void    quartet_sort(t_data **stack_a, t_data **stack_b);
void	quicksort(int *arr, int low, int high);
void quintet_sort(t_data **stack_a, t_data **stack_b);
void rearrange_stack(t_data **stack_a, int size);
void reverse_rotate_a(t_data **stack_a, int print);
void reverse_rotate_b(t_data **stack_b, int print);
void reverse_rotate_a_and_b(t_data **stack_a, t_data **stack_b);
void rotate_a(t_data **stack_a, int print);
void rotate_b(t_data **stack_b, int print);
void rotate_a_and_b(t_data **stack_a, t_data **stack_b);
void rotate_stack(t_data **stack, int big, int small, void(*rotate_func)(t_data **, int));
void set_assoc_pos(t_data *current, t_data **stack_a);
void set_holds(int *first_hold, int *last_hold, int *index, t_data **ptr, t_data **stack_a, int bound);
void set_inital_params(int *index, int *first_hold, int *last_hold, t_data **ptr, t_data **stack_a);
void set_pos(t_data *current, t_data **stack_b);
void sort_numbers(t_data **stack_a, t_data **stack_b, int **sorted_copy, int size);
void	swap(int *a, int *b);
void    swap_a(t_data **stack_a, int print);
void    swap_a_and_b(t_data **stack_a, t_data **stack_b);
void swap_b(t_data **stack_b, int print);
void trio_sort(t_data **stack_a);

int calculate_cost(t_data *current, int size_a, int size_b);
int	get_max(t_data **stack);
int		get_min(t_data **stack);
int get_min_idx(t_data **stack_a);
int	get_size(t_data *lst);
int is_numeric(char *str);
int	partition(int *arr, int low, int high);
int safe_atoi(char *str, t_data **list);
int sorted(t_data **stack_a);

t_data	*create_node(void *content);

#endif


//todo: faire le menage