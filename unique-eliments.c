/*[35 Points]

----------------------------------------------------------------------
Automated Grading Scheme:

Visible:  5  each for all visible test cases

Hidden:  5  each for all hidden test cases



Manually Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");
Penalty :
-20% each for using any library other than stdio.h, stdlib.h,
-20% for using any built-in function other than malloc
-50% for static allocation of matrix or array, example int mat[100][100] or similar declaration

----------------------------------------------------------------------
Read a square matrix of size ‘N’. Do the following task:
Print all unique elements in the matrix. If there are no unique elements, print No unique elements.


Input:


First line contain M size of matrix

The input will span across M line.

Each line will contain space separated  M integers.


Output:


A single line with unique (non-repetitive) elements in the matrix with space (Take care of space at the last)


Sample TestCase:


Input
4
5 1 2 1
4 10 3 5
2 1 4 4
1 2 0 7

Output:
10 3 0 7
Explanation:

Only elements 10,3,0 and 7 does not repeat in the matrix.*/

// solution:

#include <stdio.h>
#include <stdlib.h>
int spanner(int *arr, int n, int b)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (*(arr + i) == b)
            {
                flag = 1;
                break;
            }
        }
        return flag;
    }
}
int times(int **mat, int b, int n)
{
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(*(mat + i) + j) == b)
            {
                d++;
            }
        }
    }
    return d;
}
int main()
{
    int n;
    scanf("%d", &n);
    int **mat;
    mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        *(mat + i) = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int *arr = (int *)malloc((n * n) * sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (spanner(arr, count, *(*(mat + i) + j)) == 0)
            {
                *(arr + count) = mat[i][j];
                count++;
            }
        }
    }
    int *brr = (int *)malloc(count * sizeof(int));
    int index = 0;
    for (int p = 0; p < count; p++)
    {
        if (times(mat, *(arr + p), n) == 1)
        {
            *(brr + index) = *(arr + p);
            index++;
        }
    }
    if (index == 0)
    {
        printf("No unique elements.");
        return 0;
    }
    for (int i = 0; i < index; i++)
    {
        printf("%d", *(brr + i));
        if (i < index - 1)
        {
            printf(" ");
        }
    }
    return 0;
}