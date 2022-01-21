#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int a[] = {2};
    int k = 1;
    int n = a[0] + 1;
    while (k <= 500)
    {
        bool is_prime = true;
        for (int i = 0; i < k; i++)
        {
            if (n % a[i] == 0)
            {
                is_prime = false;
                break;
            }
        }
    }
    return 0;
}