/*Your friend Arjun is a unique person. He believes only odd numbers are the natural numbers. He counts in the way as '1,3,5,7...'. So if you ask him what number comes after 1, he will say 3.
His teacher ask you two questions,

What is nth natural number according to him?

What is the sum of the first n natural numbers according to him?

Note : Assume you believe in the conventional natural number system.

Input : An integer n.

Output : Two lines containing one integer each, corresponding to answer of first question and second question respectively.

Sample Input 1:
3

Sample Output 1:
5
9

Sample Input 2:
5

Sample Output 2:
9
25*/

// SOLUTION

#include <stdio.h>

int main()
{
    int n, num, sum;
    scanf("%d", &n);
    num = 2 * n - 1;
    sum = n * n;
    printf("%d\n", num);
    printf("%d", sum);
    return 0;
}