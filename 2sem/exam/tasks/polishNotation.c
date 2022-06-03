#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stack.h> // псевдокод

int main(void)
{
    char c, a, b;
    stack *s;

    stack_create(s);

    while ((c = getchar()) != EOF) 
    {
        if (c == '0' || c == '1') {
            stack_push(s, c - '0');
        }
        else if (c == '+') {
            a = stack_pop(s);
            b = stack_pop(s);

            if (a && b) {
                stack_push(s, a);
            }
            else {
                stack_push(s, a + b);
            }
        }
        else if (c == '*') {
            a = stack_pop(s);
            b = stack_pop(s);
            stack_push(a * b);
        }
    }

    pritnf(stack_top(s));

    return 0;
}