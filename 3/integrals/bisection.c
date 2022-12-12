#include <stdio.h>
#include <math.h>


double f(double x)
{
    return log(x)- 5 *sin(x) * sin(x);
}


double bisection(double a, double b, double eps)
{

    double x0 = a;
    double x1 = b;

    while (fabs(x1 - x0) > eps)
    {

        double x2 = 0.5 * (x0 + x1);


        if (f(x2) * f(x0) < 0)
        {
            x1 = x2;
        }
        else
        {
            x0 = x2;
        }
    }

    return 0.5 * (x0 + x1);
}

