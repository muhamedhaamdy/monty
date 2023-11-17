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


/**
 * swap - swap the top two elements of the stack
 *
 * @stack : the stack
 * @line_number : the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int tmp;

    UNSUSED(stack);
    UNSUSED(line_number);
    if (!info.head || !info.head->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short", info.line_num);
        exit(EXIT_FAILURE);
    }
    tmp = info.head->n;
    info.head->n = info.head->next->n;
    info.head->next->n = tmp;
}

/**
 * add - add the top two elements of the stack
 *
 * @stack : the stack
 * @line_number : the line number
 */
void add(stack_t **stack, unsigned int line_number)
{
    int tmp;

    UNSUSED(stack);
    UNSUSED(line_number);
    if (!info.head || !info.head->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short", info.line_num);
        exit(EXIT_FAILURE);
    }
    tmp = info.head->n;
    info.head->n = info.head->next->n + tmp;
    pop(stack, line_number);
}
 
/**
 * nop - do nothing
 *
 * @stack : the stack
 * @line_number : the line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
    UNSUSED(stack);
    UNSUSED(line_number);
}
