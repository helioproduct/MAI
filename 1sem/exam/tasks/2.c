#include <stdio.h>
#include <stdbool.h>

// Проверка палиндрома числа
//  Сложность: O(log n)

bool is_palindrom(long long number)
{  
    long long saved_number, reversed_number;
    saved_number = number;
    reversed_number = 0;

    while (number > 0)
    {
        reversed_number = reversed_number * 10 + number % 10;
        number /= 10;
    }
    return saved_number == reversed_number;
}

int main(void)
{
    long long number;
    scanf("%lld", &number);
    printf(is_palindrom ? "YES" : "NO");
    return 0;
}