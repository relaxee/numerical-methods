#include <stdio.h>
#include <math.h>

double f(double x) {
  return x*x;
}

double trapezoid(double a, double b, int n) {
  double h = (b - a) / n; 
  double s = 0.5 * (f(a) + f(b));


  for (int i = 1; i < n; i++) {
    double x = a + h * i;
    s = s + f(x);
  }

  return h * s;
}

