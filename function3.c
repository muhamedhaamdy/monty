#include "monty.h"


/**
 * div - divide the top two elements of the stack
 * 
 * @stack : the stack 
 * @line_number : the line number 
 */
void div(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    UNSUSED(stack);
    UNSUSED(line_number);
    if (!info.head || !info.head->next)
    {
        fprintf(stderr, "L%d: can't div, stack too short", info.line_num);
        exit(EXIT_FAILURE);
    }
    if (info.head->n == 0)
    {
        fprintf(stderr, "L%d: division by zero", info.line_num);
        exit(EXIT_FAILURE);
    }
    tmp = info.head;
    info.head = info.head->next;
    info.head->n = info.head->n / tmp->n;
    free(tmp);
}

/**
 * mul - multiply the top two elements of the stack
 * 
 * @stack : the stack 
 * @line_number : the line number 
 */
void mul(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    UNSUSED(stack);
    UNSUSED(line_number);
    if (!info.head || !info.head->next)
    {
        fprintf(stderr, "L%d: can't mul, stack too short", info.line_num);
        exit(EXIT_FAILURE);
    }
    tmp = info.head;
    info.head = info.head->next;
    info.head->n = info.head->n * tmp->n;
    free(tmp);
}

/**
 * mod - compute the rest of the division of the top two elements of the stack
 * 
 * @stack : the stack 
 * @line_number : the line number 
 */
void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    UNSUSED(stack);
    UNSUSED(line_number);
    if (!info.head || !info.head->next)
    {
        fprintf(stderr, "L%d: can't mod, stack too short", info.line_num);
        exit(EXIT_FAILURE);
    }
    if (info.head->n == 0)
    {
        fprintf(stderr, "L%d: division by zero", info.line_num);
        exit(EXIT_FAILURE);
    }
    tmp = info.head;
    info.head = info.head->next;
    info.head->n = info.head->n % tmp->n;
    free(tmp);
}
