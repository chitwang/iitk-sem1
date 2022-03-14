/*You are a new intern at a famous multinational company. Your first task given by your manager is as follows.


You are provided with 4 positive integers: three numbers are the same while one is different. You need to find the number that is not equal to the others. Furthermore, you also need to check whether the sum of the three equal numbers (denoted by S) is divisible by 6 and 9.


Input: 4 integers


All the numbers are positive integers and all numbers except one are equal.


Output Format: The output should be across 2 lines. In the first line, print the number that is not equal to the others. In the second line, print "YES BOTH" if S is divisible by 6 and 9, print "YES SIX" if S is divisible by 6 and not by 9, print "YES NINE" if S is divisible by 9 and not by 6, print "NO NONE" if S is divisible by neither 6 nor 9. The quotes are for emphasis.


Example Input
10 6 10 10


Example Output
6
YES SIX*/

// solution:

#include <stdio.h>

int main()
{
    int a;
    int b;
    int c;
    int d;
    int S;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    if ((a != b) && (b == c) && (b == d))
    {
        printf("%d \n", a);
        S = b + c + d;
        if ((S % 6 == 0) && (S % 9 == 0))
        {
            printf("YES BOTH");
        }
        else if ((S % 6 == 0) && (S % 9 != 0))
        {
            printf("YES SIX");
        }
        else if ((S % 6 != 0) && (S % 9 == 0))
        {
            printf("YES NINE");
        }
        else if ((S % 6 != 0) && (S % 9 != 0))
        {
            printf("NO NONE");
        }
    }
    else if ((a != b) && (a == c) && (a == d))
    {
        printf("%d \n", b);
        S = a + c + d;
        if ((S % 6 == 0) && (S % 9 == 0))
        {
            printf("YES BOTH");
        }
        else if ((S % 6 == 0) && (S % 9 != 0))
        {
            printf("YES SIX");
        }
        else if ((S % 6 != 0) && (S % 9 == 0))
        {
            printf("YES NINE");
        }
        else if ((S % 6 != 0) && (S % 9 != 0))
        {
            printf("NO NONE");
        }
    }
    else if ((a == b) && (a == c) && (a != d))
    {
        printf("%d \n", d);
        S = a + c + b;
        if ((S % 6 == 0) && (S % 9 == 0))
        {
            printf("YES BOTH");
        }
        else if ((S % 6 == 0) && (S % 9 != 0))
        {
            printf("YES SIX");
        }
        else if ((S % 6 != 0) && (S % 9 == 0))
        {
            printf("YES NINE");
        }
        else if ((S % 6 != 0) && (S % 9 != 0))
        {
            printf("NO NONE");
        }
    }
    else if ((a == b) && (a != c) && (a == d))
    {
        printf("%d \n", c);
        S = a + b + d;
        if ((S % 6 == 0) && (S % 9 == 0))
        {
            printf("YES BOTH");
        }
        else if ((S % 6 == 0) && (S % 9 != 0))
        {
            printf("YES SIX");
        }
        else if ((S % 6 != 0) && (S % 9 == 0))
        {
            printf("YES NINE");
        }
        else if ((S % 6 != 0) && (S % 9 != 0))
        {
            printf("NO NONE");
        }
    }
    return 0;
}
