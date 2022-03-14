/*Given a matrix of N X M that contains integers, find the submatrix with the largest sum.
Return the sum of the submatrix. Intuitively a submatrix is a smaller rectangular matrix chosen from the original matrix. For example, look at the image below :
submatrix


Constraint:


Array of pointer to store the matrix

Define a custom function to find the answer

Pass the pointer to the above function

Do not use global variable for storing array

There should not be any memory leak  in you program


Input:


The input will span across M+1 line.

First line will contain two space separated integer N (number of rows) and M (number of columns).

The next N line, each will contain M space separated integer(elements of each row).


Output:


The program should print:

The sum of the submatrix with the largest sum.




Sample TestCase:


TestCase1:

Input
2 3
1 2 3
4 5 6
Output:
21
Explanation:
since all the the elements are positive that is why the whole matrix is the answer.*/

// solution:

#include <stdio.h>
#include <stdlib.h>
int func(int **mat, int n, int m)
{
    int ans = 0;
    for (int sx = 0; sx < n; sx++)
    {
        for (int sy = 0; sy < m; sy++)
        {
            int i = 0;
            int j = 0;
            while (i < n - sx)
            {
                if (j + sy < m)
                {
                    int sum = 0;
                    for (int x = 0; x <= sx; x++)
                    {
                        for (int y = 0; y <= sy; y++)
                        {
                            sum += mat[i + x][j + y];
                        }
                    }
                    if (sum > ans)
                    {
                        ans = sum;
                    }
                }
                j++;
                if (j == m)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return ans;
}
int main()
{
    //  Insert your code here.
    int n, m;
    scanf("%d %d", &n, &m);
    int **mat;
    mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(m * sizeof(int));
    }
    for (int v = 0; v < n; v++)
    {
        for (int b = 0; b < m; b++)
        {
            scanf("%d", &mat[v][b]);
        }
    }
    printf("%d", func(mat, n, m));
    return 0;
}