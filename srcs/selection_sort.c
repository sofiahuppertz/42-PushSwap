#include "../push_swap.h"

void selection_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int index_min;
    int i;
    int j;

    i = size;
    while (i > 0)
    {
        if (sorted(stack_a))
            break ;
        index_min = find_min(stack_a);
        if (index_min <= i / 2)
        {
            if (index_min == 1)
            {
                swap_a(stack_a);
            }
            else
            {
                while (find_min(stack_a) > 0)
                {
                    rotate_a(stack_a);
                }
            }
        }
        else if (index_min > i / 2)
        {
            while (find_min(stack_a) > 0)
            {
                reverse_rotate_a(stack_a);
            }
        }
        push_b(stack_a, stack_b);
        i -= 1;
    }
    //Push back all elements from stack_b to stack_a.
    j = 0;
    while (j < size - i)
    {
        push_a(stack_b, stack_a);
        j += 1;
    }
}