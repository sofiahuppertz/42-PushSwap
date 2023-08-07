
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "42-Libft/libft/libft.h"
# include "42-Libft/libft/ft_printf.h"

int find_min(t_list **stack_a);
int get_size(int argc, char *argv[], char ***args);
void load_stack(int argc, char **args, t_list **head, int size);
int make_stacks(int argc, char *argv[], t_list **head);
void    memory_error(t_list **head);
void selection_sort(t_list **stack_a, t_list **stack_b, int size);
void sort_3(t_list **stack_a);
void    sort_4(t_list **stack_a, t_list **stack_b);
void    sort_5(t_list **stack_a, t_list **stack_b);
void    swap_a(t_list **stack_a);
void    swap_b(t_list **stack_b);
void    swap_a_and_b(t_list **stack_a, t_list **stack_b);
void    push_a(t_list **stack_b, t_list **stack_a);
void    push_b(t_list **stack_a, t_list **stack_b);
void    rotate_a(t_list **stack_a);
void    rotate_b(t_list **stack_b);
void    rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void    reverse_rotate_a(t_list **stack_a);
void    reverse_rotate_b(t_list **stack_b);
void    reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void    sort(t_list **stack_a, t_list **stack_b);
int sorted(t_list **stack_a);

#endif