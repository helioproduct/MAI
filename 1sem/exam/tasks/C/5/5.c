#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Сложность: O(sqrt(n))
bool is_prime(long long number)
{   
    long long  i = 2;
    while (i * i <= number)
    {   
        if (number % i == 0)
            return false;
        i++;
    }
    return true;
}

// Сложность: O(n * sqrt(n))
int main(void)
{
    unsigned int start_time = clock();

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

    unsigned int end_time = clock();
    printf("TIME: %d", end_time - start_time);
    return 0;
}