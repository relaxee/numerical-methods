#include <stdio.h>
#include <math.h>
#include<stdlib.h>

double myFunction(double x) {
  return x * x;
}


double twoPointGauss(double a, double b, double (*f)(double)) {
  double x1 = -sqrt(1.0 / 3.0); //переделать, умножить на h и m
  double x2 = sqrt(1.0 / 3.0); //переделать, умножить на h и m, сделать для разных точек
  double w1 = 1.0;
  double w2 = 1.0;
  double x1_transformed = ((b - a) / 2.0) * x1 + (a + b) / 2.0; //сделать до j1..21 по формуле
  double x2_transformed = ((b - a) / 2.0) * x2 + (a + b) / 2.0;
  return ((b - a) / 2.0) * (w1 * f(x1_transformed) + w2 * f(x2_transformed)); // сделать суммой до m, сделать ввод h в функцию
}


