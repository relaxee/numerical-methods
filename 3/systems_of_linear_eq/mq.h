#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void cholesky(int n, double** A, double** L)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            double s = 0;
            for (int k = 0; k < j; k++)
            {
                s += L[i][k] * L[j][k];
            }

            if (i == j)
            {
                L[i][j] = sqrt(A[i][i] - s);
            }
            else
            {
                L[i][j] = (1.0 / L[j][j] * (A[i][j] - s));
            }
        }
    }
}


void choleskySolve(int n, double** A, double* b, double* x)
{

    double** L = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
    {
        L[i] = malloc(n * sizeof(double));
    }


    cholesky(n, A, L);


    double* y = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }


    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += L[j][i] * x[j];
        }
        x[i] = (y[i] - sum) / L[i][i];
    }


    free(y);
    for (int i = 0; i < n; i++)
    {
        free(L[i]);
    }

}

