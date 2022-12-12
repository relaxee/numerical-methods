#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000 
#define TOL 1e-6 

double f(double x) {
    return x * x - 4;
}


double df(double x) {
    return 2 * x;
}

//сделать нормально + для интервала
void simple_iteration() {
    double x0 = 1.0;
    double x = x0; 
    int iter = 0; 

    while (iter < MAX_ITER && fabs(f(x)) > TOL) {
        x = x - f(x) / df(x);  
        iter++; 
    }

    if (iter < MAX_ITER) {
        printf(" x = %.4f\n", x);
    } else {
        printf("Failed");
    }

    return 0;
}
