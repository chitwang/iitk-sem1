/*You are given a series of integers terminated by -1. Print the maximum adjacent absolute difference between two consecutive numbers. You will always be provided with at least two numbers in the sequence.

Example 1

Input : 1 -3 4 9 12 -3 12 33 -2 34 22 41 -1

Output : 36

Explanation : The maximum absolute difference is between -2 and 34


Example 2

Input : 55 23 76 55 22 11 0 32 54 88 -1

Output : 53

Explanation: The max absolute difference is between 23 and 76*/

// solution:

#include <stdio.h>
int main()
{
    int a, b, diff;
    int maxdiff = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    while ((a != -1) && (b != -1))
    {
        if (a > b)
        {
            diff = a - b;
        }
        else
        {
            diff = b - a;
        }
        if (maxdiff < diff)
        {
            maxdiff = diff;
        }
        else
        {
            maxdiff = maxdiff;
        }
        a = b;
        scanf("%d", &b);
    }
    printf("%d", maxdiff);
}
