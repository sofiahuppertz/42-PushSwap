#include "../push_swap.h"

int main(int argc, char *argv[])
{
    t_list *stack_a;
    //t_list **stack_b;
    if  (argc < 2)
    {
        return 0;
    }
    stack_a = NULL;
    //stack_b = NULL;
    make_stacks(argc, argv, &stack_a);
    //Sort the stack
    //Display the instructions I used to sort the stack

}



