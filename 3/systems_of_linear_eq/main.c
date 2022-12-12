#include <stdio.h>
#include <stdlib.h>
#include"mq.h"
#include"mz.h"
#include"mg_mp.h"
#include"mi.h"

double** tridiagonal_matrix(double q)
{
    int n = 5;
    int count = 0;
    double **A = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
    {
        A[i] = malloc(n * sizeof(double));
    }
    double a[] = {q,1,0,0,0,1,-2,1,0,0,0,1,-2,1,0,0,0,1,-2,1,0,0,0,1,q};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n;j++)
        {
            A[i][j] = a[count];
            count++;
        }
    }
    return A;
    

}

double* solution_vector(double d)
{
    double *b = malloc(5 * sizeof(double));
    for (int i = 0; i < 5; i++)
    {
        if(i == 0 || i == 4)
        {
            b[i] = 0;
        }
        else
        {
            b[i] = d;    
        }
    }
    return b;
}

void print_matrix(int rows, int cols, double **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print(int rows,double *a)
{
    for(int i = 0; i < rows;i++)
    {
        printf("%lf\n",a[i]);
    }
}

void to_csv(const char* str,double*data)
{
    FILE *file = fopen("output.csv", "a"); 
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }


    fprintf(file, "%s,%lf,%lf,%lf,%lf,%lf\n",str,data[0], data[1], data[2], data[3], data[4]);
    fclose(file); 
}


void mg(double q,double d, const char *label)
{
    int n = 5;
    double **A = tridiagonal_matrix(q);
    double *b = solution_vector(d);
    gaussian_elimination(A, b, n);
    double *x = malloc(n * sizeof(double));
    back_substitution(A, b, x, n);
    to_csv(label,x);
    //free
}

void mi(double q,double d, const char *label)
{
    int n = 5;
    double **A = tridiagonal_matrix(q);
    print_matrix(5,5,A);
    double *b = solution_vector(d);
    print(n,b);
    double *x = malloc(n * sizeof(double));
    thomas_algorithm(A,b,x,n);
    to_csv(label,x);
    //free

}



int main()
{

    const char *label = "MyArray";
    char *label_string = "MI1";
    mi(-3.17,1,label_string);
}

//Доделать функции для заданий + ввод значений с csv file (main)
//Протестить для всех значений
//сделать невязку + релаксацию
//почистить грамотно память
