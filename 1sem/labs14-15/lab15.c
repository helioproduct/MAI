#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void print_matrix(int matrix[8][8], int size) 
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int size;
    int matrix[8][8];
    long long MAX = LLONG_MIN;
    
    scanf("%d", &size);

    long long sum_line[8];
    for (int i = 0; i < size; i++)
    {
        sum_line[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] > MAX)
            {
                MAX = matrix[i][j];
            }
        }
    }
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == MAX)
            {
                for (j = 0; j < size; j++)
                {
                    sum_line[j] += matrix[i][j];
                }
                continue;
            } 
            
        }
    }
    
    int line_to_change;

    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == MAX)
            {
                line_to_change = i;
            } 
        }
    }

    for (int i = 0; i < size; i++)
    {
        matrix[line_to_change][i] = sum_line[i];
    }

    printf("\n");
    print_matrix(matrix, size);

    return 0;
}