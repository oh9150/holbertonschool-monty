#include "monty.h"

/**
* mod - computes the rest of the division from the second top element by the
* top one, the result is stored in the second element and the first one is
* removed
* @stack: the stack
* @line_number: the line number
*/
void mod(stack_t **stack, unsigned int line_number)
{
        int i = 0;
        stack_t *tmp = *stack;
        while (tmp)
        {
                i++;
                tmp = tmp->next;
        }
        if (i < 2)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        if ((*stack)->n == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", line_number);
                exit(EXIT_FAILURE);
        }
        ((*stack)->next)->n %= (*stack)->n;
        pop(stack, line_number);
}
