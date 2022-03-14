/*You are given a square matrix. Compute the determinant of the matrix.


Input

The first line contains a single positive integer n
 Each of the next n lines contains n integers, each denoting the elements of the matrix


Output

A single integer, which is the determinant of the matrix


Constraints

n < 5


Sample Input

3
1 2 3
4 5 6
7 8 8

Sample Output

3

Sample Explanation

The determinant is 1×(5×8−6×8)−2×(4×8−6×7)+3×(4×8−5×7)=−8+20−9=3.*/

// solution;

#include <stdio.h>
#include <stdlib.h>
int deter(int n, int mat[n][n])
{
    if (n == 1)
    {
        return mat[0][0];
    }
    int det = 0;
    int sign = 1;
    for (int j = 0; j < n; j++)
    {
        int arr[n - 1][n - 1];
        int x = 0;
        int y = 0;
        for (int a = 1; a < n; a++)
        {
            for (int b = 0; b < n; b++)
            {
                if (b == j)
                {
                    continue;
                }
                arr[x][y] = mat[a][b];
                y++;
                if (y == n - 1)
                {
                    y = 0;
                    x++;
                }
            }
        }
        /*for(int g=0;g<n-1;g++)
        {
            for(int h=0;h<n-1;h++)
            {
                printf("%d " , arr[g][h]);
            }
            printf("\n");
        }
        printf("%d\n" , deter(n-1,arr)*mat[0][j]);*/
        det = det + sign * deter(n - 1, arr) * mat[0][j];
        sign = sign * (-1);
    }
    return det;
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
    printf("%d", deter(n, mat));
    return 0;
}