
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

typedef struct _stack Stack;

Stack *stack_create();
void stack_push(Stack *s, Item value);
Item stack_pop(Stack *s);
bool stack_is_empty(Stack *s);
void stack_destroy(Stack **s);

Item stack_top(Stack *s);

#endif // __STACK_H__