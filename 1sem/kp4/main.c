#include <stdio.h>
#include "math.h"

double get_eps()
{
    double eps = 1;
    while (1.0f + eps / 2.0f > 1.0f)
    {
        eps /= 2.0f;
    }
    return eps;
}

double dichotomy_method(double a, double b, double (*fn)(double))
{
    double eps = get_eps();
    while (b - a > eps * 10e3)
    {
        double c = (a + b) / 2;
        if (fn(a) * fn(c) > 0)
            a = c;
        else
            b = c;
    }
    return (a + b) / 2;
}

double iteration_method(double a, double b, double (*fn)(double))
{
    double eps = get_eps();
    double x0 = (a + b) / 2;
    double x1 = b;
    while (fabs(x1 - x0) > eps * 10e3)
    {
        x0 = x1;
        x1 = fn(x0);
    }
    return x1;
}

double Newton_method(double a, double b, double (*fn)(double), double (*fn_derivative)(double))
{
    double eps = get_eps();
    double x0 = (a + b) / 2;
    double x1 = b;
    while (fabs(x1 - x0) > eps * 10e3)
    {
        x0 = x1;
        x1 -= fn(x0) / fn_derivative(x0);
    }
    return x1;
}

// Вариант 27
double fn1(double x)
{
    return sin(log(x)) - cos(log(x)) + 2*log(x);
}

double fn2(double x)
{
    return sin(sqrt(1 - 0.4 * x * x));
}

double fn3(double x)
{ 
    return 2*x*sin(x) - cos(x);
}

double fn3_derivative(double x)
{
    return 3*sin(x) + 2*x*cos(x);
}

int main()
{
    // Вариант 27
    double x = dichotomy_method(1, 3, fn1);
    printf("Dichotomy-method: %.4f\n", x);

    // Вариант 25
    x = iteration_method(0, 1, fn2);
    printf("Iteration-method: %.4f\n", x);

    // Вариант 10
    x = Newton_method(0.4, 1, fn3, fn3_derivative);
    printf("Newton-method: %.4f\n", x);
}