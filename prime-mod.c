/*You are given a prime p >= 2, and a positive number N < p.

You have to output the smallest non-negative integer k such that
(2 ^ k) mod p is N, if such a k exists. If such a k does not exist, you
have to output -1.

Constraints

2 <= p <= 200

N < p

Input Format

The input consists of two numbers, a prime p >= 2 and a positive number
N < p separated by a single space. (You can assume that p is a prime,
and that 0 < N < p, you do not have to check whether these conditions
are true.)

Output Format

A single integer k*/

// solution:

#include <stdio.h>
int main()
{
    int N;
    int p;
    int z = 1;
    int count = 0;
    int found = 0;
    scanf("%d", &p);
    scanf("%d", &N);
    while ((count < p) && (found == 0))
    {
        if (z == N)
        {
            printf("%d", count);
            found = 1;
        }
        z = (z * 2) % p;
        count++;
    }
    if (found == 0)
    {
        printf("-1");
    }
    return 0;
}
