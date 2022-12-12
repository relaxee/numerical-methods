#include <stdio.h>
#include <math.h>


double f(double x)
{
    return x * x * x - x - 1;
}


double secant(double a, double b, double eps)
{

    double x0 = a;
    double x1 = b;
    double y0 = f(x0);
    double y1 = f(x1);
    double x2;

    while (fabs(x1 - x0) > eps)
    {

        y0 = f(x0);
        y1 = f(x1);

        x2 = x1 - y1 * (x1 - x0) / (y1 - y0);
        x0 = x1;
        x1 = x2;
    }

    return 0.5 * (x0 + x1);
}

