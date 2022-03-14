/*Your genius friend Kolmogorov always makes you feel inferior. This time you have a challenge for him. You give him a positive integer n, and ask him to find the number of different ways there are to form the given number n as a sum of positive integers in non-decreasing order. Now to pose this challenge to him, you need to solve it yourself :)


Input Format

A single positive integer n


Output Format

A single integer, denoting the number of ways


Sample Input

3
Sample Output

3
Explanation

There are 3 ways to express 3 in non-decreasing order


1 + 1 + 1
1 + 2
3
Note that 2 + 1 is invalid, since it is not non-decreasing.*/

// solution:

#include <stdio.h>
void recursion(int in, int s, int *count, int istart)
{
    if (in == s)
    {
        *count = *count + 1;
        return;
    }
    if (in > s)
    {
        return;
    }
    for (int i = istart; i <= s; i++)
    {
        istart = i;
        recursion(in + i, s, count, istart);
    }
    return;
}
int main()
{
    int s;
    scanf("%d", &s);
    int count = 0;
    recursion(0, s, &count, 1);
    printf("%d", count);
}
