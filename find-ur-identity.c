/*In the first line of your input, you will be given two strictly positive integers n and m. In the next n lines, you will be given the n rows of an n x m matrix A, with each row on a separate line and two elements in a row separated by a single space. The matrix A will contain entries that are either 0 or 1.
In the first line of your output, print the size of the largest identity submatrix. In the next line, print the row index and column index of the top-left element of the largest identity submatrix in the format (rowIdx,colIdx). Note that there are no spaces in the output. In case of multiple identity submatrices of the same largest size, print the (rowIdx,colIdx) of the one with the largest row number. If two matrices of the largest size have the same largest row number print the one with larger column number.


If there is no identity submatrix, print 0 in the first line of your output and print (-1,-1) in the second line of your output.
Use zero indexing for row and column indexing.


Identity Matrix : A square matrix in which all the elements of the principal diagonal are ones and all other elements are zeros.
Submatrix : A smaller matrix inside a given matrix made by fixing the left top corner and the bottom right corner.


INPUT:

The input consists of n + 1 lines.The first line contains two integers n and m.The following n lines each contain a row of matrix A.


OUTPUT:

The output should contains two lines. The first line contains the size of largest submatrix and the next line contains (rowIdx,colIdx).


CONSTRAINTS:

1 <= n*m <= 100


Example Input


3 4
1 1 1 1
1 1 0 1
1 0 1 0


Example Output


2
(1,1)


Public Test Cases (7 marks)

Test Case	Output
3 4
1 1 1 1
1 1 0 1
1 0 1 0
2
(1,1)
Hidden Test Cases (7 +7 + 7 +7= 28 Points)*/

// solution:

#include <stdio.h>
int checkidentity(int n, int m, int mat[n][m], int size, int i, int j)
{
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (x == y)
            {
                if (mat[i + x][y + j] != 1)
                {
                    return 0;
                }
            }
            else
            {
                if (mat[i + x][y + j] != 0)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    //  Insert your code here.
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int mat[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    int maxsize = 0;
    int row = -1;
    int col = -1;
    int x = min(n, m);
    for (int s = 0; s < x; s++)
    {
        int i = 0;
        int j = 0;
        while (i + s < n)
        {
            if (j + s < m)
            {
                if (checkidentity(n, m, mat, s + 1, i, j) == 1)
                {
                    maxsize = s + 1;
                    row = i;
                    col = j;
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
    printf("%d\n(%d,%d)", maxsize, row, col);
    return 0;
}