/*Given a non-negative integer n, find and print the sum of the digits of n.


Example 1

Input:
5239


Output:
19


Example 2

Input:
21301
Output:
7  */

// solution:

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int rem;
    int sum = 0;
    while (n != 0)
    {
        rem = n % 10;
        n = n / 10;
        sum = sum + rem;
    }
    printf("%d", sum);
    return 0;
}