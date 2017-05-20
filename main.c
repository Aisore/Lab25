#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "stack.c"
#include "stack.h"
#include "stack2.c"

int main(void)
{
    char input[8];
    Stack *stack = stack_create();
    Item num = 0;

    printf("\nTo get help type 'help'\n\n");
    for (;;) {
        scanf("%7s", input);
        if (!strcmp(input, "insert") || !strcmp(input, "ins")) {
            if(stack == NULL) {
                stack = stack_create();
            }
            while (scanf("%d", &num)) {
                stack_push(stack, num);
            }
        } else if (!strcmp(input, "quit") || !strcmp(input, "exit") || !strcmp(input, "q")) {
            if(stack == NULL) {
                break;
            }
            stack_destroy(&stack);
            break;
        } else if (!strcmp(input, "sort") || !strcmp(input, "s")) {
            if(stack == NULL) {
                printf("Stack does not exist\n");
            } else if (stack_is_empty(stack)) {
                printf("Stack is empty\n");
            } else {
                insert_sort(stack);
            }
        } else if (!strcmp(input, "print") || !strcmp(input, "p")) {
            if(stack == NULL) {
                printf("Stack does not exist\n");
            } else if (stack_is_empty(stack)) {
                printf("Stack is empty\n");
            } else {
                stack_print(stack);
            }
        } else if (!strcmp(input, "destroy") || !strcmp(input, "des")) {
            stack_destroy(&stack);
        } else if (!strcmp(input, "inssort")) {
            while (scanf("%d", &num)) {
                push_sorted_stack(stack, num);
            }
        } else if (!strcmp(input, "help") || !strcmp(input, "h")) {
            printf("\n'insert' or 'ins' - insert new elements.\n");
            printf("'print' or 'p' - print the stack.\n");
            printf("'sort' or 's' - sort elements \n");
            printf("'inssort' - insert new elements in sorted stack\n");
            printf("'destroy' or 'des'- remove stack\n");
            printf("'quit', 'q' or 'exit' close the program.\n");
        } else {
            printf("\n This command does not exist, type 'help' or 'h'. \n");
        }
    }
    return 0;
}