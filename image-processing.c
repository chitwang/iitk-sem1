/*Your are given n*n pixel grid of an image represented in the matrix form. You have to calculate the convulation of every pixel with a circular kernel of radius r i.e the convulation is the mean of the pixels falling in a circle. The circle is centered at the pixel.


Input Format

First line of the input contains the value of n i.e the size of the grid.
Next n lines contain the values of the grid.
Next line contains the value of r i.e the radius of the kernel.


Output Format

Print the convulation matrix.


input
3
1 1 2
2 1 1
1 2 1
1
output
1.333333 1.250000 1.333333
1.250000 1.400000 1.250000
1.666667 1.250000 1.333333*/

// solution:

#include <stdio.h>
int distance(int i1, int j1, int i2, int j2)
{
    return ((i1 - i2) * (i1 - i2) + (j1 - j2) * (j1 - j2));
}
int main()
{
    //  Insert your code here.
    int n;
    scanf("%d", &n);
    double mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &mat[i][j]);
        }
    }
    double r;
    scanf("%lf", &r);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double sum = 0.0;
            double count = 0.0;
            for (int a = 0; a < n; a++)
            {
                for (int b = 0; b < n; b++)
                {
                    if (distance(i, j, a, b) <= (r * r))
                    {
                        sum += mat[a][b];
                        count++;
                    }
                }
            }
            printf("%lf", sum / count);
            if (j < n - 1)
            {
                printf(" ");
            }
        }
        if (i < n - 1)
        {
            printf("\n");
        }
    }
    return 0;
}