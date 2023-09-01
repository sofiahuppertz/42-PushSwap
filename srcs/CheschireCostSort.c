
#include "../push_swap.h"

void	minimum_cost_sort(t_data **stack_a, t_data **stack_b)
{
	t_data	*min_cost_value;
	t_data	*ptr;

	min_cost_value = NULL;
	while (*stack_b)
	{
		iterate_and_set_cost(stack_a, stack_b);
		min_cost_value = *stack_b;
		ptr = (*stack_b)->next;
		while (ptr)
		{
			if (ptr->cost < min_cost_value->cost)
				min_cost_value = ptr;
			ptr = ptr->next;
		}
		if (!min_cost_value)
			return;
		min_cost_operation(stack_a, stack_b, min_cost_value);
	}
}

int calculate_cost(t_data *current, int size_a, int size_b)
{
	int cost;

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

void iterate_and_set_cost(t_data **stack_a, t_data **stack_b) 
{
    t_data *current = *stack_b;
	int size_a;
	int size_b;
	size_a = get_size(*stack_a);
	size_b = get_size(*stack_b);
    while (current)
	{
		set_pos(current, stack_b);
		set_assoc_pos(current, stack_a);
    	current->cost = calculate_cost(current, size_a, size_b);
        current = current->next;
    }
}

void set_pos(t_data *current, t_data **stack_b) 
{
    int i = 0;
    t_data *ptr = *stack_b;
    
    while (ptr) {
        if (ptr->id == current->id) {
            current->pos = i;
            return;
        }
        i++;
        ptr = ptr->next;
    }
}

void set_assoc_pos(t_data *current, t_data **stack_a)
{
    int i = 0;
    int min_a = get_min(stack_a);
    t_data *ptr = *stack_a;
    
    current->assoc_pos = -1;
    if (min_a > *(int *)current->content) {
        current->assoc_pos = get_min_idx(stack_a);
        return;
    }
    
    while (ptr) {
        if (*(int *)ptr->content < *(int *)current->content) {
            if (ptr->next && (*(int *)ptr->next->content > *(int *)current->content)) {
                current->assoc_pos = i + 1;
                return;
            } else if (!ptr->next && current->assoc_pos == -1) {
                current->assoc_pos = i + 1;
                return;
            }
        }
        i++;
        ptr = ptr->next;
    }
}



