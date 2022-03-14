/*You are given a square matrix with n rows and n columns. Your task is to calculate the absolute difference between the sum of square of trace elements of the matrix and the sum of square of anti-trace elements of the matrix.

Input Format

First line contains a single integer n denoting the number of rows and columns of the matrix. Next n lines contain n integers separated by space.

Output Format

A single integer: absolute difference of sum of square of trace elements and sum of the square of anti-trace elements.


Sample Input

3

1 2 3

4 5 6

7 8 9

Sample Output

24

Explanation:

1*1+ 5*5 + 9*9 - 3*3 - 5*5 - 7*7 = 24*/

// solution:

#include <stdio.h>

int main()
{
    int n;
    int e;
    int trace = 0;
    int antitrace = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &e);
            if (i == j)
            {
                trace = trace + (e * e);
            }
            if (j == n + 1 - i)
            {
                antitrace = antitrace + (e * e);
            }
        }
    }
    if (antitrace >= trace)
    {
        printf("%d", antitrace - trace);
    }
    else
    {
        printf("%d", trace - antitrace);
    }
    return 0;
}