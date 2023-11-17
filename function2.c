#include "monty.h"

/**
 * pop - pop an element from the stack
 *
 * @stack : the stack
 * @line_number : the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    UNSUSED(stack);
    UNSUSED(line_number);
    if (!info.head)
    {
        fprintf(stderr, "L%d: can't pop an empty stack", info.line_num);
        exit(EXIT_FAILURE);
    }
    tmp = info.head;
    info.head = info.head->next;
    if (info.head)
        info.head->prev = NULL;
    free(tmp);
}