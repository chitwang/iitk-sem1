/*Given a matrix of size M * N. Find the transpose of matrix.


Constraint:


Array of pointer to store the matrix

Define a custom function to find the transpose

Pass the matrix as an argument to the function

Do not use global variable for storing array


Input:


The input will span across M+1 line.

First line will contain two space separated integer M (number of rows) and N (number of columns).

The next M line, each will contain N space separated integer(elements of each row).


Output:


The program should print:

The matrix after transpose.




Sample TestCase:


TestCase1:

Input
2 3
1 2 3
4 5 6
Output:
1 4
2 5
3 6*/

// solution:

#include <stdio.h>
#include <stdlib.h>
void transpose(int **mat, int n, int m)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}
int main()
{
    //  Insert your code here.
    int m;
    int n;
    scanf("%d %d", &m, &n);
    int **mat;
    mat = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    transpose(mat, n, m);
    return 0;
}