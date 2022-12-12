#include <stdio.h>
#include <math.h>


double f(double x)
{
    return x * x * x - 5*x + 12;
}


double df(double x)
{
    return 3 * x * x - 5;
}


double wegstein(double a, double b, double eps)
{

    double x0 = a;
    double x1 = b;
    double xm;
    double slope;
    double ym;
    double x2;
    while (fabs(x1 - x0) > eps)
    {

        xm = 0.5 * (x0 + x1);
        slope = df(xm);
        ym = f(xm);

        if (ym > 0)
            x1 = xm;
        else
            x0 = xm;


        x2 = x1 - ym * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    }

 
    return 0.5 * (x0 + x1);
}

