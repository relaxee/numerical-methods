#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define TOL 1e-6  
#define MAX_ITER 1000  


double abs_error(double* x, double* x_old,int N)
{
    double error = 0.0;
    for (int i = 0; i < N; i++) {
        error += fabs(x[i] - x_old[i]);
    }
    return error;
}


double* jacobi(double** a, double* b, double* x,int N)
{
    double x_old[N];  
    int iter = 0;  


    for (int i = 0; i < N; i++) {
        x[i] = 0.0;
    }

    do {

        for (int i = 0; i < N; i++) {
            x_old[i] = x[i];
        }


        for (int i = 0; i < N; i++) {
            double sigma = 0.0;
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    sigma += a[i][j] * x_old[j];
                }
            }
            x[i] = (b[i] - sigma) / a[i][i];
        }

        iter++;
    } while (abs_error(x, x_old,N) > TOL && iter < MAX_ITER);

    return x;
}
