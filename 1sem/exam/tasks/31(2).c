#include <stdio.h>
#include <math.h>

double min(double a, double b)
{
    return a < b ? a : b;
}

double max(double a, double b)
{
    return a > b ? a : b;
}

int main(void)
{
    int width = 80;
    double start = 0;
    double end = 2 * asin(-1);
    double step = 0.1;

    double f_min = sin(start);
    double f_max = sin(start);

    for (double i = start + step; i < end; i += step)
    {
        f_min = min(f_min, sin(i));
        f_max = max(f_max, sin(i));
    }

    printf("%lf %lf", f_min, f_max);

    for (double i = start; i < end; i += step)
    {
        // Кол-во знаков, которые надо распечатать
        int n = (sin(i) - f_min) / (f_max - f_min) * width;
        for (int j = 0; j < n; j++)
        {
            printf("*");
        }  
        printf("\n");
    }

    return 0;
}