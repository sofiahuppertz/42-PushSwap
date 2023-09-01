#include "../push_swap.h"

void min_cost_operation(t_data **stack_a, t_data **stack_b, t_data *min_cost_value)
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

void perform_rotations(t_data **stack_a, t_data **stack_b, int moves_a, int moves_b) {
    if (moves_a > 0 && moves_b > 0) {
        handle_positive_moves(stack_a, stack_b, moves_a, moves_b);
    } else if (moves_a < 0 && moves_b < 0) {
        handle_negative_moves(stack_a, stack_b, moves_a, moves_b);
    } else {
        handle_mixed_moves(stack_a, stack_b, moves_a, moves_b);
    }
}

void handle_positive_moves(t_data **stack_a, t_data **stack_b, int moves_a, int moves_b) {
    if (moves_a > moves_b) {
        while (moves_a > moves_b) {
            rotate_a(stack_a, 1);
            moves_a--;
        }
        while (moves_a > 0) {
            rotate_a_and_b(stack_a, stack_b);
            moves_a--;
        }
    } else {
        while (moves_b > moves_a) {
            rotate_b(stack_b, 1);
            moves_b--;
        }
        while (moves_b > 0) {
            rotate_a_and_b(stack_a, stack_b);
            moves_b--;
        }
    }
}

void handle_negative_moves(t_data **stack_a, t_data **stack_b, int moves_a, int moves_b) {
    if (moves_a < moves_b) {
        while (moves_a < moves_b) {
            reverse_rotate_a(stack_a, 1);
            moves_a++;
        }
        while (moves_b < 0) {
            reverse_rotate_a_and_b(stack_a, stack_b);
            moves_b++;
        }
    } else {
        while (moves_a > moves_b) {
            reverse_rotate_b(stack_b, 1);
            moves_b++;
        }
        while (moves_b < 0) {
            reverse_rotate_a_and_b(stack_a, stack_b);
            moves_b++;
        }
    }
}

void handle_mixed_moves(t_data **stack_a, t_data **stack_b, int moves_a, int moves_b)
{
    while (moves_a > 0) {
        rotate_a(stack_a, 1);
        moves_a--;
    }
    while (moves_a < 0) {
        reverse_rotate_a(stack_a, 1);
        moves_a++;
    }
    while (moves_b > 0) {
        rotate_b(stack_b, 1);
        moves_b--;
    }
    while (moves_b < 0) {
        reverse_rotate_b(stack_b, 1);
        moves_b++;
    }
}

