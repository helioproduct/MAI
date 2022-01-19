#include <stdio.h>

/*
    q2   Начальное состояние
    q2   Конечное состояние
    v    Действие
    q12  Промежуточное состояние

    В пятерках:  (q1, a, b, v, q2)
    В четверках: (q1, a, v, q2)

    Конвертация:
    (q1, a, b, v, q1) == (q1, a, v, q12); (q12, a, v, q2)
*/

int main(void)
{
    int n;  // Кол-во команд
    scanf("%d", &n);
    /*
        Команда = строка из 9 символов
        012345678
        1,a,b,>,2
    */
    char str[9];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &str);
        printf("%c, %c, %c, %c, z%c%c", str[0], str[2], str[3], str[4], str[0], str[8]);
        printf("z%c%c, %c, %c, %c", str[0], str[8], str[4], str[6], str[8]);
    }   

}