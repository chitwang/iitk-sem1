/*Bob has deposited b amount of money in a certain bank. The bank offers r% interest on the amount of money that is at start of the year each year. Bob wants to calculate the bank balance after y years have passed but he cannot figure out and needs your help. Help Bob calculate his bank balance after y years.

Be careful of extra/missing spaces and extra/missing lines

Use the visible test cases to guide yourself

You are not allowed to use any header file other than stdio.h and any built-in functions

Constraints: 0<=b<=100000, 0<=r<=100, 0<=y<=4

Input: Three integers in the order b, r, y.

Output: Print the amount of money rounded upto 5 decimal places after y years assuming Bob does not do any transaction in that time period.

Sample Input 1: 100 2 1

Sample Output 1: 102.00000

Sample Input 2: 100 50 2

Sample Output 2: 225.00000*/

// solution:

#include <stdio.h>

int main()
{
    int b, r, y;
    float p0;
    float m, n;
    scanf("%d%d%d", &b, &r, &y);
    n = (float)(r) / 100;
    m = 1.0 + n;
    p0 = (float)b;
    if (y == 0)
    {
        printf("%0.5f", p0);
    }
    else if (y == 1)
    {
        printf("%0.5f", p0 * m);
    }
    else if (y == 2)
    {
        printf("%0.5f", p0 * m * m);
    }
    else if (y == 3)
    {
        printf("%0.5f", p0 * m * m * m);
    }
    else if (y == 4)
    {
        printf("%0.5f", p0 * m * m * m * m);
    }

    return 0;
}