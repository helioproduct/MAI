#include <stdio.h>
#include <math.h>

double get_eps()
{
    double eps = 1;
    while (1.0f + eps / 2.0f > 1.0f)
    {
        eps /= 2.0f;
    }
    return eps;
}

double get_taylor_term(double x, unsigned int n)
{
    return pow(-1, n) * pow(x, 2 * n + 1) / (2 * n + 1);
}

double function(double x)
{
    return atan(x);
}

void calculate(
    double a, 
    double b,
    int n,
    double (*function)(double),
    double (*get_taylor_term)(double, unsigned int)
    )
{  
    if (n <= 0)
    {
        printf("n must be > 0");
        return;
    }
    
    printf("+--------+--------------------+----------+-----+\n");
    printf("|    x   |  Taylor series sum | arctg(x) |  n  |\n");
    printf("+--------+--------------------+----------+-----+\n");

    double x = a;
    double step = (b - a) / n;
    double eps = get_eps();
    double fun_value, taylor_series_sum;
    
    for (float x = a; x <= b; x += step)
    {  
        fun_value = function(x);
        taylor_series_sum = get_taylor_term(x, 0);

        int i = 1;
        while (fabs(fun_value - taylor_series_sum) > eps * 10e8f && i < 100)
        {
            taylor_series_sum += get_taylor_term(x, i++);
        }

        printf("|%8.2f|%20.5f|%10.5f|%5d|\n", x, taylor_series_sum, fun_value, i);
    }
    printf("+--------+--------------------+----------+-----+\n");
}

int main()
{  
    int n;
    scanf("%d", &n);
    calculate(0.1f, 0.6f, n, function, get_taylor_term);
}