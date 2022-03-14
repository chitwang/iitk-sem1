/*Note: Usage of arrays is disallowed.

Given a list of n number of non-zero integers (n > 1), find and print the pair of integers such that their product is the maximum among all possible pairs in the list.

Input Format:
The first line denotes the integer n.
The second line contains n non-zero integers separated by spaces.

Output Format:
The pair of numbers in the input list with the maximum product possible separated by a space. The numbers should be printed in non-decreasing order.

Constraints:

In the list of numbers given, it is guaranteed that there is a unique pair with the maximum product.

The given n is greater than 1.

The given numbers are non-zero integers.

Example 1

Input:
4
312 26 312 1
Output:
312 312

Example 2
Input:
5
59 -49 14 123 -213
Output:
-213 -49 */

// solution:

#include <stdio.h>
int main()
{
    int n;
    int a;
    int b;
    int count = 1;
    int max1;
    int max2;
    int min1;
    int min2;
    scanf("%d", &n);
    if (n == 2)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        if (a > b)
        {
            printf("%d %d", b, a);
        }
        else
        {
            printf("%d %d", a, b);
        }
    }
    else
    {
        while (count <= n)
        {
            scanf("%d", &a);
            if (a >= max1)
            {
                max2 = max1;
                max1 = a;
            }
            else if (a > max2)
            {
                max2 = a;
            }
            if (a <= min1)
            {
                min2 = min1;
                min1 = a;
            }
            else if (a < min2)
            {
                min2 = a;
            }
            count++;
        }
        if ((min1 * min2) < (max1 * max2))
        {
            printf("%d %d\n", max2, max1);
        }
        else
        {
            printf("%d %d\n", min1, min2);
        }
    }
}
