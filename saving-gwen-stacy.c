/*Doc Ock tried to drop Gwen Stacy down a square hole but Spider-Man created a 2D array-like web below her to save her. Now he is sitting on the edge of the web and wants to go to the centre. Given a 2-D array, he has to reach the centre of the matrix by travelling around the matrix in a spiral pattern. Help him by printing the spiral pattern of his path.


Given n and a 2-D array A of size n x n, print the elements of the array in a spiral pattern starting from the element A[n-1][n-1] in the anti-clockwise direction till the last middle element of the array. See example for more clarification.


Input Format


The first line contains the integer n.

The next n lines contain n integers each, representing the n rows of the matrix.


Output Format

Print n^2 space-separated integers in the order given above.


Note


1 <= n <= 100

You should declare only one 2-D array for scanning the input. you should not use any other 1-D or 2-D array anywhere in your solution code.


Example/Visible Case 1

Input:


3
1 2 3
4 5 6
7 8 9
Output:


9 6 3 2 1 4 7 8 5*/

// solution:

#include <stdio.h>
void spiral(int n, int mat[n][n], int i, int j, int p, int q)
{
    if (i >= p || j >= q)
    {
        return;
    }
    for (int x = p - 1; x >= i; x--)
    {
        printf("%d ", mat[x][q - 1]);
    }
    for (int x = q - 2; x >= j; x--)
    {
        printf("%d ", mat[i][x]);
    }
    if (j != q - 1)
    {
        for (int x = i + 1; x < p; x++)
        {
            printf("%d ", mat[x][j]);
        }
    }
    if (i != p - 1)
    {
        for (int x = j + 1; x < q - 1; x++)
        {
            printf("%d ", mat[p - 1][x]);
        }
    }
    spiral(n, mat, i + 1, j + 1, p - 1, q - 1);
}
int main()
{
    //  Insert your code here.
    int n;
    scanf("%d", &n);
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    spiral(n, mat, 0, 0, n, n);
    return 0;
}