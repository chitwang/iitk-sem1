/*You are given a series of numbers terminated by -1. Print the sum of product of quadruples formed by taken 4 in sequence.

Example 1

Input:

1 2 3 4 5 6 7 8 9 10 11 12 -1

Output: 13584

Explanation: (1 x 2 x 3 x 4) + (5 x 6 x 7 x 8) + (9 x 10 x 11 x 12) = 13584


Example 2

Input:

1 3 2 4 12 11 9 10 8 7 6 5 -1

Output: 13584*/

// solution:

#include <stdio.h>
int main()
{
    int a, b, c, d, e, f, g, h;
    int ans = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    while ((a != -1) && (b != -1) && (c != -1) && (d != -1))
    {
        ans = ans + (((a * b) * c) * d);
        scanf("%d", &e);
        scanf("%d", &f);
        scanf("%d", &g);
        scanf("%d", &h);
        a = e;
        b = f;
        c = g;
        d = h;
    }
    printf("%d", ans);
}