#include <stdio.h>
#include <stdbool.h>

// Сложность: O(n)
bool is_prime(long long number)
{   
    long long  i = 2;
    while (i * i <= number)
    {   
        if (number % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}

int main(void)
{
    int count = 0;
    long long x = 2;
    while (count < 500)
    {
        if (is_prime(x))
        {
            printf("%lld\n", x);
            count++;
        }
        x++;
    }
}