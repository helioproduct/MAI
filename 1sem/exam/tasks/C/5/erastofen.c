#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define N 3571

// Сложность: O(n*log(log n))
int main(void)
{
    unsigned int start_time = clock();

    bool prime[N + 1]; 
    for (int i = 0; i <= N; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;

    for (int i = 2; i <= N; i++)
    {
        if (prime[i] && i*i*1ll <= N) 
                for(int j = i*i; j <= N; j += i)
                    prime[j] = false;
    }

    unsigned int end_time = clock();

    int count = 0, x = 2;
    while (count < 500 && x <= N)
    {
        if (prime[x])
        {
            printf("%d %d\n", count + 1, x);
            count++;
        }
        x++;
    }

    printf("TIME: %d", end_time - start_time);
    return 0;
}
