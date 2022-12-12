#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 10000 
#define TOLERANCE 0.0001     


int converged(int n, double* x) {
    int i;
    double x_old;

    x_old = x[0];
    for (i = 1; i < n; i++) {
        if (fabs(x[i] - x_old) / fabs(x_old) > TOLERANCE) {
            return 0; 
        }
    }

    return 1; 
}


double* mz(int n, double** A, double* b, double* x) {
    int i, j;
    double sum, x_old;


    for (int k = 0; k < MAX_ITERATIONS; k++) {
        if (converged(n, x)) break;

        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }

            x_old = x[i];
            x[i] = (b[i] - sum) / A[i][i];

            if (fabs(x[i] - x_old) < TOLERANCE) {
                break;
            }
        }
    }

    return x;
}
