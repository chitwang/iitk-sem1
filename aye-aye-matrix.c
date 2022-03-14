/*You are given an n*m matrix with n rows and m columns. The rows and columns are 0-indexed [top left cell is referred to in this question as (0,0)]

Pirate Captain Black-Mat gives you, his most trusted underling, 2 positive integers k and r. He asks you to make a list of all the special elements in the matrix in the row-wise traversal order.

A special element is an element which is in the cell (i,j) of the matrix such that (i+j)%k = r.

By row-wise traversal, we mean that we first travel along all cells of first row (row number 0), then along all cells of second row (row number 1), and so on.. Also, for each row, we start travelling from the first column (columns number 0) and move right.

Once you have made the list of all special elements, he wants you to find their interleaving sum.

For the list {1, 2, 5, 3, -1, 3, 4, 5}, we have the interleaving sum as 1 - 2 + 5 - 3 + (-1) - 3 + 4 - 5 = -4.


Input Format

The first line has 2 positive integers n and m, denoting the number of rows and columns respectively.

The second line has 2 non-negative integers k and r (r < k, k > 0).

The next n lines each have m space separated integers.

Output Format

A single integer, denoting the interleaved sum

Sample Input

5 6
3 1
3 1 2 4 -4 54
-44 23 1 2 33 0
-10 2 32 2 7 666
98 11 -76 21 4 -1
77 -77 101 -65 -6 -2
Sample Output

-526
Explanation

For k = 3, r = 1, we have the list of special elements in row-wise traversal as : {1, -4, -44, 2, 32, 666, 11, 4, 77, -65}
So, the interleaving sum is : 1 - (-4) + (-44) - 2 + 32 - 666 + 11 - 4 + 77 - (-65) = -526*/

/// solution:

#include <stdio.h>

int main()
{
    int n;
    int m;
    int k;
    int r;
    int index = 1;
    int isum = 0;
    int e;
    scanf("%d", &n);
    scanf("%d\n", &m);
    scanf("%d", &k);
    scanf("%d\n", &r);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &e);
            if ((i + j) % k == r)
            {
                if (index % 2 == 1)
                {
                    isum = isum + e;
                }
                else if (index % 2 == 0)
                {
                    isum = isum -= e;
                }
                index++;
            }
        }
    }
    printf("%d", isum);
    return 0;
}