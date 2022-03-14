/*[70 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  5  each for all visible test cases

Hidden:  10  each for all hidden test cases



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% each for using any library other than stdio.h, stdlib.h, limits.h
-20% for using any built-in function
-50% for using single pointer or 1 dimensional array
-50% for static allocation of matrix, example int mat[100][100] or similar declaration

----------------------------------------------------------------------
Problem Description

Given a square matrix M of size N. Calculate the sum of all neighboring elements of each diagonal element (up, down, left, right, and 4 diagonal elements -- a total of 8 elements). The neighboring elements for diagonal elements M[0][0] and M[N-1][N-1] is 3.
Print these values corresponding to each diagonal element. Also print the index of that diagonal element whose corresponding sum is highest.(Row and Column index are same for a diagonal element in square matrix)


Constraint:


It is mandatory to use array of pointers or double pointer to store the matrix

Header file: stdlib.h is allowed for dynamic memory allocation

The elements of matrix can be negative integer as well

Indexing starts from zero

N is always greater than equal to 2

Use of single pointer or one dimensional array to store matrix element will result in penalty of 50% marks.

Penalty of 50% marks if using static allocation of matrix e.g. int mat[50][50] or int mat[100][100]




Input:



First line in each test case will contain the size of square matrix N.



The remaining N lines contains the elements of each row in the matrix.


Output:


The output will contains the N+1 lines.

First N line will be the sum of all neighboring elements for each diagonal element in the specified format, i.e., diagonal element followed by sum of neighboring elements.

The last line will contain index of the diagonal element with the highest sum of the neighboring elements.

In case two diagonal elements having same sum of neighboring elements, print the one with smaller index.


Sample TestCase

  Input


  3
  8 2 3
  2 3 4
  4 5 6
  Output:


  8: 7
  3: 34
  6: 12
  index: 1
  Explanation:
 The first N lines print sum of all neighboring element for each diagonal element. The sum of neighboring elements is maximum for M[1][1] i.e., diagonal element 3 hence index will be 1. */

// solution:

#include <stdio.h>
#include <stdlib.h>
int getval(int **mat, int n, int i, int j)
{
    if (i >= n || j >= n || i < 0 || j < 0)
    {
        return 0;
    }
    else
    {
        return *(*(mat + i) + j);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int **mat;
    mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", (*(mat + i) + j));
        }
    }
    int index;
    int max = -999999;
    for (int i = 0; i < n; i++)
    {
        int sum;
        sum = getval(mat, n, i - 1, i) + getval(mat, n, i + 1, i) + getval(mat, n, i, i + 1) + getval(mat, n, i, i - 1) + getval(mat, n, i - 1, i + 1) + getval(mat, n, i + 1, i + 1) + getval(mat, n, i + 1, i - 1) + getval(mat, n, i - 1, i - 1);
        printf("%d: %d\n", *(*(mat + i) + i), sum);
        if (sum > max)
        {
            index = i;
            max = sum;
        }
    }
    for (int i = 0; i < n; i++)
    {
        free(mat[i]);
    }
    free(mat);
    printf("index: %d", index);
    return 0;
}