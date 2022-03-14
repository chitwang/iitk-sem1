/*A Fibonacci Sequence is a sequence such that the current number is sum of previous two numbers in the sequence. Write a program to print the n-th number in the sequence. Take the first Fibonacci number to be 0 and second to be 1.

Input Format

A single integer n

Output Format

A single integer denoting n-th Fibonacci number*/

// solution:

#include <stdio.h>
int main()
{
    int a = 0;
    int b = 1;
    int c;
    int n;
    int d = 3;
    scanf("%d", &n);
    if ((n == 1) || (n == 2))
    {
        printf("%d", n - 1);
    }
    else
    {
        while (d <= n)
        {
            c = a + b;
            a = b;
            b = c;
            d++;
        }
        printf("%d", c);
    }
    return 0;
}
