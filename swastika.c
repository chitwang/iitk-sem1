/*You are given a matrix with odd number of columns and rows. You have to print the sum of elements that appear in a swastika pattern.

swastika pattern attached in figure

Note: Swastika pattern involves middle row and middle column.


Input Format

first line two odd natural numbers n and m separated by space. Next n lines contain m integers separated by space.


It is guaranteed that n≥3 and m≥3.

For eg.

3 5

1 2 3 4 5

6 7 8 9 10

11 12 13 14 15

Output Format

A single integer: sum of elements that appear in a swastika pattern.

Sample Input

3 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15


Sample Output

104*/

// solution:

#include <stdio.h>

int main()
{
    int sum = 0;
    int e;
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d\n", &m);
    int rm = (n + 1) / 2;
    int cm = (m + 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &e);
            if ((i == rm) || (j == cm) || (i == 1 && j > cm) || (i == n && j < cm) || (j == 1 && i < rm) || (j == m && i > rm))
            {
                sum = sum + e;
            }
        }
    }
    printf("%d", sum);
    return 0;
}