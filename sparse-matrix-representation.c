/*You are given an N x N binary matrix called C, i.e. all the elements in the matrix are either 0 or 1. It's a sparse matrix, meaning that most of the elements are 0. You have to convert it to it's sparse representation, which is defined as follows :


Your job is to create a 2-Dimensional dynamic array D and populate it using  C. Entries in the D array are as follows:



D[i] is a dynamically allocated array of size k+1 if the ith array has exactly k elements as non zero.
D[i][0], D[i][1], ...,D[i][k-1] entries store the column number of the non zero elements in the ith row in sorted order. D[i][k] will be -1 to indicate the termination of the columns for the ith row.


You do not need to print any output or scan any input here. You just need to implement the function generate_sparse_representation, in the following template, do not change any other part of the code.The check_ans function, will check whether the representation created by you is correct or not. The output will be CORRECT or INCORRECT.




Example D:
  Input:


  4
  0 1 1 0
  1 0 0 0
  1 0 1 0
  0 0 0 0
  D matrix:


  1 2 -1
  0 -1
  0 2 -1
  -1

Testcase1:
Input:
3
0 1 0
0 0 1
1 0 0
Output:
CORRECT*/

// solution:

#include <stdio.h>
#include <stdlib.h>

int **generate_sparse_representation(int **C, int n)
{
    // fill this function, do not change anything else
    // C is a 2D matrix of size n*n
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            if (C[i][j] != 0)
            {
                k++;
            }
        }
        mat[i] = (int *)malloc((k + 1) * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        int g = 0;
        for (int j = 0; j < n; j++)
        {
            if (C[i][j] != 0)
            {
                mat[i][g] = j;
                g++;
            }
        }
        mat[i][g] = -1;
    }
    return mat;
}

int check_ans(int **C, int **D, int n)
{
    for (int i = 0; i < n; i++)
    {
        int d_index = 0;
        for (int j = 0; j < n; j++)
        {
            if (C[i][j] == 1)
            {
                if (D[i][d_index] == j)
                {
                    d_index++;
                    continue;
                }
                else
                {
                    return 0;
                }
            }
        }

        if (D[i][d_index] != -1)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int **C, **D;
    int n;
    scanf("%d", &n);

    // allocate space for and scan the c matrix
    C = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        C[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &C[i][j]);
        }
    }

    D = generate_sparse_representation(C, n);

    if (check_ans(C, D, n))
    {
        printf("CORRECT");
    }
    else
    {
        printf("INCORRECT");
    }
    return 0;
}