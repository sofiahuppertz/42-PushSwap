
#include "../push_swap.h"


void	minimum_cost_sort(t_data **stack_a, t_data **stack_b)
{
	t_data	*current;
	int size_a;
	int size_b;
	t_data	*min_cost_value;

	while (*stack_b)
	{
		current = *stack_b;
		while (current)
		{
			size_a = get_size(*stack_a);
			size_b = get_size(*stack_b);
			set_info(current, stack_a, stack_b);
			current->cost = calculate_cost(current, size_a, size_b);
			current = current->next;
		}
		/*
		printf("stack_b\n");
		t_data *ptr = *stack_b;
		while (ptr)
		{
			printf("value: %d id: %d, pos: %d, assoc_pos: %d, cost: %d, moves_a: %d, moves_b: %d\n",*(int*)ptr->content, ptr->id, ptr->pos, ptr->assoc_pos, ptr->cost, ptr->moves_a, ptr->moves_b);
			ptr = ptr->next;
		}
		printf("stack_a\n");
		ptr = *stack_a;
		while (ptr)
		{
			printf("value: %d, id: %d, pos: %d, assoc_pos: %d, cost: %d, moves_a: %d, moves_b: %d\n", *(int*)ptr->content, ptr->id, ptr->pos, ptr->assoc_pos, ptr->cost, ptr->moves_a, ptr->moves_b);
			ptr = ptr->next;
		}
		*/
		min_cost_value = get_min_cost_value(*stack_b);
		if (!min_cost_value)
			return;
		do_cheapest_move(stack_a, stack_b, min_cost_value);
	}
}

void do_cheapest_move(t_data **stack_a, t_data **stack_b, t_data *min_cost_value)
{
	if (min_cost_value->cost == 0)
	{
		push_a(stack_b, stack_a);
		return;
	}
	perform_rotations(stack_a, stack_b, min_cost_value->moves_a, min_cost_value->moves_b);
	push_a(stack_b, stack_a);
	return;
}

void perform_rotations(t_data **stack_a, t_data **stack_b, int moves_a, int moves_b)
{

	if (moves_a > 0 && moves_b > 0)
	{
		if (moves_a > moves_b)
		{
			while (moves_a > moves_b)
			{
				rotate_a(stack_a, 1);
				moves_a -= 1;
			}	
			while (moves_a > 0)
			{
				rotate_a_and_b(stack_a, stack_b);
				moves_a -= 1;
			}
				
		}
		else
		{
			while (moves_b > moves_a)
			{
				rotate_b(stack_b, 1);
				moves_b -= 1;
			}	
			while (moves_b > 0)
			{
				rotate_a_and_b(stack_a, stack_b);
				moves_b -= 1;
			}	
		}	
	}
	else if (moves_a < 0  && moves_b < 0)
	{
		if (moves_a < moves_b)
		{
			while (moves_a < moves_b)
			{
				reverse_rotate_a(stack_a, 1);
				moves_a += 1;
			}
			while (moves_b < 0)
			{
				reverse_rotate_a_and_b(stack_a, stack_b);
				moves_b += 1;
			}
		}
		else
		{
			while (moves_a > moves_b)
			{
				reverse_rotate_b(stack_b, 1);
				moves_b += 1;
			}
			while (moves_b < 0)
			{
				reverse_rotate_a_and_b(stack_a, stack_b);
				moves_b += 1;
			}
		}
	}
	else 
	{
		while (moves_a > 0)
		{
			rotate_a(stack_a, 1);
			moves_a -= 1;
		}
		while (moves_a < 0)
		{
			reverse_rotate_a(stack_a, 1);
			moves_a += 1;
		}
		while (moves_b > 0)
		{
			rotate_b(stack_b, 1);
			moves_b -= 1;
		}
		while (moves_b < 0)
		{
			reverse_rotate_b(stack_b, 1);
			moves_b += 1;
		}
	}
}

t_data 	*get_min_cost_value(t_data *stack_b)
{
	t_data *min_cost_value;
	t_data *ptr;
	min_cost_value = stack_b;
	ptr = stack_b->next;
	while (ptr)
	{
		if (ptr->cost < min_cost_value->cost)
			min_cost_value = ptr;
		ptr = ptr->next;
	}
	return (min_cost_value);
}


int calculate_cost(t_data *current, int size_a, int size_b)
{
	int cost;

	//printf("current: %d, pos: %d, assoc_pos: %d\n", *(int *)current->content, current->pos, current->assoc_pos);
	//printf("size_a: %d, size_b: %d\n", size_a, size_b);
	if (current->pos > size_b / 2)
		current->moves_b = -1 * (size_b - current->pos);
	else
		current->moves_b = current->pos;
	
	if (current->assoc_pos > size_a / 2)
		current->moves_a = -1 * (size_a - current->assoc_pos);
	else
		current->moves_a = current->assoc_pos;
	cost = abs(current->moves_a) + abs(current->moves_b);
	return(cost);

}

void set_info(t_data *current, t_data **stack_a, t_data **stack_b)
{
	int i;
	int min_a;
	t_data *ptr;

// 1. Set pos.
	ptr = *stack_b;
	i = 0;
	while (ptr)
	{
		if (ptr->id == current->id)
		{
			current->pos = i;
			break ;
		}
		i++;
		ptr = ptr->next;
	}
// 2. Set assoc_pos.
	min_a = get_min(stack_a);
	current->assoc_pos = -1;
	if (min_a > *(int *)current->content)
		current->assoc_pos = get_min_idx(stack_a);
	else
	{
		i = 0;
		ptr = *stack_a;
		while (ptr)
		{
			if (*(int *)ptr->content < *(int *)current->content)
			{
				if (ptr->next)
				{
					if (*(int *)ptr->next->content > *(int *)current->content)	
					{
						current->assoc_pos = i + 1;
					}	
				}
				else if (!ptr->next && current->assoc_pos == -1)
				{
					current->assoc_pos = i + 1;
				}
			}
			ptr = ptr->next;
			i += 1;
		}
	}	
}

int		get_min(t_data **stack)
{
	t_data	*ptr;
	int		min;

	ptr = *stack;
	min = *(int *)ptr->content;
	while (ptr)
	{
		if (*(int *)ptr->content < min)
			min = *(int *)ptr->content;
		ptr = ptr->next;
	}
	return (min);
}