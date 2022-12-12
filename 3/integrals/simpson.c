#include <math.h>
#include <stdio.h>

double f(double x) {
  return x * x;
}

double simpson(double a, double b, int n)
{

    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
    {
        result += 4 * f(a + i * h);
    }


    for (int i = 2; i < n - 1; i += 2)
    {
        result += 2 * f(a + i * h);
    }

    return result * h / 3;
}

