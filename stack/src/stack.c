#include "../headers/stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief initialize the stack
 *
 * top stores the current index of the last element inserted in
 * the stack
 *
 * @param *stack reference to the stack
 */
void initialize_stack(struct Stack *stack) { stack->top = -1; }
