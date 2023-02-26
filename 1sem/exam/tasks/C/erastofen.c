#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

/*
Кол-во простых чисел на отрезке [1, n]
растет с увеличением n как n / ln(n)

Сложность: O(n*log(log n))
*/
 
int main(void)
{
    int n = 2;
    while (n / log(n) < 500)
    {
        n++;
    }
    const int N = n;
        
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
    return 0;
}
