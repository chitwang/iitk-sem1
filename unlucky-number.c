/*You are given an n*m matrix with n rows and m columns. You are supposed to calculate the sums of each of the rows of the matrix. Then you are supposed to take summation over these sums starting from the first row and stop whenever you reach a row whose sum is 7 as it is considered bad luck. The sums for all following rows, including the row whose sum is 7 will not be added to the final answer.


Input Format

First line contains 2 space separated integers n and m which denote the size of the n*m matrix. Then next n lines contain m space separated integers.


Output Format

A single integer: The required summation over the valid rows


Sample Input

3 3
1 2 3
2 3 2
4 2 4
Sample Output

6
Explanation

Sum of first row = 6
Sum of second row = 7
Since the sum of the second row is 7, we need only consider the sum over rows before itself in our final answer*/

// solution:

#include <stdio.h>

int main()
{
    int n;
    int m;
    int sum = 0;
    int csum = 0; // csum stands for cumulative sum
    int e;
    scanf("%d", &n);
    scanf("%d\n", &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &e);
            sum = sum + e;
        }
        if (sum == 7)
        {
            break;
        }
        csum = csum + sum;
        sum = 0;
    }
    printf("%d", csum);
    return 0;
}