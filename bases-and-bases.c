/*Write a program that converts a decimal (base-10) number "A" to a base-B number. Input will be given in the format of two integers separated by a space. Output will be base-B number.

Constraints: 2<=B<=10 and A is a whole number.

INPUT :
A B

OUTPUT :
C

Sample Input 1:
5 2

Sample Output 1:
101


Sample Input 2:
10 6

Sample Output 2:
14*/

// solution:

#include <stdio.h>
int main()
{
    int A;
    int B;
    int rem;
    int m = 0;
    int place_val = 1;
    scanf("%d", &A);
    scanf("%d", &B);
    while (A != 0)
    {
        rem = A % B;
        m = m + rem * place_val;
        A = A / B;
        place_val = place_val * 10;
    }
    printf("%d", m);
}
