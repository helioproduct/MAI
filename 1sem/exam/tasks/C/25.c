#include <stdio.h>
#include <stdlib.h>

// Сложность: O(n*m)
int main(void)
{
    // Степени многочленов
    int p1, p2; 
    scanf("%d", &p1);
    //Коэффициенты многочлена (1)
    int *k1 = (int*) malloc(sizeof(int) * (p1 + 1));

    // Ввод коэффициентов многочлена, начиная с p1
    for (int i = p1; i >= 0; i--)
    {
        scanf("%d", &k1[i]);
    }

    scanf("%d", &p2);
    //Коэффициенты многочлена (2)
    int *k2 = (int*) malloc(sizeof(int) * (p2 + 1));
    // Ввод коэффициентов многочлена, начиная с p2
    for (int i = p2; i >= 0; i--)
    {
        scanf("%d", &k2[i]);
    }

    // Многочлен (3) = (1) * (2)
    int *k3 = (int*) malloc(sizeof(int) * (p1 + p2 + 1));
    for (int i = p1; i >= 0; i--)
    {
        for (int j = p2; j >= 0; j--)
        {
            k3[i + j] += k1[i] * k2[j];
        }
    }    

    for (int i = p1 + p2; i >= 0; i--)
    {
        printf("%d ", k3[i]);
    }
        
    return 0;
}