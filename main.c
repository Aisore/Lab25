#include <stdlib>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "stack.c"
#include "stack.h"

int main(int argc, char *argv[])
{
    char input[8];
    Stack *stack = stack_create(stack_size);
    Item num = 0;

    printf("\nTo get help type 'help'\n\n");
    for (;;) {
        scanf("%7s", input);
        if (!strcmp(s, "insert") || !strcmp(s, "ins")) {
            if(stack == NULL) {
                stack = stack_create(stack_size);
            }
            while (scanf("%d", &num)) {
                stack_push(stack, num);
            }
        } else if (!strcmp(s, "quit") || !strcmp(s, "exit") || !strcmp(s, "q")) {
            if(stack == NULL) {
                break;
            }
            stack_destroy(&stack);
            break;
        } else if (!strcmp(s, "run") || !strcmp(s, "r")) {
            if(stack == NULL) {
                printf("Stack does not exist\n");
            } else if (stack_is_empty(stack)) {
                printf("Stack is empty\n");
            } else {
                //sort(stack);
            }
        } else if (!strcmp(s, "print") || !strcmp(s, "p")) {
            if(stack == NULL) {
                printf("Stack does not exist\n");
            } else if (stack_is_empty(stack)) {
                printf("Stack is empty\n");
            } else {
                stack_print(stack);
            }
        } else if (!strcmp(s, "destroy") || !strcmp(s, "des")) {
            stack_destroy(&stack);
        } else if (!strcmp(s, "help") || !strcmp(s, "h")) {
            printf("\n'insert' or 'ins' - insert new elements.\n");
            printf("'print' or 'p' - print the stack.\n");
            printf("'run' or 'r' - sort elements \n");
            printf("'destroy' or 'des'- remove stack\n");
            printf("'quit', 'q' or 'exit' close the program.\n");
        } else {
            printf("\n This command does not exist, type 'help' or 'h'. \n");
        }
    }

    return 0;
}