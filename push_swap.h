
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "42-Libft/libft/libft.h"
# include "42-Libft/libft/ft_printf.h"

int get_size(int argc, char *argv[], char ***args);
void load_stack(int argc, char **args, t_list **head, int size);
void make_stacks(int argc, char *argv[], t_list **head);
void    memory_error(t_list **head);

#endif