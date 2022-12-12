#include <stdio.h>
#include <math.h>


double f(double x) {
  return x*x;
}


double midpoint(double a, double b, int n) {
  double h = (b - a) / n; 
  double s = f(a + h / 2);


  for (int i = 1; i < n; i++) {
    double x = a + h * i;
    s = s + f(x + h / 2);
  }

  return h * s;
}

