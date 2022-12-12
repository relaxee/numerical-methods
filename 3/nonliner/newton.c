#include <stdio.h>
#include <math.h>


double f(double x)
{
    return x * x * x - x - 1;
}


double df(double x)
{
    return 3 * x * x - 1;
}


double newton(double a, double b, double eps)
{

    double x0 = a;
    double x1 = b;
    double xm;
    double slope;
    double ym;


    while (fabs(x1 - x0) > eps)
    {

        xm = 0.5 * (x0 + x1);
        slope = df(xm);
        ym = f(xm);

        if (ym > 0)
            x1 = xm;
        else
            x0 = xm;
    }


    return -f(0.5 * (x0 + x1)) / df(0.5 * (x0 + x1));
}

