/*Error Detection mechanism are widely employed in industry to identify the error in data communication. You have to have design a simple error detection mechanism, which uses parity digit. A parity digit is appended to the decimal representation of the number to make the total number of 9's even.
Given an integers A . Your task is identify the parity bit.


Constraint:


The integer A is always positive

Refrain from using floating point variables for storing A.


Input:


The input will consist of a number.


Output:


The program should print:

YES, if the parity digit is required to make the total number of digit 9's even.

NO, if parity digit is not required



The output should be followed by a newline.


Sample TestCase:


TestCase1:

Input
919
Output:
NO

TestCase2:

Input


94
Output:


YES

Explanation:

TEST CASE1: The number of 9's is 919 is even. Parity digit is not required.


TEST CASE2: The number of 9's is 94 is odd. Parity digit is required.*/

// solution:

#include <stdio.h>

int main()
{
    int A;
    int count = 0;
    scanf("%d", &A);
    while (A != 0)
    {
        if (A % 10 == 9)
        {
            count++;
        }
        A = A / 10;
    }
    if (count % 2 == 0)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    return 0;
}
