/*You are given four numbers a, b, c, d which form two fractions a/b and c/d. You have to report the integral part of the decimal formed after adding the two fractions and converting the sum into decimal form. If the integral part is smaller than -2, then print "Smaller than -2", else if it is greater than 2, then print "Greater than 2". In all other cases, print the integral part itself.

The integral part of decimal is the largest integer smaller than or equal to the decimal. For example, the integral part of the decimal -5.87 is -6, -1.00 is -1, and 2.37 is 2.

Be careful of extra/missing spaces and extra/missing lines

Use the visible test cases to guide yourself

Do not use any data structure other than int

You are not allowed to use any header file other than stdio.h

Constraints: -1000 <= a, b, c, d <= 1000

Input: Four integers in the order a, b, c, d.

Output: If the integral part of the decimal formed by converting a/b + c/d is less than -2, then print "Smaller than -2". If it is greater than 2, print "Greater than 2". In all other cases, print a number that is the integeral part itself.

Sample Input 1: 1 1 2 2

Sample Output 1: 2

Sample Input 2: -1 2 -3 2

Sample Output 2: -2

Grading Scheme:
Note: Give 0 marks for test-case component if there is any form of hard-coding. Eg: printf("0");*/

// SOLUTION

#include <stdio.h>
int main()
{
    int a, b, c, d, num, den;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    num = ((a * d) + (b * c));
    den = b * d;
    if (num >= (3 * den))
    {
        printf("Greater than 2\n");
    }
    else if ((num >= (2 * den)) && (num < (3 * den)))
    {
        printf("2");
    }
    else if ((num >= (1 * den)) && (num < (2 * den)))
    {
        printf("1");
    }
    else if ((num >= 0) && (num < (1 * den)))
    {
        printf("0");
    }
    else if ((num >= ((-1) * den)) && (num < 0))
    {
        printf("-1");
    }
    else if ((num >= (-2 * den)) && (num < ((-1) * den)))
    {
        printf("-2");
    }
    else if (num < ((-2) * den))
    {
        printf("Smaller than -2");
    }
}
