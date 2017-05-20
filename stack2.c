#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


void stack_print(Stack *s)
{
    Stack *helper_stack = stack_create(1);
    while(!stack_is_empty(s)) {
        printf(">%d\n", stack_top(s));
        stack_push(helper_stack, stack_pop(s));
    }
    while(!stack_is_empty(helper_stack)) {
        stack_push(s, stack_pop(helper_stack));
    }
    stack_destroy(&helper_stack);
}

void push_sorted_stack(Stack *stack, int value) 
{
   int top;
   
   if (!stack_is_empty(stack)) {
      top = stack_top(stack);
      
      if (top > value) {
        stack_pop(stack);
        push_sorted_stack(stack, value);
        stack_push(stack, top);
        return;
      }
   }
   stack_push(stack, value);
}

void insert_sort(Stack *orig_stack)
{
    Stack *helper_stack = stack_create(1);
    Item elem = stack_pop(orig_stack);

    while(!stack_is_empty(orig_stack)) {
        if(elem <= stack_top(helper_stack)) {
            stack_push(helper_stack, elem);
            Item elem = stack_pop(orig_stack);
        } else {
            if(!stack_is_empty(helper_stack)) {
                stack_push(helper_stack, elem);
                return insert_sort(helper_stack);
            }
        }
    }

    while(!stack_is_empty(helper_stack)) {
        stack_push(orig_stack, stack_pop(helper_stack));
    }
    stack_destroy(&helper_stack);
}