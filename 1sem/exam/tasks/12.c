#include <stdio.h>

int main(void)
{  
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++)
    {
        double a;
        scanf("%lf", &a);
        printf("%ld", a * i);
    }

    return 0;
}