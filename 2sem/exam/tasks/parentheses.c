#include <stdio.h>
#include <stdlib.h>
#include <stack.h> // псевдокод



int main(void)
{
    stack *a;
    char a[100];

    int i = 0;
    scanf("%s", a);

    while (a[i] != '\0')
    {
        if (a[i] == '(')
            push(a[i], s);
    
        if (a[i] == ')') {
            if (isEmpty(s) || stack_pop(s) != a[i]) {
                printf("false\n");
                return 0;
            }
        }
        i++;
    }

    printf(isEmpty(s) ? "true\n" : "false\n");

    return 0;
}