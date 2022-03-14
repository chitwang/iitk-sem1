/*We know that factorial of a non-negative number n is defined as n! = 1*2*3....*n, which is the product of all natural numbers till n. As a special case, 0! is defined to be 1. You are given a sequence of non-negative integers terminated with -1. Find the sum of the squares of the sum of digits of factorial of each number. Do not account the terminating -1 as a part of the sequence. For ease of understanding, see the example input.

Input Format

A space separated stream of non-negative integers terminated with a -1.


Output Format

A single integer: sum of squares of sum of digits of factorial of each number in the stream (except the -1).

Sample Input

4 5 1 6 1 -1
Sample Output

128
Explanation

```
4! = 24     Sum of digits = 6
5! = 120    Sum of digits = 3
1! = 1      Sum of digits = 1
6! = 720    Sum of digits = 9
1! = 1      Sum of digits = 1


So, our required answer is 6^2 + 3^2 + 1^2 + 9^2 + 1^2 = 36 + 9 + 1 + 81 + 1 = 128*/

// solution:

#include <stdio.h>

int main()
{
    int e;
    int sqsum = 0;
    int sum = 0;
    int fact = 1;
    scanf("%d", &e);
    while (e != -1)
    {
        for (int i = 1; i <= e; i++)
        {
            fact = fact * i;
        }
        while (fact != 0)
        {
            sum = sum + (fact % 10);
            fact = fact / 10;
        }
        sqsum = sqsum + (sum * sum);
        sum = 0;
        fact = 1;
        scanf("%d", &e);
    }
    printf("%d", sqsum);
    return 0;
}
