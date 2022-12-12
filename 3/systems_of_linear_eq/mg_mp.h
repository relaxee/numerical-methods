#include <stdio.h>
#include <stdlib.h>


void gaussian_elimination(double **A, double *b, int n)
{
    for (int i = 0; i < 2; i++)
    {
        double pivot = A[i + 1][i] / A[i][i];
        for (int j = 0; j < n; j++)
        {
            A[i + 1][j] -= pivot * A[i][j];
        }
        b[i + 1] -= pivot * b[i];
    }
}


void back_substitution(double **A, double *b, double *x, int n)
{
    x[n - 1] = b[n - 1] / A[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        x[i] = (b[i] - A[i][i + 1] * x[i + 1]) / A[i][i + 1];
    }
}

void thomas_algorithm(double **A, double *b, double *x, int n)
{

    double *a = malloc((n - 1) * sizeof(double));
    double *c = malloc((n - 1) * sizeof(double));
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = A[i][i + 1];
        c[i] = A[i + 1][i];
    }


    double *d = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        d[i] = A[i][i];
    }

    for (int i = 1; i < n; i++)
    {
        double pivot = c[i - 1] / d[i - 1];
        d[i] -= pivot * a[i - 1];
        b[i] -= pivot * b[i - 1];
    }

    x[n - 1] = b[n - 1] / d[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        x[i] = (b[i] - a[i] * x[i + 1]) / d[i];
    }

    free(a);
    free(c);
    free(d);
}
